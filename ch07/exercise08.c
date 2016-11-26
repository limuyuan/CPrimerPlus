//Programming Exercise 7.12.8
#include <stdio.h>
#define OVERTIME 1.5	//超过40小时的倍率
#define BREAK1 300		//300美元内为RATE1
#define RATE1 0.15
#define BREAK2 450		//300~450的150为RATE2，超过450为RATE3
#define RATE2 0.20
#define RATE3 0.25	
int main(void)
{
	int hours,option;
	double gross, tax, net, basic;

	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1) $8.75/hr                         2) $9.33/hr\n");
	printf("3) $10.00/hr                        4) $11.20/hr\n");
	printf("5) quit\n");
	printf("*****************************************************************\n");

	while (scanf("%d", &option) == 1)
	{
		switch (option)
		{
			case 1:	basic = 8.75;
					break;
			case 2:	basic = 9.33;
					break;
			case 3:	basic = 10.00;
					break;
			case 4:	basic = 11.2;
					break;
		}
		if (option > 4 || option < 1)
			break;
		printf("How many hours do you work in a week?\n");
		scanf("%d", &hours);
		if (hours <= 40)
			gross = basic * hours;
		else
			gross = basic * hours + OVERTIME * basic * (hours - 40);

		if (gross <= BREAK1)
			tax = gross * RATE1;
		else if (gross <= BREAK2)
			tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
		else
			tax = BREAK1 * RATE1 + (BREAK2 - BREAK1)*RATE2 + (gross - BREAK2)*RATE3;

		net = gross - tax;

		printf("Your gross pay: $%.2f\n", gross);
		printf("Your taxes: $%.2f\n", tax);
		printf("Your net pay: $%.2f\n\n\n", net);

		printf("*****************************************************************\n");
		printf("Enter the number corresponding to the desired pay rate or action:\n");
		printf("1) $8.75/hr                         2) $9.33/hr\n");
		printf("3) $10.00/hr                        4) $11.20/hr\n");
		printf("5) quit\n");
		printf("*****************************************************************\n");
	}
	printf("Thank you!\n");
	return 0;
}