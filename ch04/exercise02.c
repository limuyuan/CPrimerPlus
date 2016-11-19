//Programming Exercise 4.8.2
#include <stdio.h>
#include <string.h>
int main()
{
	char name[40];

	printf("What's your first name?\n");
	scanf("%s", name);

	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("\"%*s\"\n", strlen(name) + 3, name);

	return 0;
}
