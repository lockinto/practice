#ifndef MYSTACK_H_
#define MYSTACK_H_

template <class type>
class Stack
{
private:
	enum {MAX = 10};
	type items[MAX];
	int top;
public:
	Stack();
	bool isempty();
	bool isfull();
	bool push(const type & item);
	bool pop(type & item);
};

template <class type>
Stack<type>::Stack()
{
	top = 0;
}

template <class type>
bool Stack<type>::isempty()
{
	return top == 0;
}

template <class type>
bool Stack<type>::isfull()
{
	return top == MAX;
}

template <class type>
bool Stack<type>::push(const type & item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <class type>
bool Stack<type>::pop(type & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

#endif

