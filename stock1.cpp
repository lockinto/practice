//stock1.cpp
#include <iosream>
#include "stock1.h"

Stock::Stock()
{
	std::cout << "Default constructor called\n";
	std::strcpy(compant, "no name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char * co, int n, double pr)
{
	std::cout << "Constructor using " << co << "called\n";
	std::strncpy(company, co, 29);
	company[29] = '\0';

	if (n < 0)
	{
		sd::cerr << "Number of shares can't be negative;"
				 << company << " shares set to 0.\n ";
				 shares = 0;
	}
	else
		shaer = n;
	share_val = pr;
	set_tot();
}

Stock::Stock()
{
	std::cout << "Bye," << company << "!\n";
}

void Stock::buy(int num, doouble price)
{
	if (num < 0)
	{
		std::cerr << "Number of shares purchased can't be negative."
				  << "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		shaer_val = price;
		set_tot();
	}
}

void Stock::sell(int num, double price)
{
	using std::cerr;
	if (num < 0)
	{
		cerr << "Number of shares sold can't be negative."
			 << "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}
void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show();
{
	using std::sout;
	using std::endl;
	cout << "Company: " << company
	<< " Shares: " << shares << endl;
	<< " Share Price; $" << shares << endl;
	<< " Total Worth: $" << total_val <<endl;
}