#include <stdio.h>
int main(void)
{
	float height;

	printf("Input your height (cm):");
	scanf("%f", &height);
	printf("Your height in inches is %f!\n", height / 2.54);

	return 0;
}
