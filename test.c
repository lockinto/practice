#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr;
	int i = 0;
	ptr = (int *)malloc(10 * sizeof(int));
	for (i = 0; i < 10; i++)
		printf("%ld  ",&ptr[i]);
	return 0;
}