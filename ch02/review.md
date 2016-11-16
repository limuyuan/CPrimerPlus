## C语言的基本模块是什么？
C程序包含一个或多个函数，它们是C程序的基本模块。

## 什么是语法错误？写出一个英语例子和C语言例子。
C语言的语法错误指的是，把有效的C符号用错了地方。

英语例子：good the today is wheater very  
C语言例子：int printf(main()):

## 什么是语义错误？写出一个英语例子和C语言例子。
语义错误是指意思上的错误。在C语言中，如果遵循了C规则，但是结果不正确，那就是犯了语义错误。

英语例子：Today I see music never.  
C语言例子：a_minus_b = a + b;

## Indiana Sloth 编写了下面的程序，并征求你的意见。请帮助他评定。
```c
include studio.h
int main{void} /* 该程序打印一年有多少周 /*
(
    int s
    
    s := 56;
    print(There are s weeks in a year.);
    return 0;
```
该程序有多处语法错误：

1. include前应加`#`，标准库的名字输入错误，应为`stdio.h`，并用`<>`或`""`将标准库的名字包含在内
2. 注释结尾符号错误，应改为`/* 该程序打印一年有多少周 */`，另外main函数的括号应改为圆括号即`main()`
3. 函数体应用花括号括起来，`(`改为`{`，并在代码结尾处添加`}`
4. int s后缺失分号
5. 查了一下没有`:=`的用法，赋值直接用`=`
6. 格式化输出语句有误，应为`printf`，同时语法也不对，应为`printf("There a %d weeks in a year.", s);`，但是一年有52周而不是56周，所以上一条中s应该赋值为`s = 52;`

> - 关于`#include <filename>`和`#include "filename"`的区别，参看StackOverflow问答[What is the difference between #include <filename> and #include “filename”?](http://stackoverflow.com/questions/21593/what-is-the-difference-between-include-filename-and-include-filename)
> - 关于第5点错误，答案中指出，Pascal中赋值方式即为`:=`，这说明Indiana Sloth了解Pascal（好吧我不了解

修改后的代码为：
```c
#include <stdio.h>
int main(void) /* 该程序打印一年有多少周 */
{
    int s;
    
    s = 52;
    printf("There are %d weeks in a year.",s);
    return 0;
}
```
> 对比答案发现，输出一句答案多添加了一个换行符`\n`，即`printf("There are %d weeks in a year.\n",s);`，虽然本程序只有一句输出，并且加换行符不会影响看起来的输出结果，但是加上换行符某种程度上来说是一个好习惯，以后的练习中多加注意。

## 假设下面的4个例子都是完整程序的一部分，它们都输出什么结果？
```c
a.  printf(Baa Baa Black Sheep.");
    Printf("Have you any wool?\n");
b.  printf("Begone!\nO Creature of lard!\n");
c.  printf("What?\nNo/nfish?\n");
d.  int num;
    num = 2;
    printf("%d + %d = %d", num, num, num + num);
```
a.
```
Baa Baa Baa Black Sheep.Have you any wool?
```

b.
```
Begone!  
O Creature of lard!
```

c.
```
What?  
No/nfish?
```
    
d.
```
2 + 2 = 4
```

## 在`main`、`int`、`function`、`char`、`=`中，哪些是C语言的关键字？
~~`main`~~、`int`、`char`是C语言的关键字

> 正确答案：`main`是函数名，`function`是用来描述C语言的一种术语（函数），`=`是运算符(operator)

## 如何以下面的格式输出变量words和lines的值（这里，3020和350代表两个变量的值）？
```
There were 3020 words and 350 lines.
```
输出方法：
```c
printf("There were %d words and %d lines.", words, lines);
```

## 考虑下面的程序：
```c
#include <stdio.h>
int main(void)
{
    int a, b;
    
    a = 5;
    b = 2;  /* 第7行 */
    b = a;  /* 第8行 */
    a = b;  /* 第9行 */    
    printf("%d %d\n",b,a);
    return 0;
}
```
请问，在执行完第7、第8、第9行后，程序的状态分别是什么？

第7行：
```
a = 5, b = 2
```
第8行：
```
a = 5, b = 5
```
第9行：
```
a = 5, b = 5
```

## 考虑下面的程序：
```c
#include <stdio.h>
int main(void)
{
    int x, y;
    
    x = 10;
    y = 5;      /* 第7行 */
    y = x + y;  /* 第8行 */
    x = x * y;  /* 第9行 */
    printf("%d %d\n", x, y);
    return 0;
}
```
请问，在执行完第7、第8、第9行后，程序的状态分别是什么？
第7行：
```
x = 10, y = 5
```
第8行：
```
x = 10, y = 15
```
第9行：
```
x = 150, y = 15
```
