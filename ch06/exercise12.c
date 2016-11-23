//Programming Exercise 6.16.12
#include <stdio.h>
int main(void)
{
	double pos, neg, minus;
	int i, j, limit;

	printf("How much is the limit? (<=0 to quit) :\n");
	scanf("%d", &limit);
	while (limit > 0)
	{
		for (i = 1, j = 1, pos = 0.0, neg = 0.0, minus = -1.0; i <= limit; i++, j++)
		{
			pos += 1.0 / i;
			minus *= -1.0;
			neg += 1.0 / (minus * j);
		}
		printf("Pos = %f and Neg = %f after %d times!\n", pos, neg, limit);
		printf("How much is the limit? (<=0 to quit) :\n");
		scanf("%d", &limit);
	}
	printf("Thank you!");

	return 0;
}
