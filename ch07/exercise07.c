//Programming Exercise 7.12.7
#include <stdio.h>
#define BASIC 10
#define OVERTIME 1.5	//超过40小时的倍率
#define BREAK1 300		//300美元内为RATE1
#define RATE1 0.15
#define BREAK2 450		//300~450的150为RATE2，超过450为RATE3
#define RATE2 0.20
#define RATE3 0.25	
int main(void)
{
	int hours;
	double gross, tax, net;

	printf("How many hours do you work in a week?\n");
	scanf("%d", &hours);
	if (hours <= 40)
		gross = BASIC * hours;
	else
		gross = BASIC * hours + OVERTIME * BASIC * (hours - 40);

	if (gross <= BREAK1)
		tax = gross * RATE1;
	else if (gross <= BREAK2)
		tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
	else
		tax = BREAK1 * RATE1 + (BREAK2 - BREAK1)*RATE2 + (gross - BREAK2)*RATE3;

	net = gross - tax;

	printf("Your gross pay: $%.2f\n", gross);
	printf("Your taxes: $%.2f\n", tax);
	printf("Your net pay: $%.2f\n", net);

	return 0;
}