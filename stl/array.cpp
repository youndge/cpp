#include <array>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * array容器成员函数
 * 成员函数	功能
begin()	返回指向容器中第一个元素的随机访问迭代器。
end()	返回指向容器最后一个元素之后一个位置的随机访问迭代器，通常和 begin() 结合使用。
rbegin()	返回指向最后一个元素的随机访问迭代器。
rend()	返回指向第一个元素之前一个位置的随机访问迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上增加了 const 属性，不能用于修改元素。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
size()	返回容器中当前元素的数量，其值始终等于初始化 array 类的第二个模板参数 N。
max_size()	返回容器可容纳元素的最大数量，其值始终等于初始化 array 类的第二个模板参数 N。
empty()	判断容器是否为空，和通过 size()==0 的判断条件功能相同，但其效率可能更快。
at(n)	返回容器中 n 位置处元素的引用，该函数自动检查 n 是否在有效的范围内，如果不是则抛出 out_of_range 异常。
front()	返回容器中第一个元素的直接引用，该函数不适用于空的 array 容器。
back()	返回容器中最后一个元素的直接应用，该函数同样不适用于空的 array 容器。
data()	返回一个指向容器首个元素的指针。利用该指针，可实现复制容器中所有元素等类似功能。
fill(val)	将 val 这个值赋值给容器中的每个元素。
array1.swap(array2)	交换 array1 和 array2 容器中的所有元素，但前提是它们具有相同的长度和类型。

*/

/**
 * 基础1.遍历
*/
void printValue(string str){
    cout << str << " ";
}
void arrTraverse(){
    std::array<std::string,5> str {"hello","how","is","you"};
    //way1
    auto start = str.begin();
    auto end = str.end();
    while (start != end){
        if ("is" == *start){
            *start = "are";
        }
        cout << *start << " ";
        start++;
    }
    cout << endl;
   // way2
    for (auto it = str.cbegin();it < str.cend();it ++){
        cout << *it << " ";
        //const无法修改
        // if ("are" == *it){
        //     *it = "is";
        // }
    }
    cout << endl;
    //way3
    for_each(str.crbegin(),str.crend(),printValue);


}
/**
 * 基础2.访问容器中元素
*/
void arrAcess(){
        array<int, 5> values1;
    array<int, 5> values2;
    //初始化 values1 为 {0,1,2,3,4}
    for (size_t i = 0; i < values1.size(); ++i)
    {
        values1.at(i) = i;
    }
    cout << "values1[0] is : " << values1[0] << endl;     //way1
    cout << "values1[1] is : " << values1.at(1) << endl;  //way2
    cout << "values1[2] is : " << get<2>(values1) << endl;//way3
    //初始化 values2 为{10，11，12，13，14}
    int initvalue = 10;
    for (auto& value : values2) //way4
    {
        value = initvalue;
        initvalue++;
    }
    cout <<  "Values1 is : ";
    for (auto i = values1.begin(); i < values1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl << "Values2 is : ";
    for (auto i = values2.begin(); i < values2.end(); i++) {
        cout << *i << " ";
    }
}

/**
 * 提升1.array容器重载了全局get()函数
*/
void arrGet(){
    std::array<int,5> arr {7,8,9,12};
    std::cout<< std::get<1> (arr) << std::endl;
}
/**
 * 提升2 array和vector的区别？为什么array是普通数组的升级版？
*/


int main(){
    //arrTraverse();
    arrAcess();

    //arrGet();
    return 0;
}