## 写出执行完下列各行后`quack`的值是多少。后5行中使用的是第1行的`quack`值

```c
  int quack = 2;
  quack += 5;   //quack = 7
  quack *= 10;  //quack = 20
  quack -= 6;   //quack = -4
  quack /= 8;   //quack = 0
  quack %= 3;   //quack = 2
```


## 假设`value`是`int`类型，下面循环的输出是什么？

```c
for (value = 36; value > 0; value /= 2)
  printf("%3d", value);
```

如果`value`是`double`类型，会出现什么问题？

推测输出结果：

`   0`[X]

实际输出结果：

> ` 36 18  9  4  2  1`

错误原因：误认为打印语句处于`for`循环外

如果`value`是`double`类型，计算过程中会导致无限循环（直到超过`double`类型的精度表示范围），又因`printf`以整型形式打印数字，会在最后出现很多个数字`0`

实际运行结果：

```
...(很多个0)
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0-21474836481073741824536870912-1879048192120795955260397977630198
98881509949447549747237748736188743689437184471859223592961179648589824294912147
4567372836864184329216460823041152576288144 72 36 18  9  4  2  1请按任意键继续.
. .
```
为了试图分隔开后面的长数字，修改格式化字符串为`" %3d"`，结果如下：
```
...(很多个0)
0   0   0   0   0 -2147483648 1073741824 536870912 -1879048192 1207959552 603
979776 301989888 150994944 75497472 37748736 18874368 9437184 4718592 2359296 11
79648 589824 294912 147456 73728 36864 18432 9216 4608 2304 1152 576 288 144  72
36  18   9   4   2   1请按任意键继续. . .
```
为了进一步弄清楚产生这种现象的原因，继续修改格式化字符串为`" %.3le"`，结果如下：
```
...
  4.663e-317 2.331e-317 1.166e-317 5.828e-318 2.914e-318 1.457e-318 7.285e-319 3
.643e-319 1.821e-319 9.107e-320 4.553e-320 2.277e-320 1.138e-320 5.692e-321 2.84
6e-321 1.423e-321 7.115e-322 3.557e-322 1.779e-322 8.893e-323 4.447e-323 1.976e-
323 9.881e-324 4.941e-324请按任意键继续. . .
```
可以看到，以整型输出的`double`类型变量实际上一直在减小，应该是`double`在内存中被截断为`int`之后导致了显示为整数的情况。

查看`<float.h>`头文件，找到两个和`double`类型精度有关的明示常量：

```c
#define DBL_MIN          2.2250738585072014e-308 // min positive value
#define DBL_TRUE_MIN     4.9406564584124654e-324 // min positive value
```
可以看出，导致循环终止的原因是，循环中最后一个数字`4.941e-324`除以2之后的结果小于`DBL_TRUE_MIN`的值

至于为什么`<float.h>`中要采用`DBL_MIN`和`DBL_TRUE_MIN`两个具有相同注释的常量的原因，这是另外一个问题，暂且略过，不过查到了这样一个带注释的版本：
```c
#ifndef DBL_TRUE_MIN
/* DBL_TRUE_MIN is a common non-standard extension for the minimum denorm value
 * DBL_MIN is the minimum non-denorm value -- use that if TRUE_MIN is not defined */
#define DBL_TRUE_MIN DBL_MIN
#endif
```

> 答案中指明了这种现象的正确名词：浮点数下溢(*underflow*)

## 用代码表示以下测试条件：

> a. x大于5  
> b. `scanf()`读取一个名为`x`的`double`类型值且失败  
> c. x的值等于5  

a. `x > 5`  
b. `scanf("%lf", &x) == 0`  
c. `x == 5`

## 用代码表示以下测试条件：

> a. `scanf()`成功读入一个整数  
> b. `x`不等于5  
> c. `x`大于或等于20  

a. `scanf("%d", n) == 1`  
b. `x != 5`  
c. `x >= 20`

## 下面的程序有点问题，请找出问题所在

```c
#include <stdio.h>
int main(void)
{									/* 第3行 */
	int i, j, list(10);				/* 第4行 */

	for (i = 1, i <= 10, i++)		/* 第6行 */
	{								/* 第7行 */
		list[i] = 2 * i + 3;		/* 第8行 */
		for (j = i, j >= i, j++)	/* 第9行 */
			printf(" %d", list[j]);	/* 第10行 */
		printf("\n");				/* 第11行 */
	}								/* 第12行 */
}
```


