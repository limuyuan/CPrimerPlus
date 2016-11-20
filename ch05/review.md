## 假设所有变量的类型都是`int`，下列各项变量的值是多少：

```c
a.  x = (2 + 3) * 6;
b.  x = (12 + 6) / 2 * 3;
c.  y = x = (2 + 3) / 4;
d.  y = 3 + 2 * (x = 7 / 2);
```

a. `x = 30`  
b. `x = 27`  
c. `x = 1, y = 1`  
d. `x = 3, y = 9`

## 假设所有变量的类型都是`int`，下列各项变量的值是多少：

```c
a.  x = (int)3.8 + 3.3;
b.  x = (2 + 3) * 10.5;
c.  x = 3 / 5 * 22.0;
d.  x = 22.0 * 3 / 5;
```

a. `x = 6`  
b. `x = 52`  
c. `x = 0`  
d. `x = 13`

> 当运算符共享一个运算对象时，优先级决定了求职顺序。结合律只适用于*共享*同一运算对象运算符。`+` `-` `*` `\`的结合律都是从左往右，因此从左往右计算表达式。这导致了c和d答案的不同，在下一题中也有直观地表现出来。

## 对下列各表达式求值：

```c
a. 30.0 / 4.0 * 5.0;
b. 30.0 / (4.0 * 5.0);
c. 30 / 4 * 5;
d. 30 * 5 / 4;
e. 30 / 4.0 * 5;
f. 30 / 4 * 5.0;
```

a. `37.5`  
b. `1.5`  
c. `35`  
d. `37`  
e. `37.5`  
f. `35.0`

## 请找出下面的程序中的错误：

```c
int main(void)
{
	int i = 1,
	float n;
	printf("Watch out! Here come a bunch of fractions!\n");
	while (i < 30)
		n = 1 / i;
		printf(" %f", n);
	printf("That's all, folks!\n");
	return;
}
```

该程序有多处错误：

1. 未包含`<stdio.h>`头文件
2. 声明应以分号`;`结尾，而不是逗号
3. 缩进在`while`循环中不起作用，应该将循环体用花括号`{}`包围起来
3. 程序中没有设置循环终止的条件，会导致无限循环
4. 变量`i`被声明为`int`整型类型，两个整型相除会导致舍位，无法正确显示小数
4. `return`返回值应为0

修改后的程序为：

```c
#include <stdio.h>
int main(void)
{
	float i = 1.0;
	float n;
	printf("Watch out! Here come a bunch of fractions!\n");
	while (i++ < 30)
	{
		n = 1 / i;
		printf(" %f", n);
	}
	printf("That's all, folks!\n");
	return 0;
}
```
> - 两个整数相除导致舍位，除了将变量`i`声明为`float`类型外，答案提供了另外一种方法：`n = 1.0 / i;`  
> - `printf()`格式化字符串中没有换行符`\n`，这将导致数字被打印成一行（我以为加了个空格就是想要打在一行呢:joy:

## 这是程序清单5.9的另一个版本。从表面上看，该程序只使用了一条`scanf()`语句，比程序清单5.9简单。请找出不如原版之处：

```c
#include <stdio.h>
#define S_TO_M 60
int main(void)
{
	int sec, min, left;
	prinf("This program converts seconds to minutes and ");
	printf("seconds.\n");
	printf("Just enter the number of seconds.\n");
	printf("Enter 0 to end the program.\n");
	while(sec > 0){
		scanf("%d", &sec);
		min = sec / S_TO_M;
		left = sec & S_TO_M;
		printf("%d sec is %d min, %d sec. \n", sec, min, left);
		printf("Next input?\n");
	}
	printf("Bye!\n");
	return 0;
}
```
程序清单5.9：
```c
//min_sec.c
#include <stdio.h>
#define SEC_PER_MIN 60
int main(void)
{
	int sec, min, left;

	printf("Convert seconds to minutes and seconds!\n");
	printf("Enter the number of seconds (<=0 to quit):\n");
	scanf("%d", &sec);
	while (sec > 0)
	{
		min = sec / SEC_PER_MIN;
		left = sec % SEC_PER_MIN;
		printf("%d seconds is %d minutes, %d seconds.\n", sec, min, left);
		printf("Enter next alue (<=0 to quit):\n");
		scanf("%d", &sec);
	}
	printf("Done!\n");

	return 0;
}
```
