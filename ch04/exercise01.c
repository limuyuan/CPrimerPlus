//Programming Exercise 4.8.1
#include <stdio.h>
int main()
{
	char first[20];
	char last[20];

	printf("What's your first name?\n");
	scanf("%s", first);
	printf("and your last name?\n");
	scanf("%s", last);
	printf("%s,%s\n", last, first);

	return 0;
}