- 第4行：声明数组应使用方括号`[]`，改为`list[10]`
- 第6行：`for`语句中，初始化、测试条件、更新三部分应使用分号`;`隔开，而不是逗号`,`。另外，数组中元素下标的范围应为0~9，而不是1~10
- 第9行：`for`语句中，初始化、测试条件、更新三部分应使用分号`;`隔开，而不是逗号`,`。另外，测试条件有误，`j >= i`始终成立，会导致无限循环

修改后的程序为：

```c
#include <stdio.h>
int main(void)
{									/* 第3行 */
	int i, j, list[10];				/* 第4行 */

	for (i = 0; i < 10; i++)		/* 第6行 */
	{								/* 第7行 */
		list[i] = 2 * i + 3;		/* 第8行 */
		for (j = i; j <= i; j++)	/* 第9行 */
			printf(" %d", list[j]);	/* 第10行 */
		printf("\n");				/* 第11行 */
	}								/* 第12行 */
}
```


## 编写一个程序打印下面的图案，要求使用嵌套循环：

```
$$$$$$$$
$$$$$$$$
$$$$$$$$
$$$$$$$$
```

## 下面的程序各打印什么内容？

```c
a.
#include <stdio.h>

int main(void)
{
	int i = 0;

	while (++i < 4)
		printf("Hi! ");
	do
		printf("Bye! ");
	while (i++ < 8);
	return 0;
}

b.
#include <stdio.h>

int main(void)
{
	int i;
	char ch;

	for (i = 0, ch = 'A'; i < 4; i++, ch += 2 * i)
		printf("%c", ch);
	return 0;
}
```

## 假设用户输入的是`Go west, young man!`，下面各程序的输出是什么？（在ASCII码中，`!`紧跟在空格字符后面）

```c
a.
#include <stdio.h>

int main(void)
{
	char ch;

	scanf("%c", &ch);
	while (ch != 'g')
	{
		printf("%c", ch);
		scanf("%c", &ch);
	}
	return 0;
}

b.
#include <stdio.h>

int main(void)
{
	char ch;

	scanf("%c", &ch);
	while (ch != 'g')
	{
		printf("%c", ++ch);
		scanf("%c", &ch);
	}
	return 0;
}

c.
#include <stdio.h>

int main(void)
{
	char ch;

	do {
		scanf("%c", &ch);
		printf("%c", ch);
	} while (ch != 'g');
	return 0;
}

d.
#include <stdio.h>

int main(void)
{
	char ch;

	scanf("%c", &ch);
	for (ch = '$'; ch != 'g'; scanf("%c", &ch))
		printf("%c", ch);
	return 0;
}
```

## 下面的程序打印什么内容？

```c
#include <stdio.h>

int main(void)
{
	int n, m;

	n = 30;
	while (++n <= 33)
		printf("%d|", n);

	n = 30;
	do
		printf("%d|", n);
	while (++n <= 33);

	printf("\n***\n");

	for (n = 1; n * n < 200; n += 4)
		printf("%d\n", n);

	printf("\n***\n");

	for (n = 2, m = 6; n < m; n *= 2, m += 2)
		printf("%d %d\n", n, m);

	printf("\n***\n");

	for (n = 5; n > 0; n--)
	{
		for (m = 0; m <= n; m++)
			printf("=");
		printf("\n");
	}
	return 0;
}
```

## 考虑下面的声明：

```c
double mint[10];
```

> a. 数组名是什么？  
> b. 该数组有多少个元素？  
> c. 每个元素可以储存什么类型的值？
> d. 下面的哪一个`scanf()`的用法正确？  
      i. `scanf("%lf", mint[2])`  
      ii. `scanf("%lf", &mint[2])`  
      iii. `scanf("%lf", &mint)`  

## Noah先生喜欢以2计数，所以编写了下面的程序，创建了一个储存2、4、6、8等数字的数组

这个程序是否有错误之处？如果有，请指出。

```c
#include <stdio.h>
#define SIZE 8
int main(void)
{
	int by_twos[SIZE];
	int index;

	for (index = 1; index <= SIZE; index++)
		by_twos[index] = 2 * index;
	for (index = 1; index <= SIZE; index++)
		printf("%d ", by_twos);
	printf("\n");
	return 0;
}
```

## 假设要编写一个返回`long`类型值的函数，函数定义中应包含什么？

## 定义一个函数，接受一个`int`类型的参数，并以`long`类型返回参数的平方值

## 下面的程序打印什么内容？

```c
#include <stdio.h>
int main(void)
{
	int k;
	for (k = 1, printf("%d: Hi!\n", k)); printf("k = %d\n", k),
		k * k < 26; k += 2, printf("Now k is %d\n", k))
		printf("k is %d in the loop\n", k);
	return 0;
}
```
