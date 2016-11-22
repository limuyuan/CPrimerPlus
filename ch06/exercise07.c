//Programming Exercise 6.16.7
#include <stdio.h>
int main(void)
{
	char word[100];
	int i;

	printf("Please enter your word:\n");
	scanf("%s", word);
	for (i = strlen(word) - 1; i >= 0; i--)
		printf("%c", word[i]);
	printf("\n");

	return 0;
}