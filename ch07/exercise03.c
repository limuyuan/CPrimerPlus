//Programming Exercise 7.12.3
#include <stdio.h>
int main(void)
{
	int odd_num, even_num, integer, even, odd;
	odd_num = even_num = even = odd = 0;
	double even_aver, odd_aver;

	printf("Please enter an integer (0 to quit):\n");
	while (scanf("%d", &integer) == 1 && integer != 0)
	{
		if (integer % 2 == 0)
		{
			even += integer;
			even_num++;
		}
		else
		{
			odd += integer;
			odd_num++;
		}
		printf("Please enter another integer (0 to quit):\n");
	}
	even_aver = (double)even / even_num;
	odd_aver = (double)odd / odd_num;

	//尝试加入单复数判定及数量为0时不报告平均数判定
	even_num <=1 ? printf("You've entered %d even integer\n", even_num)
		: printf("You've entered %d even integers\n", even_num);
	if(even_num != 0)
		printf("The average value of the even numbers is %f\n", even_aver);
	odd_num <= 1 ? printf("You've entered %d odd integer\n", odd_num)
		: printf("You've entered %d odd integers\n", odd_num);
	if (odd_num != 0)
		printf("The average value of the odd numbers is %f\n", odd_aver);
	
	return 0;
}