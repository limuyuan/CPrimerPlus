//Programming Exercise 6.16.10
#include <stdio.h>
int main(void)
{
	int lower, upper;
	int sum, i;

	printf("Enter lower and upper integer limits:");
	scanf("%d %d", &lower, &upper);

	while (upper > lower)
	{
		for (i = lower, sum = 0; i <= upper; i++)
			sum += i * i;
		printf("The sums of the squares from %d to %d is %d\n", lower * lower, upper * upper, sum);
		printf("Enter next lower and upper integer limits:");
		scanf("%d %d", &lower, &upper);
	}
	printf("Done\n");

	return 0;
}
