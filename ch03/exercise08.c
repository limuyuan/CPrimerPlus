//Programming Exercise 3.11.8
#include <stdio.h>
int main(void)
{
	float cups;
	float pints;
	float ounces;
	float tablespoons;
	float teaspoons;

	printf("Input your volme in cups:");
	scanf("%f", &cups);
	pints = cups * 2;
	ounces = cups / 8;
	tablespoons = ounces / 2;
	teaspoons = tablespoons / 3;
	printf("  %f cups\n= %f pints\n= %f ounces\n= %f tablespoons\n= %f teaspoons.\n", cups, pints, ounces, tablespoons, teaspoons);

	return 0;
}
