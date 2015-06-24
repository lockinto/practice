//文件的输入 和 输出
//C++在头文件中定义了fstream类 包括ifstream ofstream


//file.cpp
#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
	using namespace std;
	string filename;

	cout << "Enter name for new file: ";
	cin >> filename;

	ofstream fout (filename.c_str());

	fout << "hello,world";
	fout.close();

}