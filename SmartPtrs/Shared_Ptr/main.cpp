#include "shared.hpp"

class Base 
{
	public:
	Base();
	std::string name;
	void set(std::string n) { name = n; }
	Base(std::string n) : name(n) {};
	void print() { std::cout << name << "\n"; }
};

int main() {

	 //SharedPtr<int> a(new int{2});

	 //SharedPtr<int> b(new int{5});

	SharedPtr<int> a(new int(2));
	SharedPtr<int> b(new int(5));


	 std::cout << "A adress -> " << a.get() << std::endl;
	 std::cout << "B adress -> " << b.get() << std::endl;

	 SharedPtr<int> c = a;

	 SharedPtr<int> d = b;

	 //b.swap(a);

	 std::cout << "A adress -> " << a.get() << std::endl;
	 std::cout << "B adress -> " << b.get() << std::endl;

	 std::cout << "\n";
	 std::cout << a.get() << std::endl;

	 std::cout << a.user_count() << std::endl;
	 std::cout << "\n";

	 std::cout << b.get() << std::endl;

	 std::cout << b.user_count() << std::endl;
	 std::cout << "\n";

	 std::cout << c.get() << std::endl;

	 std::cout << c.user_count() << std::endl;
	 std::cout << "\n";

	 std::cout << d.get() << std::endl;

	 std::cout << d.user_count() << std::endl;
	 std::cout << "\n";

	 SharedPtr<Base> value(new Base("Hello World!"));

	 std::cout << value->name << std::endl;
	 std::cout << value.get() << "\n";
	 std::cout << value.user_count() << "\n\n";
	 value.reset(new Base("Reset"));
	 std::cout << value->name << std::endl;
	 std::cout << value.get() << "\n";
	 std::cout << value.user_count() << "\n\n";
	 std::cout << "ahah\n";


	 std::cout << "\n OWNER \n\n";
	 std::cout << a.owner_before(c) << std::endl;
	 std::cout << a.owner_before(a) << std::endl;
	 std::cout << c.owner_before(a) << std::endl;


	 std::cout << "\n";
	 std::cout << "\n";
	 std::cout << "\n";

	  //std::shared_ptr<Base> sptr = std::make_shared<Base>("te");

	  //sptr->print();
	  //std::cout << sptr.get() << "\n";
	  //sptr.reset(new Base("pa"));
	  //sptr->print();
	  //std::cout << sptr.get() << "\n";


	 //std::cout << "\n";
	 //std::cout << "\n";
	 //std::cout << "\n";
	 //std::cout << "\n";
	 //std::cout << "\n";
	 //std::cout << "\n";

	  //std::shared_ptr<Base> x = std::make_shared<Base>("te");
	  //std::shared_ptr<Base> y = std::make_shared<Base>("te");
	  //std::shared_ptr<Base> z = std::make_shared<Base>("te");

	  //std::cout << "here\n";
	  //std::cout << x.owner_before(x) << "\n";
	  //std::cout << "here\n";
	  //std::cout << x.owner_before(y) << "\n";
	  //std::cout << "here\n";
	  //std::cout  << x.owner_before(z) << "\n";
	  //std::cout << "here\n";
	  //std::cout  << y.owner_before(x) << "\n";
	  //std::cout << "here\n";



}
