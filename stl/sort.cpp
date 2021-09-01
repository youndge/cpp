#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

/**
 * 表 1 C++ STL 排序函数
函数名	用法
sort (first, last)	对容器或普通数组中 [first, last) 范围内的元素进行排序，默认进行升序排序。
stable_sort (first, last)	和 sort() 函数功能相似，不同之处在于，对于 [first, last) 范围内值相同的元素，该函数不会改变它们的相对位置。
partial_sort (first, middle, last)	从 [first,last) 范围内，筛选出 muddle-first 个最小的元素并排序存放在 [first，middle) 区间中。
partial_sort_copy (first, last, result_first, result_last)	从 [first, last) 范围内筛选出 result_last-result_first 个元素排序并存储到 [result_first, result_last) 指定的范围中。
is_sorted (first, last)	检测 [first, last) 范围内是否已经排好序，默认检测是否按升序排序。
is_sorted_until (first, last)	和 is_sorted() 函数功能类似，唯一的区别在于，如果 [first, last) 范围的元素没有排好序，则该函数会返回一个指向首个不遵循排序规则的元素的迭代器。
void nth_element (first, nth, last)	找到 [first, last) 范围内按照排序规则（默认按照升序排序）应该位于第 nth 个位置处的元素，并将其放置到此位置。同时使该位置左侧的所有元素都比其存放的元素小，该位置右侧的所有元素都比其存放的元素大。
*/

/**
 * sort() 基于快速排序
 * 使用条件：
 * 1.容器支持的迭代器类型必须为随机访问迭代器。这意味着，sort() 只对 array、vector、deque 这 3 个容器提供支持。
 * 2.如果对容器中指定区域的元素做默认升序排序，则元素类型必须支持<小于运算符；同样，如果选用标准库提供的其它排序规则，
    元素类型也必须支持该规则底层实现所用的比较运算符；
 * 3.sort() 函数在实现排序时，需要交换容器中元素的存储位置。这种情况下，如果容器中存储的是自定义的类对象，则该类的内部
    必须提供移动构造函数和移动赋值运算符。
 * 注意：sort()不保证相等元素的相对顺序不变；
*/

/**
 * 语法：
 * 1.//对 [first, last) 区域内的元素做默认的升序排序
    void sort (RandomAccessIterator first, RandomAccessIterator last);
 * 2.//按照指定的 comp 排序规则，对 [first, last) 区域内的元素进行排序
    void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
 * 效率：该函数实现排序的平均时间复杂度为N*log2N（其中 N 为指定区域 [first, last) 中 last 和 first 的距离）。
*/
void printVector(std::vector<int> vec){
    for (auto i = vec.cbegin(); i != vec.cend(); i++)
    {
        std::cout << *i << " " ;
    }
    std::cout << std::endl;
}
bool mycomp(int i, int j){
    return i < j;
}
class mycomp2{
public:
    bool operator() (int i, int j){
        return i < j;
    }
};
class mycomp3{
public:
    bool operator() (int i, int j){
        return i > j;
    }
};
void testSort(){
    std::vector<int> myvector{ 32, 71, 12, 45, 26, 80, 53, 33 };
    //第一种语法，默认升序
    std::sort(myvector.begin(), myvector.end());
    printVector(myvector);
    //第二种语法，stl提供的排序规则
    std::sort(myvector.begin(), myvector.end(), std::greater<int>());
    printVector(myvector);
    //第二种语法，自定义普通函数为排序规则
    std::sort(myvector.begin(), myvector.end(), mycomp);
    printVector(myvector);
    //第二种语法，自定义函数对象为排序规则
    std::sort(myvector.begin(), myvector.end(), mycomp2());
    printVector(myvector);
}
/**
 * stable_sort() 基于归并排序
 * 条件：sort()的前提条件 + 需要相等元素保证相对顺序不变
*/
/**
 * 语法：
 * 1.//对 [first, last) 区域内的元素做默认的升序排序
void stable_sort ( RandomAccessIterator first, RandomAccessIterator last );
 * 2.//按照指定的 comp 排序规则，对 [first, last) 区域内的元素进行排序
void stable_sort ( RandomAccessIterator first, RandomAccessIterator last, Compare comp );
 * 效率：当可用空间足够的情况下，该函数的时间复杂度可达到O(N*log2(N))；
        反之，时间复杂度为O(N*log2(N)2)，其中 N 为指定区域 [first, last) 中 last 和 first 的距离。
*/
void testStableSort(){
    std::vector<int> myvector{ 33, 71, 12, 71, 26, 33, 53, 33 };
    //第一种语法，默认升序
    std::stable_sort(myvector.begin(), myvector.end());
    printVector(myvector);
    //第二种语法，stl提供的排序规则
    std::stable_sort(myvector.begin(), myvector.end(), std::greater<int>());
    printVector(myvector);
    //第二种语法，自定义普通函数为排序规则
    std::stable_sort(myvector.begin(), myvector.end(), mycomp);
    printVector(myvector);
    //第二种语法，自定义函数对象为排序规则
    std::stable_sort(myvector.begin(), myvector.end(), mycomp2());
    printVector(myvector);
}

