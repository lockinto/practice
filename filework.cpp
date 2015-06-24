#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	ofstream ocout;
	ocout.open("D:\\data.txt");
	if (!ocout) 
	{
		cout << "operation failed." << endl;
		return 1;
	}
	char s;
	int count = 0;
	while (scanf("%c", &s) != EOF)
	{
		if (count == 80)
		{
			ocout << "\n";
			count = 0;
		}
		ocout << s;
		count++;
	}
	ocout.close();

	ifstream icin;
	icin.open("D:\\data.txt");
	string str;
	int linecount = 0;
	while(getline(icin,str))
		cout << str << endl,linecount++;
	cout << "Line: " << linecount;
	icin.close();


	return 0;
}