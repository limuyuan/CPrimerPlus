//Programming Exercise 5.11.2
#include <stdio.h>
int main(void)
{
	int number, max;

	printf("Please enter a integer:\n");
	scanf("%d", &number);
	max = number + 10;
	number--;
	while (number++ < max)
		printf("%d ", number);

	return 0;
}
