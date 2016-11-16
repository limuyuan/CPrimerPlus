## 指出下面各种数据使用的合适数据类型（有些可使用多种数据类型）：
> a. East Simpleton的人口  
> b. DVD影碟的价格  
> c. 本章出现次数最多的字母  
> d. 本章出现次数最多的字母次数  

a. 根据地域大小，32767人及以内可用`short`，65535人及以内可用`unsigned short`，65535人以上可用`int`

b. ~~考虑到货币单位不同，选择`unsigned short`类型可尽可能降低溢出风险~~  
价格通常不是一个整数，对精度要求也不高，可以选择`float`类型。**C语言中无`unsigned float`！！！**参见：StackOverflow：[Why doesn't C have unsigned floats?](http://stackoverflow.com/questions/512022/why-doesnt-c-have-unsigned-floats)

c. 选择`char`储存字符

d. 节省存储空间，选择`unsigned short`
