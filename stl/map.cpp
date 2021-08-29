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
/**
 * 基础4.map insert()方法
 * 1) 无需指定插入位置，直接将键值对添加到 map 容器中。insert() 方法的语法格式有以下 2 种：
//1、引用传递一个键值对
pair<iterator,bool> insert (const value_type& val);
//2、以右值引用的方式传递键值对
template <class P>
    pair<iterator,bool> insert (P&& val);
其中，val 参数表示键值对变量，同时该方法会返回一个 pair 对象，其中 pair.first 表示一个迭代器，pair.second 为一个 bool 类型变量：
如果成功插入 val，则该迭代器指向新插入的 val，bool 值为 true；
如果插入 val 失败，则表明当前 map 容器中存有和 val 的键相同的键值对（用 p 表示），此时返回的迭代器指向 p，bool 值为 false。
*
* 2) 除此之外，insert() 方法还支持向 map 容器的指定位置插入新键值对，该方法的语法格式如下：
//以普通引用的方式传递 val 参数
iterator insert (const_iterator position, const value_type& val);
//以右值引用的方式传递 val 键值对参数
template <class P>
    iterator insert (const_iterator position, P&& val);

其中 val 为要插入的键值对变量。注意，和第 1 种方式的语法格式不同，这里 insert() 方法返回的是迭代器，而不再是 pair 对象：
如果插入成功，insert() 方法会返回一个指向 map 容器中已插入键值对的迭代器；
如果插入失败，insert() 方法同样会返回一个迭代器，该迭代器指向 map 容器中和 val 具有相同键的那个键值对。
*
* 3) insert() 方法还支持向当前 map 容器中插入其它 map 容器指定区域内的所有键值对，该方法的语法格式如下：
template <class InputIterator>
  void insert (InputIterator first, InputIterator last);
其中 first 和 last 都是迭代器，它们的组合<first,last>可以表示某 map 容器中的指定区域。
*
* 4) 除了以上一种格式外，insert() 方法还允许一次向 map 容器中插入多个键值对，其语法格式为：
void insert ({val1, val2, ...});
*/
void mapInsert(){
    //1)无需指定插入位置 
    //创建一个空 map 容器
    std::map<string, string> mp1;
    //创建一个真实存在的键值对变量
    std::pair<string, string> p1 = { "name","tony" };
    //创建一个接收 insert() 方法返回值的 pair 对象
    std::pair<std::map<string, string>::iterator, bool> ret;
    //插入 p1，由于 p1 并不是临时变量，因此会以第一种方式传参
    ret = mp1.insert(p1);
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //以右值引用的方式传递临时的键值对变量
    ret = mp1.insert({ "age","19" });
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //插入失败样例
    ret = mp1.insert({ "name","tony" });
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;

    //2）指定插入位置
    //创建一个空 map 容器
    std::map<string, string> mp2;
    //创建一个真实存在的键值对变量
    std::pair<string, string> p2 = { "name","tony" };
    //指定要插入的位置
    std::map<string, string>::iterator it = mp2.begin();
    //向 it 位置以普通引用的方式插入 p2
    auto iter1 = mp2.insert(it, p2);
    cout << iter1->first << " " << iter1->second << endl;
    //向 it 位置以右值引用的方式插入临时键值对
    auto iter2 = mp2.insert(it, std::pair<string, string>("age", "19"));
    cout << iter2->first << " " << iter2->second << endl;
    //插入失败样例
    auto iter3 = mp2.insert(it, std::pair<string, string>("name", "tony"));
    cout << iter3->first << " " << iter3->second << endl;

    //3)插入指定区域的键值对
    //创建并初始化 map 容器
    std::map<std::string, std::string> mp3{ {"name","tony"},
                                                {"age","19"},
                                                {"phone","123456"} };
    //创建一个空 map 容器
    std::map<std::string, std::string>copymap;
    //指定插入区域
    std::map<string, string>::iterator first = ++mp3.begin();
    std::map<string, string>::iterator last = mp3.end();
    //将<first,last>区域内的键值对插入到 copymap 中
    copymap.insert(first, last);
    //遍历输出 copymap 容器中的键值对
    for (auto iter = copymap.begin(); iter != copymap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    //4)insert()多个pair
    map<string,string> mp4;
    mp4.insert({{"name","tom"},{"age","17"},{"phone","567890"}});
    for (auto iter = mp4.begin(); iter != mp4.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
}

/**
 * 基础5.emplace()
 * 实现相同的插入操作，无论是用 emplace() 还是 emplace_hont()，都比 insert() 方法的效率高
 * 1)emplace()
 template <class... Args>
  pair<iterator,bool> emplace (Args&&... args);
参数 (Args&&... args) 指的是，这里只需要将创建新键值对所需的数据作为参数直接传入即可，此方法可以自行利用这些数据构建出指定的键值对。
另外，该方法的返回值也是一个 pair 对象，其中 pair.first 为一个迭代器，pair.second 为一个 bool 类型变量：
当该方法将键值对成功插入到 map 容器中时，其返回的迭代器指向该新插入的键值对，同时 bool 变量的值为 true；
当插入失败时，则表明 map 容器中存在具有相同键的键值对，此时返回的迭代器指向此具有相同键的键值对，同时 bool 变量的值为 false。
*
* 2) emplace_hint() 方法的功能和 emplace() 类似，其语法格式如下：
template <class... Args>
  iterator emplace_hint (const_iterator position, Args&&... args);
显然和 emplace() 语法格式相比，有以下 2 点不同：
该方法不仅要传入创建键值对所需要的数据，还需要传入一个迭代器作为第一个参数，指明要插入的位置（新键值对键会插入到该迭代器指向的键值对的前面）；
该方法的返回值是一个迭代器，而不再是 pair 对象。当成功插入新键值对时，返回的迭代器指向新插入的键值对；反之，如果插入失败，则表明 map 容器
中存有相同键的键值对，返回的迭代器就指向这个键值对。
*/
void mapEmplace(){
    //1.emplace()
    //创建并初始化 map 容器
    std::map<string, string> mp1;
    //插入键值对
    pair<map<string, string>::iterator, bool> ret = mp1.emplace("name", "jemmy");
    cout << "1、ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //插入新键值对
    ret = mp1.emplace("age", "15");
    cout << "2、ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //失败插入的样例
    ret = mp1.emplace("name", "jemmy");
    cout << "3、ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;

    //2.emplace_hint()
    //创建并初始化 map 容器
    std::map<string, string>mp2;
    //指定在 map 容器插入键值对
    map<string, string>::iterator iter = mp2.emplace_hint(mp2.begin(),"name", "mary");
    cout << iter->first << " " << iter->second << endl;
    iter = mp2.emplace_hint(mp2.begin(), "age", "16");
    cout << iter->first << " " << iter->second << endl;
    //插入失败样例
    iter = mp2.emplace_hint(mp2.begin(), "name", "mary");
    cout << iter->first << " " << iter->second << endl;
}
/**
 * 提升1.C++ map容器operator[],insert()和emplace()效率对比（深度剖析）
*/
int main(){

    //mapTraverse();
    // mapGetValueByKey();
    // mapInsert();
    mapEmplace();
    return 0;
}