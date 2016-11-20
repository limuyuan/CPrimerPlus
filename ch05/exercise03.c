//Programming Exercise 5.11.3
#include <stdio.h>
int main(void)
{
	int days, weeks, left;

	printf("Please enter the number of days (<= 0 to quit):\n");
	scanf("%d", &days);
	while (days > 0)
	{
		weeks = days / 7;
		left = days % 7;
		printf("%d days are %d weeks, %d days.\n", days, weeks, left);
		printf("Please enter another number of days (<= 0 to quit):\n");
		scanf("%d", &days);
	}
	printf("Thank you!\n");

	return 0;
}
