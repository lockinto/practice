#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

class worker
{
protected:
	string name;
	int work_day;
	int leave_hour;
	int over_work_hour;
public:
	worker();
	virtual double salary();
	friend ostream & operator<< (ostream & os, worker & wo);
};

class normal : public worker
{
public:
	normal(string na, int wo, int lea, int over)
	: name(na), work_day(wo), leave_hour(lea), over_work_hour(over) {}
	double salary();
	friend ostream & operator<< (ostream & os, normal & nor);
};

class technical : public worker
{
public:
	technical(string na, int wo, int lea, int over)
	: name(na), work_day(wo), leave_hour(lea), over_work_hour(over) {}
	double salary();
	friend ostream & operator<< (ostream & os, technical & tech);
};

class manager : public worker
{
public:
	manager(string na, int wo, int lea, int over)
	: name(na), work_day(wo), leave_hour(lea), over_work_hour(over) {}
	double salary();
	friend ostream & operator<< (ostream & os, manager & mana);
};

int main(void)
{
	worker * p[9] = {
		new normal("xiaowang",20,0,20),
		new normal("xiaoli",24,0,30),
		new technical("laozhang",30,0,40),
		new technical("daliu",30,80,0),
		new normal("alan",30,0,50),
		new manager("zhaozhong",30,10,2),
		new manager("lizhong",30,20,10),
		new normal("dak",1,0,0),
		new technical("Cluo",30,5,8)
	};
	for (int i = 0; i < 9; i++)
		cout << *p[i];
	return 0;
}

ostream & operator<< (ostream & os, worker & wo)
{
	os << "Name: " << wo.name <<endl;
	os << "Work Day: " << wo.work_day << endl;
	os << "Leave Hours: " << wo.leave_hour << endl;
	os << "Over Work Hours: " << wo.over_work_hour << endl;
	os << endl;
	return os;
}

ostream & operator<< (ostream & os, normal & nor)
{
	os << "Normal Worker" << endl;
	os << (worker &)nor;
	return os;
}

ostream & operator<< (ostream & os, technical & tech)
{
	os << "Technical Worker" << endl;
	os << (worker &)tech;
	return os;
}


ostream & operator<< (ostream & os, manager & mana)
{
	os << "Manager" << endl;
	os << (worker &)mana;
	return os;
}

double normal::salary()
{
	double result;
	result = work_day * 8 * 15 + over_work_hour * 18;
	return (result > 0 ? result : 0);
}

double technical::salary()
{
	double result;
	result = 5000 + over_work_hour * 25 - leave_hour * 40;
	return (result > 0 ? result : 0);
}

double manager::salary()
{
	double result;
	result = 6000 + over_work_hour * 30 - leave_hour * 60;
	return (result > 0 ? result : 0);
}


/*
某工厂对不同职位的工人的计算工资方式不同，
普工的工资=工时*15+加班工时*18
技工的工资=固定工资5000+加班工时*25-请假*40
车间主任工资=固定工资6000+加班工时*30-请假*60
正常情况下每天工作八小时，每月30天，超过的时间算作加班，上班时间没到算作请假，普工则是干得多，挣的多。
使用工人worker作为抽象基类，定义纯虚函数int salary( )，普工normal，技工technical，
车间主任manager均继承worker，并在每个类中实现salary，可以使用单向链表或者指针数组来实现下表本月所有工人工资的计算。
*/