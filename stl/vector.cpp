#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
函数成员	函数功能
begin()	返回指向容器中第一个元素的迭代器。
end()	返回指向容器最后一个元素所在位置后一个位置的迭代器，通常和 begin() 结合使用。
rbegin()	返回指向最后一个元素的迭代器。
rend()	返回指向第一个元素所在位置前一个位置的迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
size()	返回实际元素个数。
max_size()	返回元素个数的最大值。这通常是一个很大的值，一般是 232-1，所以我们很少会用到这个函数。
resize()	改变实际元素的个数。
capacity()	返回当前容量。
empty()	判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。
reserve()	增加容器的容量。
shrink _to_fit()	将内存减少到等于当前元素实际所使用的大小。
operator[ ]	重载了 [ ] 运算符，可以向访问数组中元素那样，通过下标即可访问甚至修改 vector 容器中的元素。
at()	使用经过边界检查的索引访问元素。
front()	返回第一个元素的引用。
back()	返回最后一个元素的引用。
data()	返回指向容器中第一个元素的指针。
assign()	用新元素替换原有内容。
push_back()	在序列的尾部添加一个元素。
pop_back()	移出序列尾部的元素。
insert()	在指定的位置插入一个或多个元素。
erase()	移出一个元素或一段元素。
clear()	移出所有的元素，容器大小变为 0。
swap()	交换两个容器的所有元素。
emplace()	在指定的位置直接生成一个元素。
emplace_back()	在序列尾部生成一个元素。
*/

void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
/**基础1
 *@brief vector构造方法，推荐way1 & way5 
 * 
*/
void vectorConstructor()
{
	//way1.无参构造
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//way2.初始化列表  C++11 
	vector<int> v2 { 1,2,3,4,5 };
	printVector(v2);
	//way3.有参构造 （arg0:容器元素个数,arg1:元素值）
	vector<int> v3(10, 100);
	printVector(v3);
	//way4.有参构造 （arg0:其他vector）
	vector<int> v4(v3);
	printVector(v4);
	//way5.有参构造 （arg0:其他vector的起始迭代器,arg1:结尾迭代器）
	vector<int> v5(v1.begin(), v1.end());
	printVector(v5);
}
/**基础2 
 * @brief vector赋值
 * 
*/
void vectorAssign() {
	vector<int> v { 0,1,2,3,4,5,6,7,8,9 };
	printVector(v);
	//@brief  way1 "="
	vector<int> v1;
	v1 = v;
	printVector(v1);
	//way2 
	vector<int> v2;
	v2.assign(v.begin(), v.end());
	printVector(v2);

	vector<int> v3;
	v3.assign(5, 100);
	printVector(v3);

}

