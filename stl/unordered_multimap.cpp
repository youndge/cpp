#include <unordered_map>
#include <iostream>

using namespace std;

/**
 * 成员方法：
 * 表 2 unordered_multimap类模板成员方法
成员方法	功能
begin()	返回指向容器中第一个键值对的正向迭代器。
end() 	返回指向容器中最后一个键值对之后位置的正向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。
empty()	若容器为空，则返回 true；否则 false。
size()	返回当前容器中存有键值对的个数。
max_size()	返回容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。
find(key)	查找以 key 为键的键值对，如果找到，则返回一个指向该键值对的正向迭代器；反之，则返回一个指向容器中最后一个键值对之后位置的迭代器（如果 end() 方法返回的迭代器）。
count(key)	在容器中查找以 key 键的键值对的个数。
equal_range(key)	返回一个 pair 对象，其包含 2 个迭代器，用于表明当前容器中键为 key 的键值对所在的范围。
emplace()	向容器中添加新键值对，效率比 insert() 方法高。
emplace_hint()	向容器中添加新键值对，效率比 insert() 方法高。
insert() 	向容器中添加新键值对。
erase()	删除指定键值对。
clear() 	清空容器，即删除容器中存储的所有键值对。
swap()	交换 2 个 unordered_multimap 容器存储的键值对，前提是必须保证这 2 个容器的类型完全相等。
bucket_count()	返回当前容器底层存储键值对时，使用桶（一个线性链表代表一个桶）的数量。
max_bucket_count()	返回当前系统中，unordered_multimap 容器底层最多可以使用多少桶。
bucket_size(n)	返回第 n 个桶中存储键值对的数量。
bucket(key)	返回以 key 为键的键值对所在桶的编号。
load_factor()	返回 unordered_multimap 容器中当前的负载因子。负载因子，指的是的当前容器中存储键值对的数量（size()）和使用桶数（bucket_count()）的比值，即 load_factor() = size() / bucket_count()。
max_load_factor()	返回或者设置当前 unordered_multimap 容器的负载因子。
rehash(n)	将当前容器底层使用桶的数量设置为 n。
reserve()	将存储桶的数量（也就是 bucket_count() 方法的返回值）设置为至少容纳count个元（不超过最大负载因子）所需的数量，并重新整理容器。
hash_function()	返回当前容器使用的哈希函数对象。
*/

int main(){

    return 0;
}