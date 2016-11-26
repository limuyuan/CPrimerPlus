//Programming Exercise 7.12.2
#include <stdio.h>
#define NUMBER 8
int main(void)
{
	char c;
	int i = 0;

	printf("Please enter something (ends with #)\n");
	while ((c = getchar()) != '#')
	{
		i++;
		printf("%2c-%3d", c, c);
		if (i % NUMBER == 0)
			putchar('\n');
	}
	return 0;
}