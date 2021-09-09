#include <iostream>
#include <memory>

/**
 * 前言：智能指针可以在适当时机自动释放分配的内存。
 * C++98/03 标准中，支持使用 auto_ptr 智能指针来实现堆内存的自动回收；C++11 新标准在废弃 auto_ptr 的同时，
    增添了 unique_ptr、shared_ptr 以及 weak_ptr 这 3 个智能指针来实现堆内存的自动回收。
 * C++ 智能指针底层是采用引用计数的方式实现的。简单的理解，智能指针在申请堆内存空间的同时，会为其配备一个整形值（初始值为 1），
    每当有新对象使用此堆内存时，该整形值 +1；反之，每当使用此堆内存的对象被释放时，该整形值减 1。当堆空间对应的整形值为 0 时，
    即表明不再有对象使用它，该堆空间就会被释放掉。
*/

/**
 * shared_ptr<T>,和 unique_ptr、weak_ptr 不同之处在于，多个 shared_ptr 智能指针可以共同使用同一块堆内存。
   并且，由于该类型智能指针在实现上采用的是引用计数机制，即便有一个 shared_ptr 指针放弃了堆内存的“使用权”（引用计数减 1），
   也不会影响其他指向同一堆内存的 shared_ptr 指针（只有引用计数为 0 时，堆内存才会被自动释放）。
*/
/**
 * 基础1.shared_ptr智能指针的创建
*/
//自定义释放规则
void deleteInt(int *p) {
    delete []p;
}
void createSharedPtr(){
    //1)  通过如下 2 种方式，可以构造出 shared_ptr<T> 类型的空智能指针：注意，空的 shared_ptr 指针，其初始引用计数为 0，而不是 1。
    std::shared_ptr<int> p1;             //不传入任何实参
    std::shared_ptr<int> p2(nullptr);    //传入空指针 nullptr

    //2) 在构建 shared_ptr 智能指针，也可以明确其指向。例如：
    std::shared_ptr<int> p3(new int(10));
    //由此，我们就成功构建了一个 shared_ptr 智能指针，其指向一块存有 10 这个 int 类型数据的堆内存空间。

    //同时，C++11 标准中还提供了 std::make_shared<T> 模板函数，其可以用于初始化 shared_ptr 智能指针，例如：
    std::shared_ptr<int> p3_ = std::make_shared<int>(10);
    //以上 2 种方式创建的 p3 是完全相同。

    //3) 除此之外，shared_ptr<T> 模板还提供有相应的拷贝构造函数和移动构造函数，例如：
    //调用拷贝构造函数
    std::shared_ptr<int> p4(p3);//或者 std::shared_ptr<int> p4 = p3;
    //调用移动构造函数
    std::shared_ptr<int> p5(std::move(p4)); //或者 std::shared_ptr<int> p5 = std::move(p4);
    //如上所示，p3 和 p4 都是 shared_ptr 类型的智能指针，因此可以用 p3 来初始化 p4，由于 p3 是左值，因此会调用拷贝构造函数。需要注意的是，如果 p3 为空智能指针，则 p4 也为空智能指针，其引用计数初始值为 0；反之，则表明 p4 和 p3 指向同一块堆内存，同时该堆空间的引用计数会加 1。
    //而对于 std::move(p4) 来说，该函数会强制将 p4 转换成对应的右值，因此初始化 p5 调用的是移动构造函数。另外和调用拷贝构造函数不同，用 std::move(p4) 初始化 p5，会使得 p5 拥有了 p4 的堆内存，而 p4 则变成了空智能指针。

    //注意，同一普通指针不能同时为多个 shared_ptr 对象赋值，否则会导致程序发生异常。例如：
    int* ptr = new int;
    std::shared_ptr<int> p1_(ptr);
    //std::shared_ptr<int> p2_(ptr);//错误

    //4) 在初始化 shared_ptr 智能指针时，还可以自定义所指堆内存的释放规则，这样当堆内存的引用计数为 0 时，会优先调用我们自定义的释放规则。
    //在某些场景中，自定义释放规则是很有必要的。比如，对于申请的动态数组来说，shared_ptr 指针默认的释放规则是不支持释放数组的，只能自定义对应的释放规则，才能正确地释放申请的堆内存。
    //对于申请的动态数组，释放规则可以使用 C++11 标准中提供的 default_delete<T> 模板类，我们也可以自定义释放规则：
    //指定 default_delete 作为释放规则
    std::shared_ptr<int> p6(new int[10], std::default_delete<int[]>());
    // //自定义释放规则
    // void deleteInt(int *p) {
    //     delete []p;
    // }
    //初始化智能指针，并自定义释放规则
    std::shared_ptr<int> p7(new int[10], deleteInt);
    //实际上借助 lambda 表达式，我们还可以像如下这样初始化 p7，它们是完全相同的：
    //std::shared_ptr<int> p7(new int[10], [](int* p) {delete[]p; });

}

int main(){
    createSharedPtr();
    return 0;
}