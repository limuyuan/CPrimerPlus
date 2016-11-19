//Programming Exercise 4.8.6
#include <stdio.h>
#include <string.h>
int main()
{
	char first[20];
	char last[20];

	printf("Please input your first name:\n");
	scanf("%s", first);
	printf("Please input your last name:\n");
	scanf("%s", last);
	printf("%s %s\n", first, last);
	printf("%*d %*d\n", strlen(first), strlen(first), strlen(last), strlen(last));
	printf("%s %s\n", first, last);
	printf("%-*d %-*d\n", strlen(first), strlen(first), strlen(last), strlen(last));

	return 0;
}
