#include<iostream>
using namespace std;
 

class A
{
public:
	A(int a){
		this->a = a;
	}
	 A(const A&other)//不能A(a other)
	 {
		 this->a = other.a;
	 }
	int GetA()
	{
		return this->a;
	}
private:
	int a;
};


void test01()
{
    A a(10);
	A b(a);
	cout<<b.GetA()<<endl;
}
/*拷贝构造函数不能是 A(a other)  如果传入的是实例，那么形参复制到实参 会调用拷贝构造函数
` 因此 如果允许构造函数传值，会在拷贝构造函数内调用拷贝构造函数，无休止的递归调用会导致栈溢出
*/
 
//---------------------------------------------------------------------------------------------------------------------------------
 



class namelist
{
private:
	char *name;
public:
	namelist(){
		name = NULL;
	}
	namelist(char *p)
	{
		name = new char[strlen(p)+1];
		if(name != 0) strcpy(name,p);//字符串复制
	}
	~namelist(){delete []name;}


namelist( const  namelist& a )//拷贝构造
	{
		cout<<"拷贝构造调用"<<endl;
		if(name ==0){//----------------------------------------name没有分配内存时 为0   ,不是NULL       
			delete  []name;
		}
			name = new char[strlen(a.name)+1];
		
	    	if(name != 0) strcpy(name,a.name);//字符串复制
	
	}
	 
	/*
	1.引用的是对象 2.判断是否为本身 3.释放内存 4.返回的是类型的引用
	*/
 
/*
	//初级程序员:
	namelist& operator = (const namelist &n)
	{
		cout<<"对象赋值"<<endl;
		if(this == &n) return *this;
		delete []name;
		name = new char[strlen(n.name)+1];
		if(name !=0) strcpy(name,n.name);
		return *this;
	}
*/


	//资深程序员:
/*
分配内存前，用detele释放了实例的name的内存，如果此时内存不足导致new char抛出异常 ， 则name是一个空指针， 容易导致程序崩溃
也就是说 赋值运算符函数里面抛出一个异常 namelist的实例不再保持有效的状态  违背了安全性

实现安全性的方法：
1.先用new 分配新内容  再用delete释放已有的内容  ---可以确保当内存分配失败时，namelist的实例没有被修改
2.先创建一个临时实例 再交换临时实例与原来的实例，下面代码中：temp是局部变量，出了if就会自动调用析构，
 把temp.name指向的内存释放。 由于temp.name指向的内存就是之前name的内存，相当于释放了之前name的内存
*/
    namelist& operator = (const namelist &n)
	{	cout<<"对象赋值"<<endl;
		 if(this != &n)		  
		 {
		     namelist temp(n);//利用拷贝构造函数 创建一个临时实例  把temp.name 与 name交换
		     char *nametemp  = temp.name;
	         temp.name = name;
		     name = nametemp;
		 }
		return *this;
	}

//同上	
	namelist& operator = (const char *n)
	{
		cout<<"字符串赋值"<<endl; 
		delete []name;
		name = new char[strlen(n)+1];
		if(name !=0) strcpy(name,n);
		return *this;
	}

	void display()
	{
		cout<<name<<endl;
	}

};
 


int main()
{
	 
	namelist n1("001"), n2("002"), n3,n4;// 传入字符串赋值
	n1 = n2;//对象赋值重载
    n3 = n4 = n1;//返回值为 *this   为对象本身，可以实现连续赋值 !!!!!
	n1.display();
	n3.display();
	n4.display();
	return 0;
}

