//Programming Exercise 7.12.9
#include <stdio.h>
int main(void)
{
	int num, test;	//test用于测试是否为素数
	int i, count;	//count用于记录因数个数，为0则为素数

	printf("Please enter a positive integer (<= 0 to quit):\n");
	while (scanf("%d", &num) == 1)
	{
		if (num <= 0)
			break;

		for (test = 1; test <= num; test++)
		{
			for (i = 2, count = 0; i * i <= test; i++)
			{
				if (test % i == 0)
					count++;
			}
			if (0 == count)
				printf("%d is prime!\n", test);
		}
		printf("Please enter a positive integer (<= 0 to quit):\n");
	}
	printf("Bye!\n");

	return 0;
}