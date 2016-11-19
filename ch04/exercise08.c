//Programming Exercise 4.8.8
#include <stdio.h>
#define GL_TO_L 3.785	//1 gallon is about 3.785 liters
int main(void)
{
	const float M_TO_KM = 1.609;	//1 miles is about 1.609 kilometres
	float miles, gallons;

	printf("Please enter the number of miles traveled:\n");
	scanf("%f", &miles);
	printf("Please enter the number of gallons of gasoline:\n");
	scanf("%f", &gallons);
	printf("the miles-per-gallon value of your car is %.1f\n", miles / gallons);

	printf("and the liters-per-100-km value of your car is %.1f\n",
		(gallons * GL_TO_L) / (miles * M_TO_KM / 100));

	return 0;
}
