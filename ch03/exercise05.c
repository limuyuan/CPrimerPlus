#include <stdio.h>
int main(void)
{
	int age;
	double seconds;

	printf("Input your age:");
	scanf("%d", &age);
	seconds = age * 3.156e7;
	printf("You have past about %e seconds in your life!\n", seconds);

	return 0;
}
