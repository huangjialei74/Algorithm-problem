#include<iostream>
using namespace std;


void test01()
{
	char str1[] = {"hello"};//��ֵ���ַ�����ͬ
	char str2[] = {"hello"};

	char *str3 = {"hello"};//��ֵ��ָ����ͬ  
	char *str4 = {"hello"};

	if(str1==str2)
	{
		cout<<"12��ͬ"<<endl;
	}
	else
	{
		cout<<&str1<<"  "<<&str2<<endl;
		cout<<"12����ͬ"<<endl;
	}

	if(str3==str4)
	{
		cout<<"34��ͬ"<<endl;
	}
	else
	{
		cout<<"34����ͬ"<<endl;
	}

	/*
	��Ϊstr1 str2���������� ��Ϊ���Ƿ���2������Ϊ5�Ŀռ� ����hello�����ݸ��ƽ�ȥ����
	������ҪΪָ����� �������ַ����Ŀռ�   ֻ��Ҫ������ָ��hello���ڴ��еĵ�ַ����
	*/
}


void ReplacBlank(char string[], int length)//length�Ǹ������������
{
	if(string == NULL || length <= 0)
	    return ;
	int originalLength = 0;//string��ʵ�ʳ���
	int numberOfBlank = 0;
	int i = 0;
	while(string[i] != '\0')
	{
		++originalLength;
		if(string[i] == ' ')
			++numberOfBlank;
		++i;
	}
	int newLength = originalLength+ numberOfBlank*2;//�µĳ���
	if(newLength > length)
		return ;//���� �ڴ潫����

	int indexOfOriginal = originalLength;//˫ָ�룬һ��ָ��ԭʼ�ַ���ĩβ��һ��ָ���滻֮����ַ���ĩβ
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

