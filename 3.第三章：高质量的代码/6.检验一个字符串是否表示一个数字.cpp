#include<iostream>
using namespace std;

 
//ɨ��������0-9����λ
bool scanUnsignedInteger(const char** str)
{
	const char* before = *str;
	while(**str !='\0' && **str>='0' && **str<='9')
	     ++(*str);
	return *str>before;//��ַ�������ƶ�  ������0-9����
}



//ɨ������������ſ�ͷ��0-9����λ   
bool scanInteger(const char** str)
{
	if(**str=='+' || **str=='-')
		++(*str);
	return scanUnsignedInteger(str);//ȥ�����ź� ɨ��0-9
}


/*

A[.]B[e|E]C  ����û��A  
�Ⱦ����ܶ��ɨ��0-9���п�������ʼ����'+'��'-'�� ��A����
�������С����  ���ڿ�ʼɨ��0-9                 ��B����
�������e|E, �Ϳ�ʼɨ��0-9                      ��C����

*/

bool isNumeric(const char *str)
{
	if(str==NULL)
		return false;
	bool numeric = scanInteger(&str);
	if(*str=='.')
	{
		++str;
		/*
		||��ԭ��
		С������û���������� ��.123����0.123
		С��������û������ 123.����123.0
		С����ǰ��������
		*/
		numeric = scanUnsignedInteger(&str)||numeric;
	}
	if(*str=='e' || *str=='E')
	{
		++str;
		/*
		&&��ԭ��
		e����Eǰ��û������ʱ�������ַ������ܱ�ʾ���֣� ��e1,E1
        e����E����û������ʱ��Ҳ���ܱ�ʾ����
		*/
		numeric = numeric && scanInteger(&str);
	}
	return numeric && *str=='\0';
}








int main()
{
	 

	return 0;
}

