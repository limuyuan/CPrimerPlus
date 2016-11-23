//Programming Exercise 6.16.17
#include <stdio.h>
int main(void)
{
	const double BONUS = 1000000.00;
	const double WITHDRAW = 100000.00;
	int years = 0;
	double balance;

	balance = BONUS;
	while (balance > 0)
	{
		balance = 1.08 * balance;	//因为是每年年底，所以先算利息，再取钱
		balance -= WITHDRAW;
		years++;
		printf("Year %2d, your balance is $%.2f\n", years, balance);
	}
	printf("Insufficient funds! It takes %d years!\n", years);

	return 0;
}