void printValue(int val) {
	cout << val << endl;
}
/**基础3
 *@brief vector遍历的几种方法  cbegin(),cend()同理，rbegin(),rend()反向迭代器 
 * 
*/
void vectorTraverse() {
	vector<int> v { 0,1,2,3,4,5,6,7,8,9 };
	//way1.迭代器遍历---while
	vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();
	while (pBegin != pEnd)
	{
		cout << *pBegin << endl;
		pBegin++;
	}
	//way2.迭代器遍历---for
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	//way3.STL算法遍历 #include <algorithm>
	for_each(v.begin(), v.end(), printValue);
}
/**基础4
 *@brief vector的容量和大小 
 * 
*/
void vectorCapSize() {
	vector<int> v { 0,1,2,3,4,5,6,7,8,9 };
	printVector(v);
	if (v.empty()) {
		cout << "v is empty!" << endl;
	}
	else {
		cout << "v.capacity=" << v.capacity() << "    v.size=" << v.size() << endl;
	}
	//resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充 
	v.resize(15, 10);
	printVector(v);
	cout << "v.capacity=" << v.capacity() << "    v.size=" << v.size() << endl;
	//resize 重新指定大小 ，若指定的更小，超出部分元素被删除 
	v.resize(5);
	printVector(v);
	cout << "v.capacity=" << v.capacity() << "    v.size=" << v.size() << endl;
}
/**基础5
 *@brief vector的插入和删除 
 * 
 * Note1:emplace_back() 和 push_back() 的区别：就在于底层实现的机制不同。push_back() 向容器尾部添加元素时，
 * 	首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；
 * 	而 emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。
 * Note2:emplace()和insert()的区别同Note1，除此之外，emplace()每次只能插入一个元素，不是多个；
 * 	iterator emplace (const_iterator pos, args...);
 * Note3:<algorithm>里的remove()也可以删除元素；
*/
void vectorInsertAndDel() {
	vector<int> v1; 
	v1.push_back(10); //尾插 
	v1.push_back(20); 
	v1.push_back(30); 
	v1.emplace_back(40); //C++11
	v1.emplace_back(50); 
	printVector(v1); 
	v1.pop_back(); //尾删1  不需要入参，无返回值
	printVector(v1);  
	v1.insert(v1.begin(), 100); //插入
	printVector(v1);
	v1.emplace(v1.begin(),250);//C++11
	printVector(v1);
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1); 
	v1.erase(v1.begin()); //删除2  入参是删除元素的迭代器，返回下一个元素的迭代器；  
	printVector(v1); 
	v1.erase(v1.begin(), v1.end());//删除3  入参是两个元素迭代器，返回下一个元素的迭代器；
	v1.clear(); //清空容器，size()为0,cap()不变
	printVector(v1);
}
/**基础6
 *@brief vector访问指定元素 
 * 
 * Note1:at和[]的区别：容器名[n]这种获取元素的方式，需要确保下标 n 的值不会超过容器的容量（可以通过 capacity() 成员函数获取），
 * 否则会发生越界访问的错误。幸运的是，和 array 容器一样，vector 容器也提供了 at() 成员函数，当传给 at() 的索引会造成越界时，
 * 会抛出std::out_of_range异常。
*/
void vectorGet() {
	vector<int>v1; 
	for (int i = 0; i < 10; i++) { 
		v1.push_back(i); 
	}
	for (int i = 0; i < v1.size(); i++) { 
		cout << v1[i] << " "; 
	}
	cout << endl; 
	for (int i = 0; i < v1.size(); i++) { 
		cout << v1.at(i) << " "; 
	}
	cout << endl;
	cout << "v1的第一个元素为： " << v1.front() << endl; 
	cout << "v1的最后一个元素为： " << v1.back() << endl;

	cout << *v1.data() << "~" << *(v1.data()+9) << endl;
}
/**基础7
 * @brief vector的交换，收缩内存
 * 
*/
void vectorSwap() {
	cout << "swap case1:" << endl;
	vector<int> v1{ 1,2,3,4,5,6,7,8,9 };
	vector<int> v2{ 9,8,7,6,5,4,3,2,1 };
	printVector(v1);
	printVector(v2);
	v1.swap(v2);
	cout << "v1和v2交换后..." << endl;
	printVector(v1);
	printVector(v2);
	cout << "***************************************************************************" << endl;
	cout << "swap case2:" << endl;

	vector<int> v; 
	for (int i = 0; i < 10000; i++) { 
		v.push_back(i); 
	}
	cout << "v的容量为：" << v.capacity() << endl; 
	cout << "v的大小为：" << v.size() << endl; 
	v.resize(3); 
	cout << "v的容量为：" << v.capacity() << endl; 
	cout << "v的大小为：" << v.size() << endl; //收缩内存 
	vector<int>(v).swap(v); //匿名对象 
	cout << "v的容量为：" << v.capacity() << endl; 
	cout << "v的大小为：" << v.size() << endl;
}
/**基础8
 * @brief vector预留空间
 * 
*/
void vectorReserve() {
	vector<int> v; //预留空间 
	v.reserve(100000); 
	int num = 0; 
	int* p = NULL; 
	for (int i = 0; i < 100000; i++) {
		v.push_back(i); 
		if (p != &v[0]) 
		{ 
			p = &v[0]; 
			num++; 
		} 
	}
	cout << "num:" << num << endl;
}
/**提升1 vector容器的迭代器注意事项
 * 初始化为空的容器不能使用迭代器，因为begin()和end()指向同一个位置；
 * vector容器增加容量之后，原迭代器指向的位置会变；
*/
void iteratorNote()
{
    vector<int>values{1,2,3};
    cout << "values 容器首个元素的地址：" << values.data() << endl;
    auto first = values.begin();
    auto end = values.end();
    //增加 values 的容量
    values.reserve(20);
    cout << "values 容器首个元素的地址：" << values.data() << endl;
    first = values.begin();//重新获取first和end，不能再用原有的first和end，指向变了；
    end = values.end();
    while (first != end) {
        cout << *first ;
        ++first;
    }
}
/**提升2  如何避免vector不必要的扩容？
 * 
*/

/**提升3 swap()的特殊用法
 * 
*/
/**提升4 vector<bool>不是存储bool类型的容器
 * 
*/
int main()
{
	std::cout << "Hello World!\n";
	//vectorConstructor();      /*1*/
	//vectorAssign();           /*2*/
	//vectorTraverse();         /*3*/
	//vectorCapSize();          /*4*/
	//vectorInsertAndDel();     /*5*/
	vectorGet();              /*6*/
	//vectorSwap();             /*7*/
	//vectorReserve();            /*8*/

	//iteratorNote();
	
}



