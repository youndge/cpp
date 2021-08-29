#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;
/**
 * 前述：
 * 1.map存储的都是pair对象，键值各自可以是任何类型，通常大多数是string；
 * 2.map会默认或按指定规则排序；
 * 3.map中键的值被const修饰，既不能重复也不能修改；
 * 4.模版声明：
 * template < class Key,                                     // 指定键（key）的类型
           class T,                                       // 指定值（value）的类型
           class Compare = less<Key>,                     // 指定排序规则
           class Alloc = allocator<pair<const Key,T> >    // 指定分配器对象的类型
           > class map;
map 容器模板有 4 个参数，其中后 2 个参数都设有默认值。大多数场景中，我们只需要设定前 2 个参数的值，有些场景可能会用到第 3 个参数，
但最后一个参数几乎不会用到。
*/

/**
 * 基础1.创建map
*/
void createMap(){
    //way1
    map<string,string> m0 ;
    map<string,string> m1 {{"name","tony"},{"age","20"}};
    // map<string,string> m1 {make_pair("name","tony"),make_pair("age","20")};
    //way2
    map<string,string> m2(m1);
    // //way3 C++ 11
    // //创建一个会返回临时 map 对象的函数
    // map<string,int> disMap(){
    //     std::map<std::string, int>tempMap{ {"C语言教程",10},{"STL教程",20} };
    //     return tempMap;
    // }
    // //调用 map 类模板的移动构造函数创建 newMap 容器
    // std::map<std::string, int> m3(disMap());
    //way4
    map<string, int>m5{ {"C语言教程",10},{"STL教程",20} };
    map<string, int>newMap(++m5.begin(), m5.end());
    //way5 创建容器同时制定排序规则
    std::map<std::string, int> m4{ {"C语言教程",10},{"STL教程",20} };
    std::map<std::string, int, std::less<std::string> > m4a{ {"C语言教程",10},{"STL教程",20} };
    //修改排序规则
    std::map<std::string, int, std::greater<std::string> > m4b{ {"C语言教程",10},{"STL教程",20} };

}
/**
 * map成员方法：
 * 表 1 C++ map容器常用成员方法
成员方法	功能
begin()	返回指向容器中第一个（注意，是已排好序的第一个）键值对的双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
end()	返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
rbegin()	返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
rend()	返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
find(key)	在 map 容器中查找键为 key 的键值对，如果成功找到，则返回指向该键值对的双向迭代器；反之，则返回和 end() 方法一样的迭代器。另外，如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
lower_bound(key)	返回一个指向当前 map 容器中第一个大于或等于 key 的键值对的双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
upper_bound(key)	返回一个指向当前 map 容器中第一个大于 key 的键值对的迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
equal_range(key)	该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值等价，pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的键为 key 的键值对（map 容器键值对唯一，因此该范围最多包含一个键值对）。
empty() 	若容器为空，则返回 true；否则 false。
size()	返回当前 map 容器中存有键值对的个数。
max_size()	返回 map 容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。
operator[]	map容器重载了 [] 运算符，只要知道 map 容器中某个键值对的键的值，就可以向获取数组中元素那样，通过键直接获取对应的值。
at(key)	找到 map 容器中 key 键对应的值，如果找不到，该函数会引发 out_of_range 异常。
insert()	向 map 容器中插入键值对。
erase()	删除 map 容器指定位置、指定键（key）值或者指定区域内的键值对。后续章节还会对该方法做重点讲解。
swap()	交换 2 个 map 容器中存储的键值对，这意味着，操作的 2 个键值对的类型必须相同。
clear()	清空 map 容器中所有的键值对，即使 map 容器的 size() 为 0。
emplace()	在当前 map 容器中的指定位置处构造新键值对。其效果和插入键值对一样，但效率更高。
emplace_hint()	在本质上和 emplace() 在 map 容器中构造新键值对的方式是一样的，不同之处在于，使用者必须为该方法提供一个指示键值对生成位置的迭代器，并作为该方法的第一个参数。
count(key)	在当前 map 容器中，查找键为 key 的键值对的个数并返回。注意，由于 map 容器中各键值对的键的值是唯一的，因此该函数的返回值最大为 1。
*/

