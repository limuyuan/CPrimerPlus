//Programming Exercise 3.11.4
#include <stdio.h>
int main(void)
{
	float num;
	//double num;

	printf("Enter a floating-point value:");
	scanf("%f", &num);
	//scanf("%lf", &num);
	printf("fixed-point notation: %f\n", num);
	printf("exponential notation: %e\n", num);
	printf("p notation: %a\n", num);

	return 0;
}
