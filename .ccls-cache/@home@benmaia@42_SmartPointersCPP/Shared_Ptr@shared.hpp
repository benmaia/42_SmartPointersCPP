#ifndef SHARED_HPP
# define SHARED_HPP

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <vector>
#include "nullptr.hpp"

template <class T> struct sharedBlock
{
	T* ptr;
	size_t sharedCounter;
	size_t weakCounter;
};

template <class T> class SharedPtr
{
	sharedBlock<T>* block;
	void copy(const SharedPtr& other)
	{
		this->block = other.block;
		if (block)
			block->sharedCounter++;
	}
	void clean()
	{
		if (block)
		{
			if (!--block->sharedCounter)
			{
				if (block->ptr)
					delete block->ptr;
				block->ptr = NULL;
			}
			if (!block->weakCounter && !block->ptr)
			{
				delete block;
				block = NULL;
			}
		}
	}

	public:
		SharedPtr(T* pointer)
		{
			block = new sharedBlock<T>;
			if (block->ptr != pointer)
			{
				block->ptr = pointer;
				block->sharedCounter = 1;
				block->weakCounter = 0;
			}
			else
				block = NULL;
		}

		~SharedPtr() { clean(); };

		SharedPtr(const SharedPtr& other) { copy(other); }

		SharedPtr& operator=(nullptr_t) { clean(); }

		SharedPtr& operator=(const SharedPtr& other)
		{
			if (!other)
				clean();
			else
			{
				clean();
				copy(other);
				return *this;
			}
		}

		T&	operator*() { return *get(); };
		T*	operator->() { return get(); }

		const T&	operator*() const {return *get(); }
		const T*	operator->() const { return get(); }

		size_t user_count() const { return block? block->sharedCounter : 0; }

		const T*	get() const { return block? block->ptr : NULL; }

		T*	get() { return block? block->ptr : NULL; }

		void	swap(SharedPtr& other)
		{
			sharedBlock<T>* block = other.block;
			other.block = this->block;
			this->block = block;
		}

		void	reset() { clean(); }

		void	reset(T* ptr)
		{
			clean();
			block = new sharedBlock<T>;
			block->ptr = ptr;
			block->sharedCounter = 1;
			block->weakCounter = 0;
		}

		bool	owner_before(const SharedPtr& other) const { return this < &other; }
};

#endif
