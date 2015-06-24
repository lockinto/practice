#include <iostream>
using namespace std;

template <class Any>
void swap (Any &a, Any &b);

int main(void)
{
    int x0,x1;
    double x2,x3;

    cin>>x0>>x1;
    swap(x0,x1);
    cout<<x0<<x1<<endl;

    cin>>x2>>x3;
    swap(x2,x3);
    cout<<x2<<x3<<endl;

    return 0;
}

template <class Any>
void swap(Any &a,Any &b)
{
    Any temp;
    temp=a;
    a=b;
    b=temp;
}