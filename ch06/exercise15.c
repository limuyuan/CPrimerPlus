//Programming Exercise 6.16.15
#include <stdio.h>
int main(void)
{
	char line[255];
	int count, i;

	printf("Please enter something in a line :)\n");
	scanf("%s", line);
	count = strlen(line);
	for (i = count - 1; i >= 0; i--)
		printf("%c", line[i]);
	printf("\n");

	return 0;
}