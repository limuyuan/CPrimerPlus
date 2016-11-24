### 判断下列各表达式是`true`还是`false`

```c
a. 100 > 3 && 'a' > 'c'
b. 100 > 3 || 'a' > 'c'
c. !(100 > 3)
```

a, c为`false`，b为`true`

### 根据下列描述的条件，分别构造一个表达式：

> a. `number`等于或大于90，但是小于100  
> b. `ch`不是字符`q`或`k`  
> c. `number`在1~9之间（包括1和9），但不是5  
> d. `number`不在1~9之间

a. `number >= 90 && number < 100`  
b. `ch != 'q' && ch != 'k'`  
c. `number >= 1 && number <= 9 && number != 5`  
d. `number < 1 && number > 9`

### 下面的程序关系表达式过于复杂，而且还有些错误，请简化并改正

```c
#include <stdio.h>
int main(void)	/* 1 */
{				/* 2 */
	int weight, height;		/* weight以磅为单位，height以英寸为单位 */
							/* 4 */
	scanf("%d ,weight, height);		/* 5 */
	if (weight < 100 && height > 64)	/* 6 */
		if (height >= 72)				/* 7 */
			printf("You are very tall for your weight.\n");	/* 8 */
		else if (height < 72 && > 64)						/* 9 */
			printf("You are tall for your weight.\n");		/* 10 */
		else if (weight > 300 && !(weight <= 300)			/* 11 */
			&& height < 48)				/* 12 */
			if (!(height >= 48))		/* 13 */
				printf(" You are quite short for your weight.\n");
	else		/* 15 */
				printf("Your weight is ideal.\n");			/* 16 */
																/* 17 */
	return 0;
}
```
该程序存在的问题：

- 第5行，格式化字符串有误，两个变量应该采用两个转换声明，并且变量名前面应加`&`
- 第6行，测试条件有误，应为`height < 100 && height > 64`
- 第9行，关系运算符两边应该均为表达式，右边表达式不完整
- 第11行，`!(weight <= 300)`可化简为`weight > 300`，但是和第一个表达式完全相同，为提高可读性应和第12行合并
- 第13行，`!(height >= 48)`可化简为`height < 48`，和第12行的表达式完全相同，应直接删除本行
- 第15行，编译器忽略缩进，需要将7~14行的内容用花括号括起来

修改后的代码为：
```c
#include <stdio.h>
int main(void)	/* 1 */
{				/* 2 */
	int weight, height;		/* weight以磅为单位，height以英寸为单位 */
							/* 4 */
	scanf("%d %d" ,&weight, &height);		/* 5 */
	if (height < 100 && height > 64)	/* 6 */
	{
		if (height >= 72)				/* 7 */
			printf("You are very tall for your weight.\n");	/* 8 */
		else if (height < 72 && height> 64)						/* 9 */
			printf("You are tall for your weight.\n");		/* 10 */
		else if (weight > 300 && height < 48)				/* 11 */
			printf(" You are quite short for your weight.\n");
	}
		else		/* 15 */
					printf("Your weight is ideal.\n");			/* 16 */
																/* 17 */
	return 0;
}
```