#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(void)
{
	ofstream ofile;
	ofile.open("c:\\data.txt");
	char ch;
	int word_count = 0;
	while(scanf("%c",&ch) != EOF)
	{
		if (word_count == 80)
		{
			word_count = 0;
			ofile << '\n';
		}
		ofile << ch;
		word_count++;
	}
	ofile.close();

	ifstream ifile;
	ifile.open("c:\\data.txt");
	string str;
	int line_count = 0;
	while(getline(cin,str))
	{
		line_count++;
		cout << str << endl;
	}
	cout << "Line: " << line_count << endl;
	ifile.close();

	return 0;

}