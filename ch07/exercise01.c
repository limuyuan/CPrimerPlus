//Programming Exercise 7.12.1
#include <stdio.h>
int main(void)
{
	char c;
	int spaces, lines, other;
	spaces = lines = other = 0;

	printf("Please enter something (ends with #)\n");
	while ((c = getchar()) != '#')
	{
		if (' ' == c)
			spaces++;
		else if ('\n' == c)
			lines++;
		else
			other++;
	}
	printf("Space: %d\nLine:%d\nOther:%d\n", spaces, lines, other);
	return 0;
}