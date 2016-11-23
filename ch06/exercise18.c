//Programming Exercise 6.16.18
#include <stdio.h>
#define DUNBAR 150
int main(void)
{
	int friends, n;

	n = 0;
	friends = 5;
	printf("Week%2d, Prof.Rabnud has %d friends.\n", n, friends);

	while (friends <= DUNBAR)
	{
		n++;
		friends = 2 * (friends - n);
		printf("Week%2d, Prof.Rabnud has %d friends.\n", n, friends);
	}
	printf("Prof.Rabnud has a number of friends more than Dunbar's number (%d in this program) in week %d!\n", DUNBAR, n);

	return 0;
}