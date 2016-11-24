### 再次运行程序清单4.1，但是在要求输入名时，请输入名和姓，看看会发生什么情况？为什么？

> 根据英文书写习惯，名和姓中间有一个空格

```c
//Listing 4.1 talkback.c
#include <stdio.h>
#include <string.h>
#define DENSITY 62.4
int main()
{
	float weight, volume;
	int size, letters;
	char name[40];

	printf("Hi! What's your first name?\n");
	scanf("%s", name);
	printf("%s, what's your weight in pounds?\n", name);
	scanf("%f", &weight);
	size = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;
	printf("Well, %s, your volume is %2.2f cubic feet.\n",
		name, volume);
	printf("Also, your first name has %d letters,\n",
		letters);
	printf("and we have %d bytes to store it.\n", size);

	return 0;
}
```

输入名时的运行结果：

>Hi! What's your first name?  
**Muyuan**  
Muyuan, what's your weight in pounds?  
**147**  
Well, Muyuan, your volume is 2.36 cubic feet.  
Also, your first name has 6 letters,  
and we have 40 bytes to store it.  

输入名和姓时的运行结果：

>Hi! What's your first name?  
**Muyuan Li**  
Muyuan, what's your weight in pounds?  
Well, Muyuan, your volume is -1720740.00 cubic feet.  
Also, your first name has 6 letters,  
and we have 40 bytes to store it.

输入`Muyuan Li`并按回车后，`scanf()`函数的第一个转换说明是`%s`，从输入中读取非空白字符直到再次遇到空白，因此只会将`Muyuan`保存到字符数组`name[40]`中，将下一个`Li`放回输入，因此`scanf()`将下一次读取到的输入`Li`当作第二次输入，转换说明`%f`，故翻译成浮点数格式保存到变量`weight`对应的地址中，运行结果和第一次输入`Muyuan`，第二次输入`Li`完全相同：

>Hi! What's your first name?  
**MuYuan**  
MuYuan, what's your weight in pounds?  
**Li**  
Well, MuYuan, your volume is -1720740.00 cubic feet.  
Also, your first name has 6 letters,  
and we have 40 bytes to store it.

### 假设下列示例都是完整程序中的一部分，它们打印的结果分别是什么？

```c
a.
    printf("He sold the painting for $%2.2f.\n", 2.345e2);

b.
    printf("%c%c%c\n", 'H', 105, '\41');
    //'\41'为八进制表示方法，对应十进制为33

c.
    #define Q "His Hamlet was funny without being vulgar."
    printf("%s\nhas %d characters.\n", Q, strlen(Q));

d.
    printf("Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0);

```

a.
> ~~He sold the painting for $23.45.~~  
> He sold the painting for $234.50.  

b.
> Hi!

c.
> His Hamlet was funny without being vulgar.  
> has 42 characters.

d.
> ~~Is 1.20e2 the same as 1201.00?~~  
> Is 1.20e+03 the same as 1201.00?

**需要注意指数的位数及输出格式写法！**

### 在第2题的c中，要输出包含双引号的字符串Q，应如何修改？

修改方法：

在`%s`前后加上两个`\"`，未更改符号常量`Q`的值，仍然包含42个字符：

```c
#define Q "His Hamlet was funny without being vulgar."
printf("\"%s\"\nhas %d characters.\n", Q, strlen(Q));
```

或者在双引号内的符号常量`Q`前后加上两个`\"`，改变了字符串的值，包含44个字符：

```c
#define Q "\"His Hamlet was funny without being vulgar.\""
printf(%s\nhas %d characters.\n", Q, strlen(Q));
```

### 找出下面程序中的错误

```c
define B booboo
define X 10
main(int)
{
	int age;
	char name;
	printf("please enter your first name.");
	scanf("%s", name);
	printf("All right, %c, what's your age?\n", name);
	scanf("%f", age);
	xp = age + X;
	printf("That's a %s! You must be at least %d.\n", B, xp);
	rerun 0;
}
```

该程序有多处错误：

1. 未包含`<stdio.h>`头文件
1. `define`前应加上`#`
2. `#define`指令定义字符串常量时要使用双引号，即`#define B "booboo"`
3. `main()`函数书写错误，应为`int main(void)`
4. 应声明字符数组来储存姓名，不能只声明一个字符常量，改为`char name[40];`
5. 打印字符串转换说明应使用`%s`而不是`%c`
5. 年龄是一个整数，应使用`%d`整型转换说明而不是`%f`浮点型转换说明
6. 将输入读取到`age`变量对应的内存地址，变量名前面应该加上`&`，即`&age`
7. 未声明xp变量，C语言中必须先声明才能使用
8. 最后一行`rerun`拼写错误，应为`return`

