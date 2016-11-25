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
d. ~~`number < 1 && number > 9`~~

> 更正：d. `number < 1 || number > 9`

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
- ~~第6行，测试条件有误，应为`height < 100 && height > 64`~~
- 第9行，关系运算符两边应该均为表达式，右边表达式不完整
- 第11行，`!(weight <= 300)`可化简为`weight > 300`，但是和第一个表达式完全相同，为提高可读性应和第12行合并
- 第13行，`!(height >= 48)`可化简为`height < 48`，和第12行的表达式完全相同，应直接删除本行
- 第15行，编译器忽略缩进，需要将7~14行的内容用花括号括起来

修改后的程序：
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

> 答案中的补充：  
> - 输入前应该有一条提示用户输入的语句
> - 根据具体条件，对应的`if else`可直接改成`else`
> - 第6行没有错误，应加深对程序编写者意图的了解

进一步修改后的程序：
```c
#include <stdio.h>
int main(void)	/* 1 */
{				/* 2 */
	int weight, height;		/* weight以磅为单位，height以英寸为单位 */
	printf("Please enter your weight in pounds and height in inches:\n"); /* 4 */
	scanf("%d %d", &weight, &height);		/* 5 */
	if (weight < 100 && height > 64)	/* 6 */
	{
		if (height >= 72)				/* 7 */
			printf("You are very tall for your weight.\n");	/* 8 */
		else					/* 9 */
			printf("You are tall for your weight.\n");		/* 10 */
	}
	else if (weight > 300 && height < 48)				/* 11 */
			printf(" You are quite short for your weight.\n");
	else		/* 15 */
		printf("Your weight is ideal.\n");			/* 16 */
													/* 17 */
	return 0;
}
```


### 下列各表达式的值是多少？
```c
a. 5 > 2
b. 3 + 4 > 2 && 3 < 2
c. x >= y || y > x
d. d = 5 + (6 > 2)
e. 'X' > 'T' ? 10 : 5
f. x > y ? y > x : x > y
```
a. 1  
b. 0  
c. 1
d. 6  
e. 10  
f. 0  

### 下面的程序将打印什么？

```c
#include <stdio.h>
int main(void)
{
	int num;
	for (num = 1; num <= 111; num++)
	{
		if (num % 3 == 0)
			putchar('$');
		else
			putchar("*");
			putchar('#');
		putchar('%');
	}
	putchar('\n');
	return 0;
}
```
输出内容：
```
*#%*#%$#% ... *#%*#%$#%

```


### 下面的程序将打印什么？

```c
#include <stdio.h>
int main(void)
{
	int i = 0;
	while(i < 3) {
		switch(i++) {
			case 0: printf("fat ");
			case 1: printf("hat ");
			case 2: printf("cat ");
			default: printf("Oh no!");
		}
		putchar('\n');
	}
	return 0;
}
```
推测输出内容：
```
cat Oh no!
Oh no!

```

实际输出内容：
```
fat hat cat Oh no!
hat cat Oh no!
cat Oh no!

```

> 错误原因：`switch`语句根据`i++`的值来决定跳转到哪条`case`语句来执行。判断时要根据`switch`括号里的表达式的值来判断！

### 下面的程序有哪些错误？
```c
#include <stdio.h>
int main(void)
{
	char ch;
	int lc = 0; /* 统计小写字母
	int uc = 0; /* 统计大写字母
	int oc = 0; /* 统计其他字母

	while ((ch = getchar()) != '#')
	{
		if ('a' <= ch >= 'z')
			lc++;
		else if (!(ch < 'A') || !(ch > 'Z')
			uc++;
		oc++;
	}
	printf(%d lowercase, %d uppercase, %d other, lc, uc, oc);
	return 0;
}
```

该程序有多处存在错误，也有多处可进一步优化：

- 注释应采用`//`或`/* */`，本程序的注释缺少注释结束标记`*/`
- 判断小写字母条件有误，表示范围时应使用逻辑运算符来连接两个表达式
- 判断大写字母条件过于复杂，可进行简化，并且使用了错误的逻辑运算符，少了一个右圆括号`)`
- 格式化字符串未使用双引号，并应在末尾添加换行符增强可读性

修改后的代码为：

```c
#include <stdio.h>
int main(void)
{
	char ch;
	int lc = 0; /* 统计小写字母 */
	int uc = 0; /* 统计大写字母 */
	int oc = 0; /* 统计其他字母	*/

	while ((ch = getchar()) != '#')
	{
		if ('a' <= ch && ch <= 'z')
			lc++;
		else if (ch >= 'A' && ch <= 'Z')
			uc++;
		else
			oc++;
	}
	printf("%d lowercase, %d uppercase, %d other\n", lc, uc, oc);
	return 0;
}
```

> 答案补充：可以使用`<ctype.h>`头文件中的`islower()`、`isupper()`来提高程序的可移植性

### 下面的程序将打印什么？

```c
/* retire.c */
#include <stdio.h>
int main(void)
{
	int age = 20;
	while (age++ <= 65)
	{
		if ((age % 20) == 0)	/* age是否能被20整除？ */
			printf("You are %d. Here is a raise.\n", age);
		if (age = 65)
			printf("You are %d. Here is your gold watch.\n", age);
	}
	return 0;
}
```

推测输出内容：
```
You are 65. Here is your gold watch.

```

实际输出内容：
```
You are 65. Here is your gold watch.
You are 65. Here is your gold watch.
You are 65. Here is your gold watch.
...（重复打印）

```
> 错误原因：  第2个`if`语句的测试条件`age = 65`中，变量`age`被赋值65，`age = 65`表达式的值非零，所以恒为真。在`while`循环的测试条件中，`age++`的值也是65，因此从第二次`while`循环开始，`while`的循环条件也恒为真，从而导致了无限循环。**一定要注意递增运算符表达式的值！！！**



### 给定下面的输入时，以下程序将打印什么？
> q  
> c  
> h  
> b  

```c
#include <stdio.h>
int main(void)
{
	char ch;

	while ((ch = getchar()) != '#')
	{
		if (ch == '\n')
			continue;
		printf("Step 1\n");
		if (ch == 'c')
			continue;
		else if (ch == 'b')
			break;
		else if (ch == 'h')
			goto laststep;
		printf("Step 2\n");
	laststep: printf("Step 3\n");
	}
	printf("Done\n");
	return 0;
}
```

交互过程（粗体字为用户输入）：

**q**  
Step 1  
Step 2  
Step 3  
**c**  
Step 1  
**h**  
Step 1  
Step 3  
**b**  
Step 1  
Done

### 重写复习题9，但这次不能使用`continue`和`goto`语句

重写代码：
```c
#include <stdio.h>
int main(void)
{
	char ch;

	while ((ch = getchar()) != '#')
	{
		if (ch != '\n')
		{
			printf("Step 1\n");
			if (ch != 'c')
			{
				if (ch == 'b')
					break;
				if (ch == 'h')
					printf("Step 3\n");
				else
				{
					printf("Step 2\n");
					printf("Step 3\n");
				}
			}
		}
	}
	printf("Done\n");
	return 0;
}
```

> 关于最后的打印`Step 3`判断，答案提供了一种更简洁的方法，只要输入的字符不是`h`，则打印`Step 2`，否则跳过`Step 2`直接打印`Step 3`：

```c
if (ch != 'h')
	printf("Step 2\n");
printf("Step 3\n");
```
