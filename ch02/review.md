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
3. int s后缺失分号
4. 查了一下没有`:=`的用法，赋值直接用`=`
5. 