修改后的程序代码为：
```c
#include <stdio.h>
#define B "booboo"
#define X 10
int main(void)
{
	int age;
	char name[40];
	int xp;

	printf("please enter your first name.");
	scanf("%s", name);
	printf("All right, %s, what's your age?\n", name);
	scanf("%d", &age);
	xp = age + X;
	printf("That's a %s! You must be at least %d.\n", B, xp);
	return 0;
}
```

> 第一句提示信息后应添加`\n`增强可读性

### 假设一个程序的开头是这样：

```c
#define BOOK "War and Peace"
int main(void)
{
	float cost = 12.99;
	float percent = 80.0;
}
```

请构造一个使用`BOOK`、`cost`和`percent`的`printf()`语句，打印以下内容：

> This copy of "War and Peace" sells for $12.99.  
> That is 80% of list.

代码如下：
```c
printf("This copy of \"%s\" sells for $%.2f.\nThat is %.0f%% of list.\n",
 BOOK, cost, percent);
```

**注意：双引号`"`的转义序列是`\"`，百分号`%`的转换说明是`%%`**

### 打印下列各项内容要分别使用什么转换说明？

a. 一个字段宽度与位数相同的十进制整数：`%d`或`%ld`或`%lld`，`d`可换成`u`用来打印无符号整数  
b. 一个形如`8A`、字段宽度为4的十六进制整数:`%4X`  
c. 一个形如`232.346`、字段宽度为10的浮点数：`%10.3f`  
d. 一个形如`2.33e+002`、字段宽度为12的浮点数：`%12.2e`  
e. 一个字段宽度为30、左对齐的字符串：`%-30s`

> 关于d.题目，答案正确，但是如果想要显示三位指数，参见StackOverflow: [How to display 2.33e+002 in C?](http://stackoverflow.com/questions/40679715/how-to-display-2-33e002-in-c)

### 打印下面各项内容要分别使用什么转换说明？

a. 字段宽度为15的`unsigned long`类型的整数：`%15lu`  
b. 一个形如`0x8a`、字段宽度为4的十六进制整数：`%#4x`  
c. 一个形如`2.33E+02`、字段宽度为12、左对齐的浮点数：`%-12.2E`  
d. 一个形如`+232.346`、字段宽度为10的浮点数：`%+10.3f`  
e. 一个字段宽度为8的字符串的前8个字符：`%8.8s`

### 打印下面各项内容要分别使用什么转换说明？

a.  一个字段宽度为6、最少有4位数字的十进制整数：`%6.4d`  
b. 一个在参数列表中给定字段宽度的八进制整数：`%*o`  
c. 一个字段宽度为2的字符：`%2c`  
d. 一个形如`+3.13`、字段宽度等于数字中字符数的浮点数：`%+.2f`  
e. 一个字段宽度为7、左对齐字符串中的前5个字符：`%-7.5s`

### 分别写出读取下列各输入行的`scanf()`语句，并声明语句中用到的变量和数组

a. 101  
```c
  int a;
  scanf("%d", &a);
```

b. 22.32 8.34E-09
```c
  float b1, b2;
  scanf("%f %f",&b1, &b2);
```

c. linguini
```c
  char c[20];
  scanf("%s",c);
```

d. catch 22
```c
  char d1[10];
  int d2;
  scanf("%s %d", d1, &d2);
```

e. catch 22 （但是跳过catch）
```c
  int e;
  scanf("%*s %d", &e);
```

### 什么是空白？

空白通常包括换行符、制表符和空格。

> C语言使用空白分隔记号(*tokens*)。`scanf()`使用空白分隔连续的输入项。

### 下面的语句有什么问题？如何修正？

```c
  printf("The double type is %z bytes..\n", sizeof(double));
```

该语句未表明使用`sizeof`的返回类型，正确示例：`%zd` `%zo`

> `%z`中的z是修饰符，不是转换字符。


### 假设要在程序中用圆括号代替花括号，以下方法是否可行？

```c
  #define ( {
  #define ) }  
```

不可行。

> 可以分别把`(`和`)`替换成`{`和`}`。但是预处理器无法区分哪些圆括号应该替换成花括号，哪些圆括号不能替换成花括号。  
> 比如：`int main(void)`将变成`int main{void}`
