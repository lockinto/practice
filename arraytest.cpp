#include <stdio.h>

int main(void)
{
	int a[2][3];
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 3; j++)
			a[i][j] = 0;

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
			printf("%d ",&a[i][j]);
		printf("\n");
	}
	return 0;
}
