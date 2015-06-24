#include <iostream>
using namespace std;

class Point 
{
private:
	double m_x,m_y;
public:
	Point(double x = 0, double y = 0) : m_x(x),m_y(y) {}
	double getX() { return m_x; }
	double getY() { return m_y; }
	void print();
};

class Line 
{
private:
	double m_a,m_b;
public:
	Line(double a, double b) : m_a(a),m_b(b) {}
	double getA() { return m_a; }
	double getB() { return m_b; }
	void print();
	friend Point setpoint(Line & m, Line & n);
};

int main(void)
{
	double a1,b1,a2,b2;
	cout << "please enter a1,b1,a2,b2\n";
	cin >> a1 >> b1 >> a2 >> b2;
	Line l1 = Line(a1,b1);
	l1.print();
	Line l2 = Line(a2,b2);
	l2.print();
	Point result = setpoint(l1,l2);
	result.print();
	return 0;
}

void Point::print()
{
	cout << "(" << m_x << "," << m_y << ")" << endl;
}

void Line::print()
{
	cout << "y=" << m_a << "x+" << m_b << endl;
}

Point setpoint(Line & m, Line & n)
{
	double x = (n.getB()-m.getB())/(m.getA()-n.getA());
	double y = m.getA()*x+m.getB();
	return (Point(x,y));
}