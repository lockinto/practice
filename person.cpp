#include <iostream>
#include <string>
#define male 0
#define female 1
using namespace std;

int males = 0;
int females = 0;


class person
{
private:
	string name;
	int sex;
	int age;
public:
	person() {}
	person(string na, int se, int ag)
	: name(na), sex(se), age(ag) 
	{
		se==0 ? males++ : females++;
	}
	~person() { sex==0 ? males-- : females--; }
	static void show_sex(void)
	{
		cout << "Male Number: " << males << endl;
		cout << "Females Number: " << females << endl;
	}
	friend ostream & operator<< (ostream & os, person & per);
};

class teacher : public person
{
private:
	string id;
	double salary;
public:
	teacher() {}
	teacher(string na, int se, int ag, string i, double sal)
	: person(na, se, ag), id(i), salary(sal) {}
	friend ostream & operator<< (ostream & os, teacher & teac);
};

class student : public person
{
private:
	string id;
	int class_number;
public:
	student() {}
	student(string na, int se, int ag, string i, int class_num)
	: person(na,se,ag), id(i), class_number(class_num) {}
	friend ostream & operator<< (ostream & os, student & stu);
};

int main(void)
{
	person * per[5];
	per[0] = new student("Herry", male, 22, "201150269", 1);
	per[1] = new student("Bob", male, 21, "201230652",3);
	per[2] = new student("Anmy", female, 22, "201159874", 2);
	per[3] = new teacher("John", male, 45, "01023654", 4000.0);
	per[4] = new teacher("Dean",female, 35, "01025896", 35000.0);
	for(int i = 0; i < 5; i++)
		cout << *per[i] << endl;
	person::show_sex();
	for (int i = 0; i < 5; i++)
		delete per[i];
	return 0;
}

ostream & operator<< (ostream & os, person & per)
{
	os << "Name: " << per.name << endl;
	os << "Sex: " << (per.sex==0 ? "M\n" : "F\n");
	os << "Age: " << per.age << endl;
	return os;
}

ostream & operator<< (ostream & os, teacher & teac)
{
	os << (person &) teac << endl;
	os << "ID: " << teac.id << endl;
	os << "Salary: " << teac.salary  << endl;
	return os;
}

ostream & operator<< (ostream & os, student & stu)
{
	os << (person &) stu << endl;
	os << "ID: " << stu.id << endl;
	os << "Class Number: " << stu.class_number << endl;
	return os;
}




