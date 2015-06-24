#include <iostream>
#include <string>
#include <map>
using namespace std;

class airplanelist
{
public:
	airplanelist();
	void show_all ();
	void show_target ();
	void add();
	int del (string);
	int remove_old (int);
private:
	struct airplane
	{
	string code;
	string pilot;
	int content;
	int height;
	string target;
	int year;
	struct airplane * next;
	airplane () : next(NULL){};
	};
	airplane *head,*tail;
	int currentlength;
};

int main(void)
{
	airplanelist plane = new airplanelist;
	int select;
	do
		cout << "1:show all the airplane.\n"
			 << "2:show the number of target perspectively.\n"
			 << "3.add a new plane.\n"
			 << "4.delete the plane of the code you enter.\n"
			 << "5.delet the plane whose year over the number you enter.\n"
			 << "6.qiut.";
		cin >> select;
		switch (select)
		{
			case 1:{ plane.show(); break; }
			case 2:{ plane.show_target(); break; }
			case 3:{ plane.add(); break; }
			case 4:{
				    	string s;
				    	cout << "please enter the code.";
				    	cin >> s;
				    	if (plane.del(s)==0) cout << "fail.";
				    	if (plane.del(s)==1) cout << "success.";
				    	break;
				   }
			case 5:{
						int x;
				    	cout << "please enter the year.";
				    	cin >> x;
				    	if (plane.remove_old(x)==0) cout << "fail.";
				    	if (plane.remove_old(x)==1) cout << "success."; 
				    	break;
				   }
			case 6:break;
		}
	while(select!=6)
	
}

airplanelist::airplanelist()
{
	head = new airplane;
	tail = new airplane;
	head->next = tail;
	currentlength = 0;
}

airplanelist::show_all()
{
	if (currentlength == 0)
		cout << "The airplanelist is empty.";
	cout << "code | pilot | content | height | target | year" << endl;
	airplane * p = head->next;
	while (p != tail)
	{
		cout << p.code << p.pilot << p.content << p.height << p.target << p.year << endl;
		p = p->next;
	}
}
void airplanelist::show_target()
{
	map <string> <int> :: iterator it;
	map <string> <int> count;
	airplane p = head->next;
	if (p == tail)
		cout << "The airplanelist is empty.";
	else
		map[p->target]++;
	for (it=count.begin();it!=count.end();it++)
		cout << it->first() << ":" << it->sencond() << endl;

}

void airplanelist::add()
{
	airplane * t = new airplane;
	cout << "code:";
	cin >> t->code;
	cout << "pilot:";
	cin << t->pilot;
	cout << "content:";
	cin >> t->content;
	cout << "height:";
	cin >> t->height;
	cout << "target:";
	cin >> t->target;
	cout <<"year:";
	cin >> t->year;
	airplane * p = head;
	airplane * q = head->next;
	while (q!=tail)
	{
		p = p->next;
		q = q->next;
	}
	p->next = t;
	t->next = q;
	currentlength++;
}

int airplanelist::del(string co)
{
	airplane * p = head;
	airplane * q = head->next;
	if (q == tail) return 0;
	while (q!=tail)
	{
		if (q->code == co)
		{
			p = q->next->next;
			airplane * tmp = q;
			q = q->next;
			delete  tmp;
			currentlength--;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
	return 1;
} 

int airplanelist::remove_old(int ye)
{
	airplane * p = head;
	airplane * q = head->next;
	if (q == tail) return 0;
	while (q!=tail)
	{
		if (q->year >= ye)
		{
			p = q->next->next;
			airplane * tmp = q;
			q = q->next;
			delete  tmp;
			currentlength--;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
	return 1;
}
