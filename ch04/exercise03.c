//Programming Exercise 4.8.3
#include <stdio.h>
int main()
{
	float number;

	printf("Please input your number:\n");
	scanf("%f", &number);

	printf("a. The input is %.1f or %.1e.\n", number, number);
	printf("b. The input is %+.3f or %.3E.\n", number, number);

	return 0;
}
