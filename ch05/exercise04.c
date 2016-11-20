//Programming Exercise 5.11.4
#include <stdio.h>
#define INCHES_TO_CM 2.54
#define FEET_TO_INCHES 12
int main(void)
{
	float cm, height, feet, inches;

	printf("Enter a height in centimetres: ");
	scanf("%f", &cm);

	while (cm > 0)
	{
		height = cm / INCHES_TO_CM;
		feet = height / FEET_TO_INCHES;
		inches = (feet - (int)feet) * FEET_TO_INCHES;
		printf("%.1f cm = %d feet, %.1f inches\n", cm, (int)feet, inches);

		printf("Enter a height in centimeters (<=0 to quit):");
		scanf("%f", &cm);
	}
	printf("bye\n");

	return 0;
}
