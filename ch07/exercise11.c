//Programming Exercise 7.12.11
#include <stdio.h>
#include <stdbool.h>
#define PRICEA 2.05		//price of artichokes (dollar per pound)
#define PRICEB 1.15		//price of beets (dollar per pound)
#define PRICEC 1.09		//price of carrots (dollar per pound)
#define POUNDBREAK1 5	//POUNDBREAK1磅以下收取SHIP1美元运费和包装费
#define POUNDBREAK2 20	//POUNDBREAK1~2之间收取SHIP2美元运费和包装费
#define SHIP1 6.5
#define SHIP2 14
#define SHIP3PLUS 0.5	//超过POUNDBREAK2，在SHIP2费用的基础上每磅SHIP3PLUS美元
#define PRICEBREAK 100	//加运费前折扣价格
#define DISCOUNT 0.05	//超过PRICEBREAK后折扣幅度

int main(void)
{
	char option;
	double apound, bpound, cpound, pound, temp;		//三种蔬菜的磅数和总磅数，temp为临时输入值
	double total, ship, price;	//total = price + ship
	bool DISCOUNT_FLAG;
	apound = bpound = cpound = pound = total = ship = price = 0;

	//提示信息（目录）
	printf("**************The ABC Mail Order Grocery Order System*************\n");
	printf("Enter the letter corresponding to the desired vegetable or action:\n");
	printf("a) Artichokes               b) Beets\n");
	printf("c) Carrots\n");
	printf("q) Quit ordering process\n");
	printf("******************************************************************\n");

	while ((option = getchar()) == 'a' || option == 'b' || option == 'c')	//输入循环
	{
		switch (option)
		{
			case 'a':
				printf("Please enter pounds of artichokes (q to finish):\n");
				//失败原因：scanf()读取输入失败后会将输入退回，下一次循环的时候使用的直接是上一次输入的'q'，会导致直接跳出循环
				while (scanf("%lf", &temp) == 1)
				{
					apound += temp;
					printf("More pounds of artichokes? (q to finish)\n");
				}
				getchar();
				getchar();
				//解决方法：使用两个getchar()，一个接收输入的'q'，另外一个接收换行符（回车）
				break;
			case 'b':
				printf("Please enter pounds of beets (q to finish):\n");
				while (scanf("%lf", &temp) == 1)
				{
					bpound += temp;
					printf("More pounds of beets? (q to finish)\n");
				}
				getchar();
				getchar();
				break;
			case 'c':
				printf("Please enter pounds of carrots (q to finish):\n");
				while (scanf("%lf", &temp) == 1)
				{
					cpound += temp;
					printf("More pounds of carrots? (q to finish)\n");
				}
				getchar();
				getchar();
				break;
		}
		if ('q' == option)
			break;
		putchar('\n');
		printf("**************The ABC Mail Order Grocery Order System*************\n");
		printf("Enter the letter corresponding to the desired vegetable or action:\n");
		printf("a) Artichokes               b) Beets\n");
		printf("c) Carrots\n");
		printf("q) Quit ordering process\n");
		printf("******************************************************************\n");
	}

	//数据处理部分
	price = apound * PRICEA + bpound * PRICEB + cpound * PRICEC;
	if (price > PRICEBREAK)
	{
		price *= (1 - DISCOUNT);
		DISCOUNT_FLAG = true;
	}
	else
		DISCOUNT_FLAG = false;

	pound = apound + bpound + cpound;
	if (pound < POUNDBREAK1)
		ship = SHIP1;
	else if (pound < POUNDBREAK2)
		ship = SHIP2;
	else
		ship = SHIP2 + (pound - POUNDBREAK2) * SHIP3PLUS;

	total = price + ship;

	//输出部分
	printf("\n---------------------------------------------------------\n");
	printf("Artichokes: $%.2f/pound, you have ordered %.1f pound(s)\n",PRICEA,apound);
	printf("Beets: $%.2f/pound, you have ordered %.1f pound(s)\n",PRICEB,bpound);
	printf("Carrots: $%.2f/pound, you have ordered %.1f pound(s)\n", PRICEC, cpound);
	printf("---------------------------------------------------------\n");
	printf("Summary:\n\n");
	printf("Artichokes: $%.2f\nBeets: $%.2f\nCarrots: $%.2f\n", PRICEA * apound, PRICEB * bpound, PRICEC * cpound);
	printf("Total: $%.2f\n\n", price);
	if (DISCOUNT_FLAG)
		printf("Discount: -$%.2f\n", DISCOUNT * (apound * PRICEA + bpound * PRICEB + cpound * PRICEC));
	printf("Shipment: $%.2f\n", ship);
	printf("Grand Total Cost: $%.2f\n\n", total);

	printf("Thank you for purchasing!\nYour vegetables will arrive within 3 minutes:)\n");

	return 0;
}