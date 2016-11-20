//Programming Exercise 5.11.5
#include <stdio.h>
int main(void)
{
	int count, sum, days;
	count = 0;
	sum = 0;

	printf("How many days would you like to earn money?\n");
	scanf("%d", &days);
	while (count++ < days)
		sum = sum + count;
	printf("You've earned $%d.00 in %d days!\n", sum, days);
	return 0;
}
