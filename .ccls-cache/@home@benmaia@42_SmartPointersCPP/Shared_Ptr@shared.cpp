#include "shared.hpp"

template <class T>
SharedPtr<T>::SharedPtr(T* pointer)
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

template <class T>
SharedPtr<T>::~SharedPtr() { clean(); };


template <class T>
SharedPtr<T>::SharedPtr(const SharedPtr& other) { copy(); };

template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& other)
{
	if (!other)
		clean();
	else
	{
		clean();
		copy(other);
		return *this;
	}
};

template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(nullptr_t) { clean(); };
