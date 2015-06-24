#include <iostream>
#include <iomanip>
using namespace std;

class complex_number
{
private:
	double real_component;
	double imaginary_component; 
public:
	complex_number(double real = 0, double imaginary = 0) 
	: real_component(real), imaginary_component(imaginary) {}
	friend complex_number operator+ (complex_number & op1, complex_number & op2);
	friend complex_number operator- (complex_number & op1, complex_number & op2);
	friend ostream & operator<< (ostream & os, complex_number & complex);
};

int main(void)
{
	complex_number a(1,1);
	complex_number b(2,3);
	cout << a << b;
	complex_number c = a + b;
	complex_number d = b - a;
	cout << c << d;
	return 0;
}

complex_number operator+ (complex_number & op1, complex_number & op2)
{
	complex_number result(0,0);
	result.real_component = op1.real_component + op2.real_component;
	result.imaginary_component = op1.imaginary_component + op2.imaginary_component;
	return result;
}

complex_number operator- (complex_number & op1, complex_number & op2)
{
	complex_number result(0,0);
	result.real_component = op1.real_component - op2.real_component;
	result.imaginary_component = op1.imaginary_component - op2.imaginary_component;
	return result;
}

ostream & operator<< (ostream & os, complex_number & complex)
{
	os << setiosflags(ios::fixed) << setprecision(2) << complex.real_component;
	os << "+" << complex.imaginary_component << "i" <<endl;
	return os;
}