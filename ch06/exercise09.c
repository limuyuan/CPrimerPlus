//Programming Exercise 6.16.9
#include <stdio.h>
double func(double a, double b);
int main(void)
{
	double first, second;
	
	printf("Enter your first float number (q to exit):\n");
	while (scanf("%lf", &first) == 1)
	{
		printf("Enter your second float number (q to exit):\n");
		while (scanf("%lf", &second) == 1)
		{
			printf("The result is %f\n", func(first, second));
			break;	//这里实在没有想到除了使用break语句之外的方法，但是到目前为止并没有讲到break语句
		}
		printf("Enter your first float number (q to exit):\n");
	}
	printf("Thank you!\n");

	return 0;
}
double func(double a, double b)
{
	double sol;
	sol = (a - b) / (a * b);
	return sol;
}