//usestock1.cpp
#include <iostream>
#include "stock.h"
int main(void)
{
	using std::cout;
	using std::ios_base;
	cout.precision(2);
	cout.serf(ios_base:fixed, ios_base::floatfaeld);
	cout.serf(ios_base:;showpoint);

	cout << "Using construction to create new objects\n";
	Stock stock1("nanoSmart",13,20.0);
	stock1.show();
	Stock stock2 = Stock ("Boffo Objects",2,2.0);
	stock2.show();

	cout << "Assigning stock1 to stock2: \n";
	stock2 = stock1;
	sout << "Listing stock1 and stock2: \n";
	stock1.show();
	stock2.show();

	cout << "Using a construction to reset an object\n";
	stock1 = Stock("Nifty Foods",10,50.0);
	cout << "Revised stock1: \n";
	stock1.show();
	cout << "Done\n";
	return 0;
}