/**
 * 基础2.迭代器遍历
 * 
 * 成员函数：
 * 表 1 map 容器迭代器相关成员方法
成员方法	功能
begin()	返回指向容器中第一个（注意，是已排好序的第一个）键值对的双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
end()	返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
rbegin()	返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
rend() 	返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
cend() 	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
crbegin() 	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
crend() 	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
find(key)	在 map 容器中查找键为 key 的键值对，如果成功找到，则返回指向该键值对的双向迭代器；反之，则返回和 end() 方法一样的迭代器。另外，如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
lower_bound(key)	返回一个指向当前 map 容器中第一个大于或等于 key 的键值对的双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
upper_bound(key) 	返回一个指向当前 map 容器中第一个大于 key 的键值对的迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
equal_range(key)	该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值等价，pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的键为 key 的键值对（map 容器键值对唯一，因此该范围最多包含一个键值对）。
*/
void printMapValue(pair<string,string> p){
    cout << p.first << ":" << p.second << "  ";
}
void mapTraverse(){
    map<string,string> m {{"name","peter"},{"age","19"},{"phone","123456"}};
    //way1
    for (auto it = m.begin();it != m.cend();++it){
        cout << it->first << ":" << it->second << "  ";
    }
    cout << endl;
    //way2
    auto start = m.begin();
    while (start != m.cend())
    {
        cout << start->first << ":" << start->second << "  ";
        start ++;
    }
    cout << endl;
    //way3
    for (auto value : m){
        cout << value.first << ":" << value.second << "  ";
    }
    cout << endl;
    //way4
    for_each(m.crbegin(),m.crend(),printMapValue);
    cout << endl;

    //way5 find()
    // auto it = m.find("age"); //找到相当于begin()
    auto it = m.find("hello"); //没找到就相当于end()
    for (; it != m.end(); it++)
    {                   
        cout << it->first << ":" << it->second<< " ";
    }
    cout << endl;
    //way6 lower_bound(),upper_bound()
    //lower_bound(key) 和 upper_bound(key) 更多用于 multimap 容器，在 map 容器中很少用到。
    //找到第一个键的值不小于 "name" 的键值对
    auto iter = m.lower_bound("name");
    cout << "lower：" << iter->first << " " << iter->second << endl;
    //找到第一个键的值大于 "name" 的键值对
    iter = m.upper_bound("name");
    cout <<"upper：" << iter->first << " " << iter->second << endl;

    /*way7: equal_range(key) 成员方法可以看做是 lower_bound(key) 和 upper_bound(key) 的结合体，该方法会返回一个 pair 对象，
    其中的 2 个元素都是迭代器类型，其中 pair.first 实际上就是 lower_bound(key) 的返回值，而 pair.second 则等同于 upper_bound(key) 
    的返回值。显然，equal_range(key) 成员方法表示的一个范围，位于此范围中的键值对，其键的值都为 key。举个例子：*/
    //创建一个 pair 对象，来接收 equal_range() 的返回值
    pair <map<string, string>::iterator, map<string, string>::iterator> myPair = m.equal_range("name");
    //通过遍历，输出 myPair 指定范围内的键值对
    for (auto iter = myPair.first; iter != myPair.second; ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
}
/**
 * 基础3.根据key获取value
 * 1）[] 
 * 2）at(),key不存在不会直接添加key，会抛出异常out_of_range;
*/
void mapGetValueByKey(){
    map<string,string> mp ;
    mp["1"] = "C";
    mp["2"] = "C++";
    mp["3"] = "Go";
    mp["4"] = "Ruby";
    for (auto value : mp){
        cout << value.first << ":" << value.second << "  ";
    }
    cout << endl;
    //1)[] 已存在的key为赋值或修改；不存在的key为新增；
    mp["5"] = "Jave";//
    mp["4"] = "Js";
    for (auto value : mp){
        cout << value.first << ":" << value.second << "  ";
    } 
    cout << endl;
    //2）at()
    mp.at("5") = "PHP";
    // mp.at("6") = "C#";//out_of_range
    for (auto value : mp){
        cout << value.first << ":" << value.second << "  ";
    } 
    cout << endl;
    // 3)find()或for循环+迭代器
}

int main(){

    //mapTraverse();
    mapGetValueByKey();
    return 0;
}