//Programming Exercise 5.11.9
#include <stdio.h>
void Temperatures(const double fahr);
int main(void)
{
	double f;

	printf("Please enter a temperature in Fahrenheit:\n");
	while(scanf("%lf", &f) == 1)
	{
		Temperatures(f);
		printf("Please enter a temperature in Fahrenheit (q or non-num to quit):\n");
		//scanf("%lf", &f);
	}

	return 0;
}
void Temperatures(const double fahr)
{
	double c, k;
	c = 5.0 / 9.0 * (fahr - 32.0);
	k = c + 273.16;
	printf("Fahrenheit Temperature = %.2f ℉\n", fahr);
	printf("Celsius Temperature = %.2f ℃\n", c);
	printf("Kelvin Temperature = %.2f K\n", k);
}
