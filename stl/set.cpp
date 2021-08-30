#include <iostream>
#include <set>

using namespace std;

/**
 * set存储的是key和value相等的键值对，遂仅存值；底层是二叉树实现；虽然没有const修饰，但一般只删除新增，而不直接修改；
 * set不可以重复，默认从小到大排序；
 * multiset可以有重复元素；
*/

/**
 * 基础1.创建容器
*/
void createSet(){
    //way1
    set<string> mySet;
    set<string> s1 {"hello","world","haha"};
    //way2 拷贝构造
    set<string> s2(s1);
    //way3 移动构造

    //way4 
    set<string> s3(++s1.begin(),s1.end());
}

/**
 * 成员方法：
 * 表 1 C++ set 容器常用成员方法
成员方法	功能
begin()	返回指向容器中第一个（注意，是已排好序的第一个）元素的双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
end()	返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
rbegin()	返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
rend()	返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
find(val)	在 set 容器中查找值为 val 的元素，如果成功找到，则返回指向该元素的双向迭代器；反之，则返回和 end() 方法一样的迭代器。另外，如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
lower_bound(val)	返回一个指向当前 set 容器中第一个大于或等于 val 的元素的双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
upper_bound(val)	返回一个指向当前 set 容器中第一个大于 val 的元素的迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
equal_range(val)	该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值等价，pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的值为 val 的元素（set 容器中各个元素是唯一的，因此该范围最多包含一个元素）。
empty()	若容器为空，则返回 true；否则 false。
size()	返回当前 set 容器中存有元素的个数。
max_size()	返回 set 容器所能容纳元素的最大个数，不同的操作系统，其返回值亦不相同。
insert()	向 set 容器中插入元素。
erase()	删除 set 容器中存储的元素。
swap()	交换 2 个 set 容器中存储的所有元素。这意味着，操作的 2 个 set 容器的类型必须相同。
clear()	清空 set 容器中所有的元素，即令 set 容器的 size() 为 0。
emplace()	在当前 set 容器中的指定位置直接构造新元素。其效果和 insert() 一样，但效率更高。
emplace_hint()	在本质上和 emplace() 在 set 容器中构造新元素的方式是一样的，不同之处在于，使用者必须为该方法提供一个指示新元素生成位置的迭代器，并作为该方法的第一个参数。
count(val)	在当前 set 容器中，查找值为 val 的元素的个数，并返回。注意，由于 set 容器中各元素的值是唯一的，因此该函数的返回值最大为 1。
*/

/**
 * 基础2.迭代遍历
*/
void setTraverse(){
    set<string> s1 {"C","C++","Go","Python","java","PHP"};
    //way1
    for (auto it = s1.cbegin(); it != s1.cend(); it ++){
        cout << *it << " ";
    }
    cout << endl;
}
/**
 * 基础3 insert()
*/
void setInsert(){
    //way1
    //创建并初始化set容器
    std::set<std::string> myset;
    //准备接受 insert() 的返回值
    pair<set<string>::iterator, bool> retpair;
    //采用普通引用传值方式
    string str = "stl";
    retpair = myset.insert(str);
    cout << "iter->" << *(retpair.first) << " " << "bool = " << retpair.second << endl;
    //采用右值引用传值方式
    retpair = myset.insert("python");
    cout << "iter->" << *(retpair.first) << " " << "bool = " << retpair.second << endl;

    //way2
    //创建并初始化set容器
    std::set<std::string> myset2;
    //准备接受 insert() 的返回值
    set<string>::iterator iter;
    //采用普通引用传值方式
    string str2 = "stl";
    iter = myset2.insert(myset2.begin(),str2);
    cout << "myset size =" << myset2.size() << endl;
    //采用右值引用传值方式
    iter = myset2.insert(myset2.end(),"python");
    cout << "myset size =" << myset2.size() << endl;

    //way3 insert() 方法支持向当前 set 容器中插入其它 set 容器指定区域内的所有元素，只要这 2 个 set 容器存储的元素类型相同即可。
    //创建并初始化set容器
    std::set<std::string> myset3{ "stl",
                                "python",
                                "java" };
    //创建一个同类型的空 set 容器
    std::set<std::string> otherset;
    //利用 myset 初始化 otherset
    otherset.insert(++myset3.begin(), myset3.end());
    //输出 otherset 容器中的元素
    for (auto iter = otherset.begin(); iter != otherset.end(); ++iter) {
        cout << *iter << endl;
    }
    //way4 采用如下格式的 insert() 方法，可实现一次向 set 容器中添加多个元素：
    //创建并初始化set容器
    std::set<std::string> myset4;
    //向 myset 中添加多个元素
    myset4.insert({ "stl","python","C++"});
    for (auto iter = myset4.begin(); iter != myset4.end(); ++iter) {
        cout << *iter << endl;
    }
}

/**
 * 基础4.emplace() & emplace_hint()
*/
void setEmplace(){
    //emplace()
    //创建并初始化 set 容器
    std::set<string>myset;
    //向 myset 容器中添加元素
    pair<set<string, string>::iterator, bool> ret = myset.emplace("stl");
    cout << "myset size = " << myset.size() << endl;
    cout << "ret.iter = <" << *(ret.first) << ", " << ret.second << ">" << endl;

    //emplace_hint()
    //创建并初始化 set 容器
    std::set<string>myset2;
    //在 set 容器的指定位置添加键值对
    set<string>::iterator iter = myset2.emplace_hint(myset.begin(), "python");
    cout << "myset size = " << myset2.size() << endl;
    cout << *iter << endl;
}
/**
 * 基础5.erase()
*/
void setDeltete(){
    //创建并初始化 set 容器
    std::set<int>myset{1,2,3,4,5};
    cout << "myset size = " << myset.size() << endl;
   
    //1) 调用第一种格式的 erase() 方法
    int num = myset.erase(2); //删除元素 2，myset={1,3,4,5}
    cout << "1、myset size = " << myset.size() << endl;
    cout << "num = " << num << endl;
    //2) 调用第二种格式的 erase() 方法
    set<int>::iterator iter = myset.erase(myset.begin()); //删除元素 1，myset={3,4,5}
    cout << "2、myset size = " << myset.size() << endl;
    cout << "iter->" << *iter << endl;
    //3) 调用第三种格式的 erase() 方法
    set<int>::iterator iter2 = myset.erase(myset.begin(), --myset.end());//删除元素 3,4，myset={5}
    cout << "3、myset size = " << myset.size() << endl;
    cout << "iter2->" << *iter2 << endl;

    //clear()
    cout << "1、myset size = " << myset.size() << endl;
    //清空 myset 容器
    myset.clear();
    cout << "2、myset size = " << myset.size() << endl;
}

int main(){

    // setTraverse();
    // setInsert();
    // setEmplace();
    setDeltete();
    return 0;
}