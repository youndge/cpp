#include<iostream>

using namespace std;

/**
 * 1.迭代器分类
 * 1) 前向迭代器（forward iterator）
假设 p 是一个前向迭代器，则 p 支持 ++p，p++，*p 操作，还可以被复制或赋值，可以用 == 和 != 运算符进行比较。此外，两个正向迭代器可以互相赋值。

2) 双向迭代器（bidirectional iterator）
双向迭代器具有正向迭代器的全部功能，除此之外，假设 p 是一个双向迭代器，则还可以进行 --p 或者 p-- 操作（即一次向后移动一个位置）。

3) 随机访问迭代器（random access iterator）
随机访问迭代器具有双向迭代器的全部功能。除此之外，假设 p 是一个随机访问迭代器，i 是一个整型变量或常量，则 p 还支持以下操作：
p+=i：使得 p 往后移动 i 个元素。
p-=i：使得 p 往前移动 i 个元素。
p+i：返回 p 后面第 i 个元素的迭代器。
p-i：返回 p 前面第 i 个元素的迭代器。
p[i]：返回 p 后面第 i 个元素的引用。

此外，两个随机访问迭代器 p1、p2 还可以用 <、>、<=、>= 运算符进行比较。另外，表达式 p2-p1 也是有定义的，其返回值表示 p2 所指向元素和 p1 所指向元素的序号之差（也可以说是 p2 和 p1 之间的元素个数减一）。

4）输入迭代器
5）输出迭代器
*/
/**
 * 2.容器和迭代器
 * 表 不同容器的迭代器（C++11）
容器	对应的迭代器类型
array	随机访问迭代器
vector	随机访问迭代器
deque	随机访问迭代器
list	双向迭代器
set / multiset	双向迭代器
map / multimap	双向迭代器
forward_list	前向迭代器
unordered_map / unordered_multimap	前向迭代器
unordered_set / unordered_multiset	前向迭代器
stack	不支持迭代器
queue	不支持迭代器
*/
/**
 * 3.迭代器的定义方式
 * 尽管不同容器对应着不同类别的迭代器，但这些迭代器有着较为统一的定义方式，具体分为 4 种，如表 1 所示。

表 2 迭代器的 4 种定义方式
迭代器定义方式	具体格式
正向迭代器	容器类名::iterator  迭代器名;
常量正向迭代器	容器类名::const_iterator  迭代器名;
反向迭代器	容器类名::reverse_iterator  迭代器名;
常量反向迭代器	容器类名::const_reverse_iterator  迭代器名;
值得一提的是，表 2 中的反向迭代器全称为 "反向迭代器适配器"，后续章节会做详细讲解，这里读者只需要知道其用法即可。

通过定义以上几种迭代器，就可以读取它指向的元素，*迭代器名就表示迭代器指向的元素。其中，常量迭代器和非常量迭代器的分别在于，通过非常量迭代器还能修改其指向的元素。另外，反向迭代器和正向迭代器的区别在于：
对正向迭代器进行 ++ 操作时，迭代器会指向容器中的后一个元素；
而对反向迭代器进行 ++ 操作时，迭代器会指向容器中的前一个元素。

注意，以上 4 种定义迭代器的方式，并不是每个容器都适用。有一部分容器同时支持以上 4 种方式，比如 array、deque、vector；而有些容器只支持其中部分的定义方式，例如 forward_list 容器只支持定义正向迭代器，不支持定义反向迭代器。
具体容器支持定义迭代器的方式，讲具体容器时会详细说明。另外，读者也可以通过 C++ STL标准手册（http://www.cplusplus.com/reference/stl/），查询具体容器迭代器支持的定义方式。
*/
int main(){
    cout << "hello, iterator!"<<endl;
    return 0;
}