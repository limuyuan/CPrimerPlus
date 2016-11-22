//Programming Exercise 6.16.5
#include <stdio.h>
int main(void)
{
	char cap;	//cap为输入大写字母
	int line;			//行数
	int i, space, words;		//i为行数索引，space为打印空格数量，words为字母偏移量

	printf("Enter a capital alphabet (A~Z):");
	scanf("%c", &cap);	//将输入值的ASCII码存入变量cap
	line = cap - 'A' + 1;	//打印行数

	//printf("lines = %d\n", line);	//测试行数是否正确

	for (i = 1; i <= line; i++)		//每行一次循环，共打印line行
	{
		//里循环1，用于打印空格数
		for (space = line - i + 1; space > 0; space--)		//空格数初始值为总行数-当前行数+1，即打印(line-i+1)个空格
			printf(" ");

		//里循环2，用于打印升序字母
		for (words = 0; words < i; words++)			//字母偏移量为0，逐渐增加
			printf("%c", 'A' + words);

		//printf("words = %d\n", words);	//测试打完升序字母后words偏移量的值

		//里循环3，用于打印降序字母
		for (words--; words > 0; words--)	//上一个循环后words的量多增加了1，故在初始条件中减去1
			printf("%c", 'A' + words - 1);	//降序后要多往前退一个字母
		printf("\n");
	}
	return 0;
}