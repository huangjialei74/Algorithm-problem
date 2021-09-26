#include<iostream>
using namespace std;



class A
{};


class B
{
public:
	B(){}
	~B(){}
};


class C
{
public:
	C(){}
	virtual~C(){}
};











int main()
{
	A a; B b; C c;
	cout<<sizeof(a)<<endl;
	//1 空类型的实例不包含任何信息 但声明该类型实例时 必须在内存中占有一定空间 否则无法使用这些实例 每个空类型的实例占一字节空间

	cout<<sizeof(b)<<endl;//1
//构造函数 和析构函数只需要知道函数的地址即可，函数的地址只与类型有关，与类型的实例无关，编译器不会因为这两个函数而在实例内添加额外信息

	cout<<sizeof(c)<<endl;//4
/*C++编译器发现一个类中有虚函数，就会为该类生成虚函数表，在该类的每一个实例中增加一个指向虚函数表的指针，
	32位的机器上，一个指针占4字节 sizeof()返回4，64位的机器上返回8
*/	 

	return 0;
}

