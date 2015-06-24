int f(int x)
{
	return x+2;
}

int g(int x)
{
	return f(x);
}

int main(void)
{
	int s=g(8);
	return 0;
}