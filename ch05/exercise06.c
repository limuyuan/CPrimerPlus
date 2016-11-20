//Programming Exercise 5.11.6
#include <stdio.h>
int main(void)
{
	int count, money, days;
	count = 0;
	money = 0;

	printf("How many days would you like to earn money?\n");
	scanf("%d", &days);
	while (count++ < days)
		money = money + count * count;
	printf("You've earned $%d.00 in %d days!\n", money, days);
	return 0;
}
