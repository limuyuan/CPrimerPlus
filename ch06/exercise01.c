//Programming Exercise 6.16.1
#include <stdio.h>
int main(void)
{
	char alphabet[26];

	for (int i = 0; i < 26; i++)
	{
		alphabet[i] = 'a' + i;
		printf("%c", alphabet[i]);
	}
	return 0;
}