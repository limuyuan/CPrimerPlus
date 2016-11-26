//Programming Exercise 7.12.5
#include <stdio.h>
int main(void)
{
	char c;
	int n = 0;	//change times

	printf("Please enter something ends with '#'\n");
	while ((c = getchar()) != '#')
	{
		switch (c)
		{
		case '.':
			putchar('!');
			n++;
			break;
		case '!':
			putchar('!');
			putchar('!');
			n++;
			break;
		default:
			putchar(c);
		}
	}
	putchar('\n');
	printf("You've made %d substitutions!\n", n);
}