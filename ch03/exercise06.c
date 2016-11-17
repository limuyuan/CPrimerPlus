#include <stdio.h>
int main(void)
{
	float quart;

	printf("Input quarts of water:");
	scanf("%f", &quart);
	printf("The number of water molucules is about %e.",quart / 3 * 1.0e23);
	return 0;
}
