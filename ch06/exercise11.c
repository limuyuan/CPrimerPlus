//Programming Exercise 6.16.11
#include <stdio.h>
int main(void)
{
	int num[20], i;

	printf("Please enter 8 integers:\n");
	for (i = 0; i < 8; i++)
		scanf("%d", &num[i]);
	printf("Your 8 integers are:\n");
	for (i = 0; i < 8; i++)
		printf("%d ", num[i]);
	printf("\nAnd the reverse order are:\n");
	for (i = 7; i >= 0; i--)
		printf("%d ", num[i]);
	printf("\n");
	

	return 0;
}
