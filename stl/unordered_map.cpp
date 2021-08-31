#include <unordered_map>
#include <iostream>

using namespace std;

/**
 * 无序容器：
 * 关联式容器的底层实现采用的树存储结构，更确切的说是红黑树结构；
 * 无序容器的底层实现采用的是哈希表的存储结构。
 * 特点：
 * 1.无序容器内部存储的键值对是无序的，各键值对的存储位置取决于该键值对中的键，
 * 2.和关联式容器相比，无序容器擅长通过指定键查找对应的值（平均时间复杂度为 O(1)）；
   但对于使用迭代器遍历容器中存储的元素，无序容器的执行效率则不如关联式容器。
 * 场景：总的来说，实际场景中如果涉及大量遍历容器的操作，建议首选关联式容器；反之，如果更多的操作是通过键获取对应的值，则应首选无序容器。
*/

/**
 * 基础1.创建容器
*/
void createUmap(){

}
/**
 * 成员函数：
 * 表 2 unordered_map类模板成员方法
成员方法	功能
begin()	返回指向容器中第一个键值对的正向迭代器。
end() 	返回指向容器中最后一个键值对之后位置的正向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。
empty()	若容器为空，则返回 true；否则 false。
size()	返回当前容器中存有键值对的个数。
max_size()	返回容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。
operator[key]	该模板类中重载了 [] 运算符，其功能是可以向访问数组中元素那样，只要给定某个键值对的键 key，就可以获取该键对应的值。注意，如果当前容器中没有以 key 为键的键值对，则其会使用该键向当前容器中插入一个新键值对。
at(key)	返回容器中存储的键 key 对应的值，如果 key 不存在，则会抛出 out_of_range 异常。 
find(key)	查找以 key 为键的键值对，如果找到，则返回一个指向该键值对的正向迭代器；反之，则返回一个指向容器中最后一个键值对之后位置的迭代器（如果 end() 方法返回的迭代器）。
count(key)	在容器中查找以 key 键的键值对的个数。
equal_range(key)	返回一个 pair 对象，其包含 2 个迭代器，用于表明当前容器中键为 key 的键值对所在的范围。
emplace()	向容器中添加新键值对，效率比 insert() 方法高。
emplace_hint()	向容器中添加新键值对，效率比 insert() 方法高。
insert() 	向容器中添加新键值对。
erase()	删除指定键值对。
clear() 	清空容器，即删除容器中存储的所有键值对。
swap()	交换 2 个 unordered_map 容器存储的键值对，前提是必须保证这 2 个容器的类型完全相等。
bucket_count()	返回当前容器底层存储键值对时，使用桶（一个线性链表代表一个桶）的数量。
max_bucket_count()	返回当前系统中，unordered_map 容器底层最多可以使用多少桶。
bucket_size(n)	返回第 n 个桶中存储键值对的数量。
bucket(key)	返回以 key 为键的键值对所在桶的编号。
load_factor()	返回 unordered_map 容器中当前的负载因子。负载因子，指的是的当前容器中存储键值对的数量（size()）和使用桶数（bucket_count()）的比值，即 load_factor() = size() / bucket_count()。
max_load_factor()	返回或者设置当前 unordered_map 容器的负载因子。
rehash(n)	将当前容器底层使用桶的数量设置为 n。
reserve()	将存储桶的数量（也就是 bucket_count() 方法的返回值）设置为至少容纳count个元（不超过最大负载因子）所需的数量，并重新整理容器。
hash_function()	返回当前容器使用的哈希函数对象。
*/

/**
 * 基础2.迭代遍历
*/
void umapTraverse(){
    unordered_map<string,string> umap {{"name","tony"}, {"age","19"},{"phone","123456"}};
    for (auto it = umap.cbegin(); it != umap.cend(); it++)
    {
        cout << it->first << ":" << it->second << "  ";
    }
    cout << endl;
    cout << "age : " << umap.find("age")->second<< endl; 
}

void umapRehash(){
    //创建 umap 容器
    unordered_map<int, int> umap;
    //向 umap 容器添加 50 个键值对
    for (int i = 1; i <= 50; i++) {
        umap.emplace(i, i);
    }
    //获取键为 49 的键值对所在的范围
    auto pair = umap.equal_range(49);
    //输出 pair 范围内的每个键值对的键的值
    for (auto iter = pair.first; iter != pair.second; ++iter) {
        cout << iter->first <<" ";
    }
    cout << endl;
    //手动调整最大负载因子数
    umap.max_load_factor(3.0);
    //手动调用 rehash() 函数重哈希
    umap.rehash(10);
    //重哈希之后，pair 的范围可能会发生变化
    for (auto iter = pair.first; iter != pair.second; ++iter) {
        cout << iter->first << " ";
    }
}
/**
 * 基础3.访问容器元素
*/
void umapGet(){
    //way1 []
    //way2 at()
    //way3 find()
    //way4 for(begin(),end())
}

/**
 * 基础4.insert()
*/
void umapInsert(){
    //way1 普通方法值传递 & 右值引用

    //way2 添加到指定位置

    //way3 从别的容器复制插入

    //way4 一次性insert({})多个键值对
}
void umapEmplace(){
    //emplace()

    //emplace_hint()
}
/**
 * 基础5.删除
 */
void umapDelete(){
    //erase()

    //clear()
}

int main(){
    // umapTraverse();
    umapRehash();
    return 0;
}