#include <iostream>
#include "mystack.h"
using namespace std;

int main(void)
{
	Stack<double> stdouble;
	Stack<int> stint;
	Stack<char> stchar;
	for(int i = 0; i < 10; i++)
	{
		stdouble.push(i + 9.9);
		stint.push(i);
		stchar.push(i + 65);
	}

	double x1;
	int x2;
	char x3;
	for (int i = 0; i < 10; i++)
	{
		stdouble.pop(x1);
		stint.pop(x2);
		stchar.pop(x3);
		cout << x1 << " " << x2 << " " << x3 << " " << endl;
	}

	return 0;
}