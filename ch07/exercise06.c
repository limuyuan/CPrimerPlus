//Programming Exercise 7.12.6
#include <stdio.h>
int main(void)
{
	char c, prev;
	int ei = 0;

	prev = 0;

	printf("Please enter something ends with '#'\n");
	while ((c = getchar()) != '#')
	{
		if ('e' == prev && 'i' == c)
			ei++;
		prev = c;
		putchar(c);
	}
	printf("\nThe sequence \"ei\" occurs %d times.\n", ei);
	return 0;
}