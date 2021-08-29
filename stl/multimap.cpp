#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * 1.区别 multimap和map的区别，multimap的key可以重复
 * 2.所以multimap没有at()和[]；
 * 3.multimap有count(key)
*/

/**
 * 成员方法：
 * 表 1 C++ multimap 容器常用成员方法
成员方法	功能
begin()	返回指向容器中第一个（注意，是已排好序的第一个）键值对的双向迭代器。如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
end()	返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
rbegin()	返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
rend()	返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
find(key)	在 multimap 容器中查找首个键为 key 的键值对，如果成功找到，则返回指向该键值对的双向迭代器；反之，则返回和 end() 方法一样的迭代器。另外，如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
lower_bound(key)	返回一个指向当前 multimap 容器中第一个大于或等于 key 的键值对的双向迭代器。如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
upper_bound(key)	返回一个指向当前 multimap 容器中第一个大于 key 的键值对的迭代器。如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
equal_range(key)	该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值等价，pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的键为 key 的键值对。
empty() 	若容器为空，则返回 true；否则 false。
size()	返回当前 multimap 容器中存有键值对的个数。
max_size()	返回 multimap 容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。
insert()	向 multimap 容器中插入键值对。
erase()	删除 multimap 容器指定位置、指定键（key）值或者指定区域内的键值对。
swap()	交换 2 个 multimap 容器中存储的键值对，这意味着，操作的 2 个键值对的类型必须相同。
clear()	清空 multimap 容器中所有的键值对，使 multimap 容器的 size() 为 0。
emplace()	在当前 multimap 容器中的指定位置处构造新键值对。其效果和插入键值对一样，但效率更高。
emplace_hint()	在本质上和 emplace() 在 multimap 容器中构造新键值对的方式是一样的，不同之处在于，使用者必须为该方法提供一个指示键值对生成位置的迭代器，并作为该方法的第一个参数。
count(key)	在当前 multimap 容器中，查找键为 key 的键值对的个数并返回。
*/

int main(){

    return 0;
}