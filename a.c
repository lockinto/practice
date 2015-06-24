#include <stdio.h>
int main(void)
{
	int  m = 0, s = 0, num = 0, els = 1, space = 0;
	char ch;
	while (scanf("%c", &ch) == 1)
	{
		if (ch >= 'A'&& ch <= 'Z')
		{
			m += 1; continue;
		}
		if (ch >= 'a'&& ch <= 'z')
		{
			s += 1; continue;
		}
		if (ch >= '0'&& ch <= '9')
		{
			num += 1; continue;
		}
		if (ch == ' ')
		{
			space += 1; continue;
		}
		els += 1;
	}
	printf("big%d\n", m);
	printf("small%d\n", s);
	printf("space%d\n", space);
	printf("number%d\n", num);
	printf("else%d\n", els);
	return 0;
}
