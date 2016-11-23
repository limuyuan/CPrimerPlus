//Programming Exercise 6.16.14
#include <stdio.h>
int main(void)
{
	double num1[8], num2[8] = {0};
	int i;

	printf("Please enter 8 values:\n");
	scanf("%lf", &num1[0]);
	num2[0] = num1[0];
	for (i = 1; i < 8; i++)
	{
		scanf("%lf", &num1[i]);
		num2[i] = num2[i - 1] + num1[i];
	}

	for (i = 0; i < 8; i++)
		printf("%6.3f ", num1[i]);

	printf("\n");

	for (i = 0; i < 8; i++)
		printf("%6.3f ", num2[i]);
	return 0;
}
