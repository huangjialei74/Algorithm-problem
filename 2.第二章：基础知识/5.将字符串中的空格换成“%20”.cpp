#include<iostream>
using namespace std;


void test01()
{
	char str1[] = {"hello"};//赋值给字符串则不同
	char str2[] = {"hello"};

	char *str3 = {"hello"};//赋值给指针相同  
	char *str4 = {"hello"};

	if(str1==str2)
	{
		cout<<"12相同"<<endl;
	}
	else
	{
		cout<<&str1<<"  "<<&str2<<endl;
		cout<<"12不相同"<<endl;
	}

	if(str3==str4)
	{
		cout<<"34相同"<<endl;
	}
	else
	{
		cout<<"34不相同"<<endl;
	}

	/*
	因为str1 str2是两个数组 会为他们分配2个长度为5的空间 并把hello的内容复制进去，，
	而不需要为指针分配 来储存字符串的空间   只需要把他们指向hello在内存中的地址即可
	*/
}


void ReplacBlank(char string[], int length)//length是该数组最大容量
{
	if(string == NULL || length <= 0)
	    return ;
	int originalLength = 0;//string的实际长度
	int numberOfBlank = 0;
	int i = 0;
	while(string[i] != '\0')
	{
		++originalLength;
		if(string[i] == ' ')
			++numberOfBlank;
		++i;
	}
	int newLength = originalLength+ numberOfBlank*2;//新的长度
	if(newLength > length)
		return ;//出界 内存将不够

	int indexOfOriginal = originalLength;//双指针，一个指向原始字符串末尾，一个指向替换之后的字符串末尾
	int indexOfNew = newLength;

	while(indexOfOriginal>=0 && indexOfNew>indexOfOriginal)
	{
		if(string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}




void test02()
{
	char string[50] = {"12345"};
	ReplacBlank(string,50);
	cout<<string<<endl;

}









int main()
{
	 

	test02();
	return 0;
}

