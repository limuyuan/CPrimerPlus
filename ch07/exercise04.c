//Programming Exercise 7.12.4
#include <stdio.h>
int main(void)
{
	char c;
	int n = 0;	//change times

	printf("Please enter something ends with '#'\n");
	while ((c = getchar()) != '#')
	{
		if ('.' == c)
		{
			putchar('!');
			n++;
		}
		else if ('!' == c)
		{
			putchar('!');
			putchar('!');
			n++;
		}
		else
			putchar(c);
	}
	putchar('\n');
	printf("You've made %d substitutions!\n", n);
}