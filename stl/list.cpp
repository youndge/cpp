#include <iostream>
#include <list>
#include <array>
#include <algorithm>
#include <string>
using namespace std;

/**
 * 特点：list底层是双向链表容器
 * 优点：插入，删除，移动元素优于array，vector，deque；
 * 缺点：遍历不如array,vector,deque,没有list[]和at()，只能从头遍历；
 * 场景：实际场景中，如何需要对序列进行大量添加或删除元素的操作，而直接访问元素的需求却很少，这种情况建议使用 list 容器存储序列。
*/
/**
 * 基础1.创建list
*/
void printList(list<int> l){
    for (auto it = l.cbegin(); it != l.cend();it ++){
        cout << *it << " ";
    }
    cout << endl;
}
void printStrList(list<string> l){
    for (auto it = l.cbegin(); it != l.cend();it ++){
        cout << *it << " ";
    }
    cout << endl;
}
void createList(){
    //way1
    list<int> l0;
    list<int> l1 {5,6,7,8,9};
    printList(l1);
    //way2
    list<int> l2(5);
    printList(l2);
    //way3
    list<int> l3(5,10);
    printList(l3);
    //way4
    list<int> l4(l2);
    printList(l4);
    //way5
    array<int,5> arr {11,22,33,44,55};
    list<int> l5(arr.cbegin()+2,arr.cend());
    printList(l5);
}
/**
 * list成员函数
 * 表 2 list 容器可用的成员函数
成员函数	功能
begin()	返回指向容器中第一个元素的双向迭代器。
end()	返回指向容器中最后一个元素所在位置的下一个位置的双向迭代器。
rbegin()	返回指向最后一个元素的反向双向迭代器。
rend()	返回指向第一个元素所在位置前一个位置的反向双向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crbegin() 	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
empty()	判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。
size()	返回当前容器实际包含的元素个数。
max_size()	返回容器所能包含元素个数的最大值。这通常是一个很大的值，一般是 232-1，所以我们很少会用到这个函数。
front()	返回第一个元素的引用。
back()	返回最后一个元素的引用。
assign()	用新元素替换容器中原有内容。
emplace_front()	在容器头部生成一个元素。该函数和 push_front() 的功能相同，但效率更高。
push_front()	在容器头部插入一个元素。
pop_front()	删除容器头部的一个元素。
emplace_back()	在容器尾部直接生成一个元素。该函数和 push_back() 的功能相同，但效率更高。
push_back()	在容器尾部插入一个元素。
pop_back()	删除容器尾部的一个元素。
emplace()	在容器中的指定位置插入元素。该函数和 insert() 功能相同，但效率更高。
insert() 	在容器中的指定位置插入元素。
erase()	删除容器中一个或某区域内的元素。
swap()	交换两个容器中的元素，必须保证这两个容器中存储的元素类型是相同的。
resize()	调整容器的大小。
clear()	删除容器存储的所有元素。
splice()	将一个 list 容器中的元素插入到另一个容器的指定位置。
remove(val)	删除容器中所有等于 val 的元素。
remove_if()	删除容器中满足条件的元素。
unique()	删除容器中相邻的重复元素，只保留一个。
merge()	合并两个事先已排好序的 list 容器，并且合并之后的 list 容器依然是有序的。
sort()	通过更改容器中元素的位置，将它们进行排序。
reverse()	反转容器中元素的顺序。
*/
/**
 * 基础2.list遍历
 * 迭代器的使用：
 * 表 1 list 容器迭代器函数
迭代器函数	功能
begin()	返回指向容器中第一个元素的双向迭代器（正向迭代器）。
end()	返回指向容器中最后一个元素所在位置的下一个位置的双向迭代器。（正向迭代器）。
rbegin() 	返回指向最后一个元素的反向双向迭代器。
rend()	返回指向第一个元素所在位置前一个位置的反向双向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，正向迭代器增加了 const 属性，即不能用于修改元素。
cend()	和 end() 功能相同，只不过在其基础上，正向迭代器增加了 const 属性，即不能用于修改元素。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，反向迭代器增加了 const 属性，即不能用于修改元素。
crend()	和 rend() 功能相同，只不过在其基础上，反向迭代器增加了 const 属性，即不能用于修改元素。
*
*list是双向迭代器，与随机迭代器的区别：
前面章节已经详细介绍了 array、vector、deque 容器的迭代器，和它们相比，list 容器迭代器最大的不同在于，其配备的迭代器类型为双向迭代器，而不再是随机访问迭代器。
这意味着，假设 p1 和 p2 都是双向迭代器，则它们支持使用 ++p1、 p1++、 p1--、 p1++、 *p1、 p1==p2 以及 p1!=p2 运算符，但不支持以下操作（其中 i 为整数）：
p1[i]：不能通过下标访问 list 容器中指定位置处的元素。
p1-=i、 p1+=i、 p1+i 、p1-i：双向迭代器 p1 不支持使用 -=、+=、+、- 运算符。
p1<p2、 p1>p2、 p1<=p2、 p1>=p2：双向迭代器 p1、p2 不支持使用 <、 >、 <=、 >= 比较运算符。
*/
void printValue(int value){
    cout << value << " ";
}
void listTraverse(){
    list<int> l {11,22,33,44,55};
    //way1
    auto it = l.cbegin();
    while (it != l.cend())
    {
        cout<< *it << " ";
        it++;
    }
    cout << endl;
    //way2
    for (auto it = l.crbegin(); it != l.crend(); ++ it){
        cout << *it << " ";
    }
    cout << endl;
    //way3
    for_each(l.rbegin(),l.rend(),printValue);
    cout << endl;
    //way4
    for(auto value : l){
        cout << value << " ";
    }
    cout << endl;
    //way5
    for_each(begin(l),end(l),printValue);
    cout << endl;
}
/**
 * 基础3.访问容器中元素
 * list 容器不支持随机访问，未提供下标操作符 [] 和 at() 成员函数，也没有提供 data() 成员函数。
*/
void listGet(){
    list<int> l {11,22,33,44,55};
    //way1 非迭代器方式
    l.back() = 99;
    cout << l.front()<<"~"<<l.back()<<endl;
    //way2 assign()

    //way3 迭代器方式
    auto it = l.begin();
    while (*it == 33)
    {
        *it = 88;
    }
    printList(l);
}
/**
 * 基础4.list中插入和删除元素
 * 1.list 模板类中，与“添加或插入新元素”相关的成员方法有如下几个：
push_front()：向 list 容器首个元素前添加新元素；
push_back()：向 list 容器最后一个元素后添加新元素；
emplace_front()：在容器首个元素前直接生成新的元素；
emplace_back()：在容器最后一个元素后直接生成新的元素；
emplace()：在容器的指定位置直接生成新的元素；
insert()：在指定位置插入新元素；
splice()：将其他 list 容器存储的多个元素添加到当前 list 容器的指定位置处。
以上这些成员方法中，除了 insert() 和 splice() 方法有多种语法格式外，其它成员方法都仅有 1 种语法格式，下面程序演示了它们的具体用法。
 * 
 *2.insert()成员方法：
 表 1 insert() 成员方法语法格式
语法格式	用法说明
iterator insert(pos,elem)	在迭代器 pos 指定的位置之前插入一个新元素 elem，并返回表示新插入元素位置的迭代器。
iterator insert(pos,n,elem)	在迭代器 pos 指定的位置之前插入 n 个元素 elem，并返回表示第一个新插入元素位置的迭代器。
iterator insert(pos,first,last) 	在迭代器 pos 指定的位置之前，插入其他容器（例如 array、vector、deque 等）中位于 [first,last) 区域的所有元素，并返回表示第一个新插入元素位置的迭代器。
iterator insert(pos,initlist)	在迭代器 pos 指定的位置之前，插入初始化列表（用大括号 { } 括起来的多个元素，中间有逗号隔开）中所有的元素，并返回表示第一个新插入元素位置的迭代器。
* 
*3.splice()成员方法：
和 insert() 成员方法相比，splice() 成员方法的作用对象是其它 list 容器，其功能是将其它 list 容器中的元素添加到当前 list 容器中指定位置处。
splice() 成员方法的语法格式有 3 种，如表 2 所示。
表 2 splice() 成员方法的用法
语法格式	功能
void splice (iterator position, list& x);	position 为迭代器，用于指明插入位置；x 为另一个 list 容器。
此格式的 splice() 方法的功能是，将 x 容器中存储的所有元素全部移动当前 list 容器中 position 指明的位置处。
void splice (iterator position, list& x, iterator i);	position 为迭代器，用于指明插入位置；x 为另一个 list 容器；i 也是一个迭代器，用于指向 x 容器中某个元素。
此格式的 splice() 方法的功能是将 x 容器中 i 指向的元素移动到当前容器中 position 指明的位置处。
void splice (iterator position, list& x, iterator first, iterator last);	position 为迭代器，用于指明插入位置；x 为另一个 list 容器；first 和 last 都是迭代器，[fist,last) 用于指定 x 容器中的某个区域。
此格式的 splice() 方法的功能是将 x 容器 [first, last) 范围内所有的元素移动到当前容器 position 指明的位置处。
*/
void listInsertDel(){
    //1.通用方法
    std::list<int> values{1,2,3};
    values.push_front(0);//{0,1,2,3}
    values.push_back(4); //{0,1,2,3,4}
    values.emplace_front(-1);//{-1,0,1,2,3,4}
    values.emplace_back(5);  //{-1,0,1,2,3,4,5}
    //emplace(pos,value),其中 pos 表示指明位置的迭代器，value为要插入的元素值
    values.emplace(values.end(), 6);//{-1,0,1,2,3,4,5,6}
    for (auto p = values.begin(); p != values.end(); ++p) {
        cout << *p << " ";
    }
}
void listInsert(){
        std::list<int> values{ 1,2 };
    //第一种格式用法
    values.insert(values.begin() , 3);//{3,1,2}
    //第二种格式用法
    values.insert(values.end(), 2, 5);//{3,1,2,5,5}
    //第三种格式用法
    std::array<int, 3>test{ 7,8,9 };
    values.insert(values.end(), test.begin(), test.end());//{3,1,2,5,5,7,8,9}
    //第四种格式用法
    values.insert(values.end(), { 10,11 });//{3,1,2,5,5,7,8,9,10,11}
    for (auto p = values.begin(); p != values.end(); ++p)
    {
        cout << *p << " ";
    }
}
void listSplice(){
    //创建并初始化 2 个 list 容器
    list<int> mylist1{ 1,2,3,4 }, mylist2{10,20,30};
    list<int>::iterator it = ++mylist1.begin(); //指向 mylist1 容器中的元素 2
   
    //调用第一种语法格式
    mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                 // mylist2:
                                 // it 迭代器仍然指向元素 2，只不过容器变为了 mylist1
    //调用第二种语法格式，将 it 指向的元素 2 移动到 mylist2.begin() 位置处
    mylist2.splice(mylist2.begin(), mylist1, it);   // mylist1: 1 10 20 30 3 4
                                                    // mylist2: 2
                                                    // it 仍然指向元素 2
   
    //调用第三种语法格式，将 [mylist1.begin(),mylist1.end())范围内的元素移动到 mylist.begin() 位置处                  
    mylist2.splice(mylist2.begin(), mylist1, mylist1.begin(), mylist1.end());//mylist1:
                                                                             //mylist2:1 10 20 30 3 4 2
   
    cout << "mylist1 包含 " << mylist1.size() << "个元素" << endl;
    cout << "mylist2 包含 " << mylist2.size() << "个元素" << endl;
    //输出 mylist2 容器中存储的数据
    cout << "mylist2:";
    for (auto iter = mylist2.begin(); iter != mylist2.end(); ++iter) {
        cout << *iter << " ";
    }
}
/**
 * 4.list删除元素
 * 对 list 容器存储的元素执行删除操作，需要借助该容器模板类提供的成员函数。幸运的是，相比其它 STL 容器模板类，list 模板类提供了更多用来实现此操作的成员函数（如表 1 所示）。
表 1 实现 list 容器删除元素的成员函数
成员函数	功能
pop_front()	删除位于 list 容器头部的一个元素。
pop_back()	删除位于 list 容器尾部的一个元素。
erase()	该成员函数既可以删除 list 容器中指定位置处的元素，也可以删除容器中某个区域内的多个元素。
clear()	删除 list 容器存储的所有元素。
remove(val)	删除容器中所有等于 val 的元素。
unique()	删除容器中相邻的重复元素，只保留一份。
remove_if()	删除容器中满足条件的元素。
其中，pop_front()、pop_back() 和 clear() 的用法非常简单，这里仅给出一个样例，不再过多解释：
*/
void listDelete1(){
    list<int>values{ 1,2,3,4 };
    //删除当前容器中首个元素
    values.pop_front();//{2,3,4}
    //删除当前容器最后一个元素
    values.pop_back();//{2,3}
    //清空容器，删除容器中所有的元素
    values.clear(); //{}
    printList(values);
}
/**
 * erase() 成员函数有以下 2 种语法格式：
iterator erase (iterator position);
iterator erase (iterator first, iterator last);
*/
void listDelete2(){
    list<int> l {5,6,7,8,9};
    l.erase(++l.begin());
    printList(l);
    l.erase(++l.cbegin(),--l.cbegin());
    printList(l);
    //remove()
    list<string> l2 {"how","is","are","is","you"};
    l2.remove("is");
    printStrList(l2);
    //remove_if()
    std::list<int> l3{ 15, 36, 7, 17, 20, 39, 4, 1 };
    //删除 mylist 容器中能够使 lamba 表达式成立的所有元素。
    l3.remove_if([](int value) {return (value < 10); }); //{15 36 17 20 39}
    printList(l3);
}
/**
 * unique() 函数也有以下 2 种语法格式：
void unique()
void unique（BinaryPredicate）//传入一个二元谓词函数
以上 2 种格式都能实现去除 list 容器中相邻重复的元素，仅保留一份。但第 2 种格式的优势在于，我们能自定义去重的规则，例如：
*/
//二元谓词函数
bool demo(double first, double second)
{
    return (int(first) == int(second));
}
void listUnique(){
    list<double> mylist{ 1,1.2,1.2,3,4,4.5,4.6 };
    //1.删除相邻重复的元素，仅保留一份  remove()全移除
    mylist.unique();//{1, 1.2, 3, 4, 4.5, 4.6}
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << *it << ' ';
    cout << endl;
    //2.demo 为二元谓词函数，是我们自定义的去重规则
    mylist.unique(demo);
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        std::cout << *it << ' ';
}
/**
 * 提升1.list容器底层存储结构
*/
int main(){
    // createList();
    // listTraverse();
    // listGet();
    // listInsertDel();
    // listInsert();
    // listSplice();
    // listDelete1();
    listDelete2();
    listUnique();
    return 0;
}