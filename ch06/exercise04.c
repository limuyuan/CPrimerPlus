//Programming Exercise 6.16.4
#include <stdio.h>
int main(void)
{
	int i, j;
	char a = 'A';

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j <= i; j++)
			printf("%c", a++);
		printf("\n");
	}
	return 0;
}