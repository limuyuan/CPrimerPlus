## 指出下面各种数据使用的合适数据类型（有些可使用多种数据类型）：
> a. East Simpleton的人口  
> b. DVD影碟的价格  
> c. 本章出现次数最多的字母  
> d. 本章出现次数最多的字母次数  

a. 根据地域大小，32767人及以内可用`short`，65535人及以内可用`unsigned short`，65535人以上可用`int`

b. ~~考虑到货币单位不同，选择`unsigned short`类型可尽可能降低溢出风险~~  
价格通常不是一个整数，对精度要求也不高，可以选择`float`类型。**C语言中无`unsigned float`！！！** 参见StackOverflow : [Why doesn't C have unsigned floats?](http://stackoverflow.com/questions/512022/why-doesnt-c-have-unsigned-floats)

c. 选择`char`储存字符

d. 节省存储空间，选择`unsigned short`

## 在什么情况下要用`long`类型的变量代替`int`类型的变量？

如果一个数超出了`int`的取值范围，且在`long`的取值范围内时，使用`long`类型。另外需要注意：如果在`long`类型和`int`类型占用空间相同的机器上编写代码，当确实需要32位整数时，应使用`long`类型而不是`int`类型，以便把程序移植到16位机后仍然可以正常工作。

## 使用哪些可移植的数据类型可以获得32位有符号整数？选择的理由是什么？
查阅附录B.6 参考资料VI：扩展的整数类型

如果需要正好获得32位的整数，选择`int32_t`类型  
如果要保证至少可以储存32位整数的最小类型，选择`int32_least_t`类型  
如果要为32位整数提供最快的计算速度，选择`int32_fast_t`类型

> 如果某系统的最小整数类型是16位，可能不会定义`int8_t`类型。尽管如此，该系统仍可使用`int8_least_t`类型，但可能把该类型实现为16位的整数类型。

## 指出下列常量的类型和含义（如果有的话）
> a. '\b'  
> b. 1066  
> c. 99.44  
> d. 0XAA  
> e. 2.0e30

a. `char`类型，储存为`int`类型，含义为转义序列中的*回退符*

b. `int`类型，整型常量

c. `double`类型，双精度浮点型常量

d. ~~`int`类型~~ `unsigned int`类型，整型常量，用16进制表示

e. `double`，双精度浮点型常量，用指数形式表示

## Dottie Cawm编写了一个程序，请找出程序中的错误。
```c
include <stdio.h>
main
(
    float g; h;
    float tax, rate;

    g = e21;
    tax = rate * g;
)
```
该程序有多处错误：

1. `include`前应加`#`
2. 将`main`函数体的内容错误地写到了参数中，应改为`int main(void){}`
3. 声明多个浮点型变量方法错误，多个变量的应为`,`而不是`;`，改为`float g,h;`
4. `e21`不是一个有效的浮点型常量，因为**指数前面的数字不可省略** ，故无法赋值给`g`
5. `main()`函数类型为`int`，需要提供返回值，在程序结尾要加上`return 0;`

修改后的程序为：
```c
#include <stdio.h>
int main(void)
{
    float g, h;
    float tax, rate;

    g = 1e21;   //答案中给出的参考数字
    tax = race * g;

    return 0;
}
```
> 答案附加：除此之外，还缺少一些内容。首先，没有给`rate`变量赋值；其次未使用`h`变量；而且程序不会报告计算结果。虽然这些错误不会影响程序的运行（编译器可能给出变量未使用的警告），但是它们确实与程序设计的初衷不符合。另外，在该程序的末尾应该有一个return语句。

## 写出下列常量在声明中使用的数据类型和在`printf()`中对应的转换说明：
常量 | 类型 | 转换说明（%转换字符）
:----|:----|:----
12|int|%d
0X3|~~int~~ unsigned int|~~%x~~ %#x
'c'|char（实际上是int）|%c
2.34E07|double|%e
'\040'|char（实际上是int）|%c
7.0|double|%f
6L|long|%ld
6.0f|float|%f
0x5.b6p12|~~double~~ float|%a

## 写出下列常量在声明中使用的数据类型和在`printf()`中对应的转换说明（假设`int`为16位）
常量 | 类型 | 转换说明（%转换字符）
:---|:-----|:-------------------
012|unsigned int|%#o
2.9e05L|~~long~~ long double|~~%ld~~ %Le *（VS2015测试*`%le`*也可以）*
's'|char（实际上是int）|%c
100000|long|%ld
'\n'|char（实际上是int）|%c
20.0f|float|%f
0x44|unsigned int|%#x
-40|int|%d

## 假设程序的开头有下列声明：
```c
int imate = 2;
long shot = 53456;
char grade = 'A';
float log = 2.71828;
```
把下面`printf()`语句中的转换字符补充完整：
```c
printf("The odds against the %d were %ld to 1.\n", imate, shot);
printf("A score of %f is not an %c grade.\n", log, grade);
```

## 假设`ch`是`char`类型的变量。分别使用转义序列、十进制值、八进制字符常量和十六进制字符常量把回车字符赋给`ch`（假设使用ASCII编码值）。
```c
char ch = '\n';
int ch = 10;
unsigned int ch = 012;
unsigned int ch= 0x0a;
```
注：以上代码理解错了题意，回车符为`\r`，对应ASCII值为13，`\n`为换行符，对应ASCII值为10。另外，题目中已明确指出`ch`为`char`类型的变量，直接赋值即可，无须重新声明

修改后的代码为：
```c
ch = '\r';
ch = 13;
ch = '\015';
ch = '\xd'
```
> 用十六进制形式表示字符常量时，反斜杠后面跟一个x或X，再加上1~3位十六进制数字。中英文书上图/Figure 3.5表格内容均有误，char类型十六进制应为`\x41`或者`\x041`而不是`\0x41`

## 修正下面的程序（在C中，/表示除以）。
```c
void main(int)  / this program is perfect /
{
    cows, legs integer;
    printf("How many cow legs did you count?\n);
    scanf("%c", legs);
    cows = legs / 4;
    printf("That implies there are %f cows.\n",cows)
}
```
该程序有多处错误，尽管在错误的注释中说它是完美的:cold_sweat:

1. `main()`函数书写错误，应改为`int main(void)`
2. “完美注释”符号错误，应改为`/* this program is rubbish */`:joy:
3. 声明变量方式错误，应改为`int cows, legs`
4. 第一个`printf()`函数内的参数只打出了一个`"`，补全，即`printf("How many cow legs did you count?\n");`
5. `scanf()`函数用法错误，`legs`前应加上`&`指示地址，即`scanf("%c", &legs);`
6. 第二个`printf()`语句中参数和值的类型不匹配，`cow`为`int`类型，不能用`%f`，要使用`%d`
7. 程序结尾缺少`return`语句

修改后的程序为：
```c
int main()  /* let me show you what is perfect */
{
    int cows, legs;
    printf("How many cow legs did you count?\n")
    scanf("%c", &legs);
    cows = legs / 4;
    printf("That implies there are %d cows.\n", cows);

    return 0;
}
```

## 指出下列转义序列的含义：
> a. \n  
> b. \\\  
> c. \"  
> d. \t  

`\n`为换行符，`\\`为反斜杠字符（\）本身，`\"`为双引号字符（"），`\t`为制表符。
