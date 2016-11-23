//Programming Exercise 6.16.13
#include <stdio.h>
int main(void)
{
	int num[8];
	int i,power;

	for (i = 0, power = 1; i < 8; i++)
	{
		power *= 2;
		num[i] = power;
	}
	i = 0;
	do
	{
		printf("%d ", num[i]);
		i++;
	} while (i < 8);

	return 0;
}
