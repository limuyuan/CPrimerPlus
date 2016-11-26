//Programming Exercise 7.12.10
#include <stdio.h>
#define RATE1 0.15
#define RATE2 0.28
int main(void)
{
	int option;
	double basic, income, tax;

	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired category or action:\n");
	printf("1) Single                           2) Head of Household\n");
	printf("3) Married, Joint                   4) Married, Separate\n");
	printf("5) Quit\n");
	printf("*****************************************************************\n");

	while (scanf("%d", &option) == 1)
	{
		switch (option)
		{
		case 1:	basic = 17850;
			break;
		case 2:	basic = 23900;
			break;
		case 3:	basic = 29750;
			break;
		case 4:	basic = 14875;
			break;
		}
		if (option > 4 || option < 1)
			break;
		printf("Please enter your taxable income:\n$");
		scanf("%lf", &income);

		if (income <= basic)
			tax = income * RATE1;
		else
			tax = basic * RATE1 + (income - basic) * RATE2;

		printf("Your tax is: $%.2f\n\n\n", tax);

		printf("*****************************************************************\n");
		printf("Enter the number corresponding to the desired category or action:\n");
		printf("1) Single                           2) Head of Household\n");
		printf("3) Married, Joint                   4) Married, Separate\n");
		printf("5) Quit\n");
		printf("*****************************************************************\n");
	}

	printf("Thank you!\n");
	return 0;
}