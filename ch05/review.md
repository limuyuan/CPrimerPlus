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
> - 两个整型变量相除导致舍位，除了将变量`i`声明为`float`类型外，答案提供了另外一种方法：`n = 1.0 / i;`  
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
附程序清单5.9：
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

## 下面的程序将打印出什么内容？

```c
#include <stdio.h>
#define FORMAT "%s! C is cool!\n"
int main(void)
{
	int num = 10;

	printf(FORMAT, FORMAT);
	printf("%d\n", ++num);
	printf("%d\n", num++);
	printf("%d\n", num--);
	printf("%d\n", num);
	return 0;
}
```

推测运行结果：

%s! C is cool!  
C is cool!  
11   
11  
12  
11  

实际运行结果：

> %s! C is cool!  
! C is cool!  
11   
11  
12  
11  

遗漏了第二行的`!`。  
原因：`%s`作为格式化字符串转换说明时只代表`%s! C is cool!\n`这部分文字，相当于用`%s! C is cool!`加上一个换行符来替换格式化字符串中的`%s`，然后继续输出`%s`后面的`! C is cool!\n`内容。本题中`printf()`语句的实际内容：
```c
	printf("%s! C is cool!\n", "%s! C is cool!\n")
```

## 下面的程序将打印出什么内容？

```c
#include <stdio.h>
int main(void)
{
	char c1, c2;
	int diff;
	float num;

	c1 = 'S';
	c2 = 'O';
	diff = c1 - c2;
	num = diff;
	printf("%c%c%c:%d %3.2f\n", c1, c2, c1, diff, num);
	return 0;
}
```

推测运行结果：

SOS:4 4.00  
（4和4.00之间有1个空格）

实际运行结果与推测运行结果一致

**`printf`转换说明中字段宽度包含小数位数**

## 下面的程序将打印出什么内容？

```c
#include <stdio.h>
#define TEN 10
int main(void)
{
	int n = 0;

	while (n++ < TEN)
		printf("5d", n);
	printf("\n");
	return 0;
}
```

## 修改上一个程序，使其可以打印字母a~g

## 假设下面是完整程序中的一部分，它们分别打印什么？

```c
a.
	int x = 0;

	while (++x < 3)
		printf("%4d", x);

b.
	int x = 100;

	while (x++ < 103)
		printf("%4d\n“, x);
		printf("%4d\n", x);

c.
	char ch = 's';

	while (ch < 'w')
	{
		printf("%c", ch);
		ch++;
	}
```

## 下面的程序会打印出什么？

```c
#define MESG "COMPUtER BYTES DOG"
#include <stdio.h>
int main(void)
{
	int n = 0;

	while (n < 5)
		printf("%s\n", MESG);
		n++;
	printf("That's all.\n");
	return 0;
}
```

## 分别编写一条语句，完成下列各任务（或者说，使其具有以下副作用）：

> a. 将变量`x`的值增加10  
> b. 将变量`x`的值增加1  
> c. 将`a`与`b`之和的两倍赋给`c`  
> d. 将`a`与[`b`的两倍]之和赋给`c`

## 分别编写一条语句，完成下列各任务：

> a. 将变量`x`的值减少1  
> b. 将`n`除以`k`的余数赋给`m`  
> c. `q`除以[`b`减去`a`]，并将结果赋给`p`  
> d. `a`与`b`之和除以`c`与`d`的乘积，并将结果赋给`x`
