//Programming Exercise 3.11.2
#include <stdio.h>
int main(void)
{
	int ascii;

	printf("Give me your ASCII code value (decimal only):");
	scanf("%d", &ascii);
	printf("Your code value %d is '%c' in ASCII.\n", ascii, ascii);

	return 0;
}