/**
 * partial_sort() 函数会以交换元素存储位置的方式实现部分排序的。具体来说，partial_sort() 会将 [first, last) 范围内最小（或最大）
 的 middle-first 个元素移动到 [first, middle) 区域中，并对这部分元素做升序（或降序）排序。
 * 条件：
 1.容器支持的迭代器类型必须为随机访问迭代器。这意味着，partial_sort() 函数只适用于 array、vector、deque 这 3 个容器。
 2.当选用默认的升序排序规则时，容器中存储的元素类型必须支持 <小于运算符；同样，如果选用标准库提供的其它排序规则，元素类型也必须支持该规则底层实现所用的比较运算符；
 3.partial_sort() 函数在实现过程中，需要交换某些元素的存储位置。因此，如果容器中存储的是自定义的类对象，则该类的内部必须提供移动构造函数和移动赋值运算符。

*/
/**
 * 语法：
 1.//按照默认的升序排序规则，对 [first, last) 范围的数据进行筛选并排序
void partial_sort (RandomAccessIterator first,
                   RandomAccessIterator middle,
                   RandomAccessIterator last);
 2.//按照 comp 排序规则，对 [first, last) 范围的数据进行筛选并排序
void partial_sort (RandomAccessIterator first,
                   RandomAccessIterator middle,
                   RandomAccessIterator last,
                   Compare comp);
 * 效率：partial_sort() 函数实现排序的平均时间复杂度为N*log(M)，其中 N 指的是 [first, last) 范围的长度，M 指的是 [first, middle) 范围的长度。 
*/
void partial_sort(){
    std::vector<int> myvector{ 3,2,5,4,1,6,9,7};
    //以默认的升序排序作为排序规则，将 myvector 中最小的 4 个元素移动到开头位置并排好序
    std::partial_sort(myvector.begin(), myvector.begin() + 4, myvector.end());
    std::cout << "第一次排序:\n";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << *it << ' ';
    std::cout << "\n第二次排序:\n";
    // 以指定的 mycomp2 作为排序规则，将 myvector 中最大的 4 个元素移动到开头位置并排好序
    std::partial_sort(myvector.begin(), myvector.begin() + 4, myvector.end(), mycomp3());
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << *it << ' ';
}
/**
 * partial_sort_copy() 函数的功能和 partial_sort() 类似，唯一的区别在于，前者不会对原有数据做任何变动，
    而是先将选定的部分元素拷贝到另外指定的数组或容器中，然后再对这部分元素进行排序。
 * partial_sort_copy() 函数会将 [first, last) 范围内最小（或最大）的 result_last-result_first 个元素
    复制到 [result_first, result_last) 区域中，并对该区域的元素做升序（或降序）排序。
*/
/**
 * 语法：//默认以升序规则进行部分排序
RandomAccessIterator partial_sort_copy (
                       InputIterator first,
                       InputIterator last,
                       RandomAccessIterator result_first,
                       RandomAccessIterator result_last);
//以 comp 规则进行部分排序
RandomAccessIterator partial_sort_copy (
                       InputIterator first,
                       InputIterator last,
                       RandomAccessIterator result_first,
                       RandomAccessIterator result_last,
                       Compare comp);
 * 效率：partial_sort_copy() 函数实现排序的平均时间复杂度为N*log(min(N,M))，其中 N 指的是 [first, last) 范围的长度，
    M 指的是 [result_first, result_last) 范围的长度。
*/
void partial_sort_copy(){
    int myints[5] = { 0 };
    std::list<int> mylist{ 3,2,5,4,1,6,9,7 };
    //按照默认的排序规则进行部分排序
    std::partial_sort_copy(mylist.begin(), mylist.end(), myints, myints + 5);
    std::cout << "第一次排序：\n";
    for (int i = 0; i < 5; i++) {
        std::cout << myints[i] << " ";
    }
    //以自定义的 mycomp2 作为排序规则，进行部分排序
    std::partial_sort_copy(mylist.begin(), mylist.end(), myints, myints + 5, mycomp3());
    std::cout << "\n第二次排序：\n";
    for (int i = 0; i < 5; i++) {
        std::cout << myints[i] << " ";
    }
}
/**
 * nth_element() 函数的功能，当采用默认的升序排序规则（std::less<T>）时，该函数可以从某个序列中找到第 n 小的元素 K，
  并将 K 移动到序列中第 n 的位置处。不仅如此，整个序列经过 nth_element() 函数处理后，所有位于 K 之前的元素都比 K 小，所有位于 K 之后的元素都比 K 大。
 * 条件：注意，鉴于 nth_element() 函数中各个参数的类型，其只能对普通数组或者部分容器进行排序。换句话说，只有普通数组和符合以下全部条件的容器，才能使用使用 nth_element() 函数：
1.容器支持的迭代器类型必须为随机访问迭代器。这意味着，nth_element() 函数只适用于 array、vector、deque 这 3 个容器。
2.当选用默认的升序排序规则时，容器中存储的元素类型必须支持 <小于运算符；同样，如果选用标准库提供的其它排序规则，元素类型也必须支持该规则底层实现所用的比较运算符；
3.nth_element() 函数在实现过程中，需要交换某些元素的存储位置。因此，如果容器中存储的是自定义的类对象，则该类的内部必须提供移动构造函数和移动赋值运算符。
*/
/**
 * 语法：
 1.//排序规则采用默认的升序排序
void nth_element (RandomAccessIterator first,
                  RandomAccessIterator nth,
                  RandomAccessIterator last);
2.//排序规则为自定义的 comp 排序规则
void nth_element (RandomAccessIterator first,
                  RandomAccessIterator nth,
                  RandomAccessIterator last,
                  Compare comp);
其中，各个参数的含义如下：
first 和 last：都是随机访问迭代器，[first, last) 用于指定该函数的作用范围（即要处理哪些数据）；
nth：也是随机访问迭代器，其功能是令函数查找“第 nth 大”的元素，并将其移动到 nth 指向的位置；
comp：用于自定义排序规则。
 * 效率：
*/
void nth_element(){
    std::vector<int> myvector{3,1,2,5,4};
    //默认的升序排序作为排序规则
    std::nth_element(myvector.begin(), myvector.begin()+2, myvector.end());
    std::cout << "第一次nth_element排序：\n";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }
    //自定义的 mycomp2() 或者 mycomp1 降序排序作为排序规则
    std::nth_element(myvector.begin(), myvector.begin() + 3, myvector.end(),mycomp);
    std::cout << "\n第二次nth_element排序：\n";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }
}
/**
 * is_sorted() 判断是否有序
 * 语法：
 1.//判断 [first, last) 区域内的数据是否符合 std::less<T> 排序规则，即是否为升序序列
bool is_sorted (ForwardIterator first, ForwardIterator last);
 2.//判断 [first, last) 区域内的数据是否符合 comp 排序规则  
bool is_sorted (ForwardIterator first, ForwardIterator last, Compare comp);
*/
void is_sorted(){
    vector<int> myvector{ 3,1,2,4 };
    list<int> mylist{ 1,2,3,4 };
    //调用第 2 种语法格式的 is_sorted() 函数，该判断语句会得到执行
    if (!is_sorted(myvector.begin(), myvector.end(),mycomp2())) {
        cout << "开始对 myvector 容器排序" << endl;
        //对 myvector 容器做降序排序
        sort(myvector.begin(), myvector.end(),mycomp2());
        //输出 myvector 容器中的元素
        for (auto it = myvector.begin(); it != myvector.end(); ++it) {
            cout << *it << " ";
        }
    }
   
    //调用第一种语法格式的 is_sorted() 函数，该判断语句得不到执行
    if (!is_sorted(mylist.begin(), mylist.end())) {
        cout << "开始对 mylist 排序" << endl;
        //......
    }
}
/**
 * is_sorted_until() 函数不仅能检测出某个序列是否有序，还会返回一个正向迭代器，该迭代器指向的是当前序列中第一个破坏有序状态的元素。
 * 语法：
1.//排序规则为默认的升序排序
ForwardIterator is_sorted_until (ForwardIterator first, ForwardIterator last);
2.//排序规则是自定义的 comp 规则
ForwardIterator is_sorted_until (ForwardIterator first,
                                 ForwardIterator last,
                                 Compare comp);
其中，first 和 last 都为正向迭代器（这意味着该函数适用于大部分容器），[first, last) 用于指定要检测的序列；comp 用于指定自定义的排序规则。
*/
void is_sorted_until(){
    vector<int> myvector{ 3,1,2,4 };
    list<int> mylist{ 1,2,3,4 };
    //如果返回值为 myvector.end()，则表明 myvector 容器中的序列符合 mycomp2() 规则
    if (is_sorted_until(myvector.begin(), myvector.end(),mycomp2()) != myvector.end()) {
        cout << "开始对 myvector 容器排序" << endl;
        //对 myvector 容器做降序排序
        sort(myvector.begin(), myvector.end(),mycomp2());
        //输出 myvector 容器中的元素
        for (auto it = myvector.begin(); it != myvector.end(); ++it) {
            cout << *it << " ";
        }
    }
   
    //该判断语句得不到执行
    if (is_sorted_until(mylist.begin(), mylist.end()) != mylist.end()) {
        cout << "开始对 mylist 排序" << endl;
        //......
    }
}

int main(){
    // testSort();
    // testStableSort();
    // partial_sort();
    // partial_sort_copy();
    // nth_element();
    // is_sorted();
    is_sorted_until();
}