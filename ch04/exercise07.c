//Programming Exercise 4.8.7
#include <stdio.h>
#include <float.h>
int main()
{
	double a = 1.0 / 3.0;
	float b = 1.0 / 3.0;

	printf("FLT_DIG = %d, DBL_DIG = %d.\n", FLT_DIG, DBL_DIG);
	printf("double = %.6f, float = %.6f\n", a, b);
	printf("double = %.12f, float = %.12f\n", a, b);
	printf("double = %.18f, float = %.18f\n", a, b);	//origin question is 16 digits here

	return 0;
}
