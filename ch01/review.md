## 对编程而言，*可移植性*意味着什么？
可移植性意味着在一种系统中编写的程序稍作修改或者不修改就能在其他系统中运行。

## 解释源代码文件(source code file)、目标代码文件(object code file)和可执行文件(executable file)有什么区别？
源代码文件(source code file)：用C语言编写程序时，编写的内容被存储在文本文件中，该文件被称为源代码文件。

目标代码文件(object code file)、可执行文件(executable file)：
* 编译器把源代码转换成中间(intermediate)代码，链接器把中间代码和其他代码合并，生成可执行文件。  
* 中间文件有多种形式，最普遍的一种形式是，把源代码转换为机器语言代码，并把结果放在目标代码文件(object code file)，简称目标文件(object file)中。  
* 虽然目标文件中包含机器语言代码，但是并不能直接运行，因为目标文件中储存的是编译器翻译的源代码，还不是一个完整的程序（缺失启动代码和库函数）。通过链接器，把编写的目标代码、系统的标准启动代码和库代码这三部分合并成一个文件，才生成了最终的可执行文件(executable file)。

**目标文件中只包含编译器为你编写的代码翻译的机器语言代码，可执行文件中还包含你编写的程序中使用的库函数和启动代码的机器代码。**
>However, the object file contains the machine language translation only for the code you used, but
the executable file also has machine code for the library routines you use and for the startup code.

## 编程的7个主要步骤是什么？
>1. 定义程序的目标
2. 设计程序
3. 编写代码
4. 编译
5. 运行程序
6. 测试和调试程序
7. 维护和修改程序

## 编译器的任务是什么？
编译器把高级语言程序源代码翻译成计算机能理解的机器语言指令代码（目标代码）。

## 链接器的任务是什么？
链接器的把目标代码、库函数
