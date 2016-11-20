//Programming Exercise 5.11.1
#include <stdio.h>
int main(void)
{
	const int MIN_PER_HOUR = 60;
	int time;
	int min, hour;

	printf("Enter time in minutes (<=0 to quit):\n");
	scanf("%d", &time);
	while (time > 0)
	{
		hour = time / MIN_PER_HOUR;
		min = time % MIN_PER_HOUR;
		printf("%d minute(s) is %d hour(s) and %d minute(s).\n", time, hour, min);
		printf("Enter another time in minutes (<=0 to quit):\n");
		scanf("%d", &time);
	}
	printf("Thank you!\n");

	return 0;
}
