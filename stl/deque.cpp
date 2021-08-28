#include <deque>
#include <array>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * 特点:deque 是 double-ended queue 的缩写，又称双端队列容器。

前面章节中，我们已经系统学习了 vector 容器，值得一提的是，deque 容器和 vecotr 容器有很多相似之处，比如：
deque 容器也擅长在序列尾部添加或删除元素（时间复杂度为O(1)），而不擅长在序列中间添加或删除元素。
deque 容器也可以根据需要修改自身的容量和大小。

和 vector 不同的是，deque 还擅长在序列头部添加或删除元素，所耗费的时间复杂度也为常数阶O(1)。并且更重要的一点是，deque 容器中存储元素并不能保证所有元素都存储到连续的内存空间中。
当需要向序列两端频繁的添加或删除元素时，应首选 deque 容器。

deque 容器以模板类 deque<T>（T 为存储元素的类型）的形式在 <deque> 头文件中，并位于 std 命名空间中。因此，在使用该容器之前，代码中需要包含下面两行代码：
纯文本复制
#include <deque>
using namespace std;
 * 
 * 函数成员	函数功能
begin()	返回指向容器中第一个元素的迭代器。
end()	返回指向容器最后一个元素所在位置后一个位置的迭代器，通常和 begin() 结合使用。
rbegin()	返回指向最后一个元素的迭代器。
rend()	返回指向第一个元素所在位置前一个位置的迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
size()	返回实际元素个数。
max_size()	返回容器所能容纳元素个数的最大值。这通常是一个很大的值，一般是 232-1，我们很少会用到这个函数。
resize()	改变实际元素的个数。
empty()	判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。
shrink _to_fit()	将内存减少到等于当前元素实际所使用的大小。
at()	使用经过边界检查的索引访问元素。
front()	返回第一个元素的引用。
back()	返回最后一个元素的引用。
assign()	用新元素替换原有内容。
push_back()	在序列的尾部添加一个元素。
push_front()	在序列的头部添加一个元素。
pop_back()	移除容器尾部的元素。
pop_front()	移除容器头部的元素。
insert()	在指定的位置插入一个或多个元素。
erase()	移除一个元素或一段元素。
clear()	移出所有的元素，容器大小变为 0。
swap()	交换两个容器的所有元素。
emplace()	在指定的位置直接生成一个元素。
emplace_front()	在容器头部生成一个元素。和 push_front() 的区别是，该函数直接在容器头部构造元素，省去了复制移动元素的过程。
emplace_back()	在容器尾部生成一个元素。和 push_back() 的区别是，该函数直接在容器尾部构造元素，省去了复制移动元素的过程。
*/

