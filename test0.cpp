#include <iostream>
#include <typeinfo>
using namespace std;

class test
{
public:
	test() {}
};

class aftertest : public test
{
public:
	aftertest() {}
};

int main(void)
{
	test * ptr;
	ptr = new test();
	cout << typeid(*ptr).name() << endl;
	ptr = new aftertest();
	cout << typeid(*(new aftertest())).name() << endl;
	return 0;
}
