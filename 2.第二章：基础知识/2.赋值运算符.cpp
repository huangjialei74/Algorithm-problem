#include<iostream>
using namespace std;
 

class A
{
public:
	A(int a){
		this->a = a;
	}
	 A(const A&other)//����A(a other)
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
/*�������캯�������� A(a other)  ����������ʵ������ô�βθ��Ƶ�ʵ�� ����ÿ������캯��
` ��� ��������캯����ֵ�����ڿ������캯���ڵ��ÿ������캯��������ֹ�ĵݹ���ûᵼ��ջ���
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
		if(name != 0) strcpy(name,p);//�ַ�������
	}
	~namelist(){delete []name;}


namelist( const  namelist& a )//��������
	{
		cout<<"�����������"<<endl;
		if(name ==0){//----------------------------------------nameû�з����ڴ�ʱ Ϊ0   ,����NULL       
			delete  []name;
		}
			name = new char[strlen(a.name)+1];
		
	    	if(name != 0) strcpy(name,a.name);//�ַ�������
	
	}
	 
	/*
	1.���õ��Ƕ��� 2.�ж��Ƿ�Ϊ���� 3.�ͷ��ڴ� 4.���ص������͵�����
	*/
 
/*
	//��������Ա:
	namelist& operator = (const namelist &n)
	{
		cout<<"����ֵ"<<endl;
		if(this == &n) return *this;
		delete []name;
		name = new char[strlen(n.name)+1];
		if(name !=0) strcpy(name,n.name);
		return *this;
	}
*/


	//�������Ա:
/*
�����ڴ�ǰ����detele�ͷ���ʵ����name���ڴ棬�����ʱ�ڴ治�㵼��new char�׳��쳣 �� ��name��һ����ָ�룬 ���׵��³������
Ҳ����˵ ��ֵ��������������׳�һ���쳣 namelist��ʵ�����ٱ�����Ч��״̬  Υ���˰�ȫ��

ʵ�ְ�ȫ�Եķ�����
1.����new ����������  ����delete�ͷ����е�����  ---����ȷ�����ڴ����ʧ��ʱ��namelist��ʵ��û�б��޸�
2.�ȴ���һ����ʱʵ�� �ٽ�����ʱʵ����ԭ����ʵ������������У�temp�Ǿֲ�����������if�ͻ��Զ�����������
 ��temp.nameָ����ڴ��ͷš� ����temp.nameָ����ڴ����֮ǰname���ڴ棬�൱���ͷ���֮ǰname���ڴ�
*/
    namelist& operator = (const namelist &n)
	{	cout<<"����ֵ"<<endl;
		 if(this != &n)		  
		 {
		     namelist temp(n);//���ÿ������캯�� ����һ����ʱʵ��  ��temp.name �� name����
		     char *nametemp  = temp.name;
	         temp.name = name;
		     name = nametemp;
		 }
		return *this;
	}

//ͬ��	
	namelist& operator = (const char *n)
	{
		cout<<"�ַ�����ֵ"<<endl; 
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
	 
	namelist n1("001"), n2("002"), n3,n4;// �����ַ�����ֵ
	n1 = n2;//����ֵ����
    n3 = n4 = n1;//����ֵΪ *this   Ϊ����������ʵ��������ֵ !!!!!
	n1.display();
	n3.display();
	n4.display();
	return 0;
}