void printDeque(deque<int> d){
    for (auto it = d.cbegin();it < d.cend();it ++){
        cout << *it<< " ";
    }
    cout << endl;
}
/**
 * 基础1.deque创建的几种方式
*/
void dequeContructor(){
    //way1
    deque<int> d0;
    deque<int> d1 {5,4,3};
    printDeque(d1);
    //way2
    deque<int> d2(5);
    printDeque(d2);
    //way3
    deque<int> d3(5,10);
    printDeque(d3);
    //way4
    deque<int> d4(d2);
    printDeque(d4);
    //way5
    array<int,5> arr {11,22,33,44,55};
    deque<int> d5(arr.data()+2,arr.data()+4);
    printDeque(d5);
}
/**基础3
 *@brief deque遍历的几种方法  cbegin(),cend()同理，rbegin(),rend()反向迭代器 
 * 
*/
void printValue(int value){
    cout << value << " ";
}
void dequeTraverse() {
    deque<int> d1 {5,6,7,8,9};
    //way1
    auto it = d1.cbegin();
    while (it != d1.cend())
    {
        cout << *it << " ";
        it ++;
    }
    cout << endl;
    //way2
    for (auto it = d1.rbegin(); it < d1.rend();it ++){
        if (*it == 7){
            *it =88;
        }
        cout << *it << " ";
    }
    cout << endl;
    //way3
    for (auto value : d1){
        cout << value << " ";
    }
    cout << endl;
    //way4
    for_each(d1.crbegin(),d1.crend(),printValue); 
    cout << endl;

}
/**
 * 基础4.访问容器中的元素
*/
void dequeAcess(){
    deque<int> d {5,6,7,8,9};
    cout << d[2] << endl; //way1
    d.at(3) = 99;         //way2
    cout << d.front() << "~" << d.back() << endl; //way3
    //cout << d.data() << endl;  deque没有data();
}
/**
 * 基础5.插入和删除
*/
void dequeInsertDelete(){
/**
 * 表 1 和添加或删除deque容器中元素相关的成员函数
成员函数	功能
push_back()	在容器现有元素的尾部添加一个元素，和 emplace_back() 不同，该函数添加新元素的过程是，先构造元素，然后再将该元素移动或复制到容器的尾部。
pop_back()	移除容器尾部的一个元素。
push_front()	在容器现有元素的头部添加一个元素，和 emplace_back() 不同，该函数添加新元素的过程是，先构造元素，然后再将该元素移动或复制到容器的头部。
pop_front()	移除容器尾部的一个元素。
emplace_back()	C++ 11 新添加的成员函数，其功能是在容器尾部生成一个元素。和 push_back() 不同，该函数直接在容器头部构造元素，省去了复制或移动元素的过程。
emplace_front()	C++ 11 新添加的成员函数，其功能是在容器头部生成一个元素。和 push_front() 不同，该函数直接在容器头部构造元素，省去了复制或移动元素的过程。
insert()	在指定的位置直接生成一个元素。和 emplace() 不同的是，该函数添加新元素的过程是，先构造元素，然后再将该元素移动或复制到容器的指定位置。
emplace()	C++ 11 新添加的成员函数，其功能是 insert() 相同，即在指定的位置直接生成一个元素。和 insert() 不同的是，emplace() 直接在容器指定位置构造元素，省去了复制或移动元素的过程。
erase()	移除一个元素或某一区域内的多个元素。
clear()	删除容器中所有的元素。
*/
    deque<int>d;
    //调用push_back()向容器尾部添加数据。
    d.push_back(2); //{2}
    //调用pop_back()移除容器尾部的一个数据。
    d.pop_back(); //{}
    //调用push_front()向容器头部添加数据。
    d.push_front(2);//{2}
    //调用pop_front()移除容器头部的一个数据。
    d.pop_front();//{}
    //调用 emplace 系列函数，向容器中直接生成数据。
    d.emplace_back(2); //{2}
    d.emplace_front(3); //{3,2}
    //emplace() 需要 2 个参数，第一个为指定插入位置的迭代器，第二个是插入的值。
    d.emplace(d.begin() + 1, 4);//{3,4,2}
    for (auto i : d) {
        cout << i << " ";
    }
    //erase()可以接受一个迭代器表示要删除元素所在位置
    //也可以接受 2 个迭代器，表示要删除元素所在的区域。
    d.erase(d.begin());//{4,2}
    d.erase(d.begin(), d.end());//{}，等同于 d.clear()
/**
 * 表 2 insert() 成员函数语法格式
语法格式	功能
iterator insert(pos,elem)	在迭代器 pos 指定的位置之前插入一个新元素elem，并返回表示新插入元素位置的迭代器。
iterator insert(pos,n,elem)	在迭代器 pos 指定的位置之前插入 n 个元素 elem，并返回表示第一个新插入元素位置的迭代器。
iterator insert(pos,first,last) 	在迭代器 pos 指定的位置之前，插入其他容器（不仅限于vector）中位于 [first,last) 区域的所有元素，并返回表示第一个新插入元素位置的迭代器。
iterator insert(pos,initlist)	在迭代器 pos 指定的位置之前，插入初始化列表（用大括号{}括起来的多个元素，中间有逗号隔开）中所有的元素，并返回表示第一个新插入元素位置的迭代器。
*/
    std::deque<int> d2{ 1,2 };
    //第一种格式用法
    d2.insert(d2.begin() + 1, 3);//{1,3,2}
    //第二种格式用法
    d2.insert(d2.end(), 2, 5);//{1,3,2,5,5}
    //第三种格式用法
    std::array<int, 3>test{ 7,8,9 };
    d2.insert(d2.end(), test.begin(), test.end());//{1,3,2,5,5,7,8,9}
    //第四种格式用法
    d2.insert(d2.end(), { 10,11 });//{1,3,2,5,5,7,8,9,10,11}
    for (int i = 0; i < d2.size(); i++) {
        cout << d2.at(i) << " ";
    }
    cout << endl;
}

/**
 * 提升1.深度剖析deque底层实现原理
*/
/**
 * 
*/
int main(){
    // dequeContructor();
    // dequeTraverse();
    dequeInsertDelete();
    return 0;
}