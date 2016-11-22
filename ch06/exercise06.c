//Programming Exercise 6.16.6
#include <stdio.h>
int main(void)
{
	int n;
	int lower, upper;

	printf("Please enter the lower limit for the table (integer):\n");
	scanf("%d", &lower);
	printf("Please enter the upper limit for the table (integer):\n");
	scanf("%d", &upper);
	
	printf("    n|  n^2|  n^3\n");
	printf("-----|-----|-----\n");
	for (n = lower; n <= upper; n++)
	{
		printf("%5d|%5d|%5d\n", n, n*n, n*n*n);
	}

	return 0;
}