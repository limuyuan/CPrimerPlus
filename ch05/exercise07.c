//Programming Exercise 5.11.7
#include <stdio.h>
void cube(double n);
int main(void)
{
	double i;
	printf("Please enter the number to be cubed:\n");
	scanf("%lf", &i);
	cube(i);

	return 0;
}
void cube(double n)
{
	double sol;
	sol = n * n * n;
	printf("The solution is: %g\n", sol);
}
