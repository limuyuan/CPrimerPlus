//Programming Exercise 4.8.4
#include <stdio.h>
int main()
{
	float inches;
	char name[40];

	printf("Please input your height(inches):\n");
	scanf("%f", &inches);
	printf("and what's your first name?\n");
	scanf("%s", name);

	printf("%s, you are %.3f feet tall\n", name, inches / 12); //12 inches = 1 foot

	return 0;
}
