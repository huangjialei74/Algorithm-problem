#include<iostream>
using namespace std;


/*  
 '*'  �����ⲻͬ  ƥ���κ����У����������У�
 '?'  ƥ�������ַ�
*/
//isMatch("ab","?*")��true


//�ݹ�� ��ʱ��
// O(n!*m!) O(n)
class Solution
{
public:
	bool isMatch(const string&s,const string&p)
	{
		return isMatch2(s.c_str(), p.c_str());
	}
private:
	bool isMatch2(const char*s,const char*p)
	{
		if(*p=='*')
		{
			while(*p=='*')
				++p; 
			if(*p=='\0') 
				return true;
			while(*s != '\0'&& !isMatch2(s,p))
				++s;
			return *s!='\0';
		}
		else if(*p=='\0'||*s=='\0')
			return *p==*s;
		else if(*p==*s||*p=='?')
			return isMatch2(++s,++p);
		else 
			return false;
	}
};




//������
// O(n*m)  O(1)
class Solution2
{
public:
	bool isMatch(const string&s,const string&p)
	{
		return isMatch2(s.c_str(),p.c_str());
	}
private:
	bool isMatch2(const char*s,const char*p)
	{
		bool star=false;
		const char*str, *ptr;
		for(str=s,ptr=p; *str!='\0'; str++, ptr++)
		{
			switch(*ptr) 
			{
			case'?':
				break;
			case'*':
				star=true;
				s=str, p=ptr;  
			 	while(*p=='*')//'*'  ƥ���κ�����  �������� ��������
					p++; 
				if(*p=='\0')
					return true;
				str=s-1;//��ǰһ��  ��Ϊ*����ƥ���˲�Ӧ��ƥ����ַ�  //���磺123b  *b �� 1��*ƥ��� ����û����  str ptr����ԭ   
				ptr=p-1;
			//	cout<<*str<<"   "<<*ptr<<endl;
				break;
			default:
				if(*str != *ptr)
				{						
					if(!star) //ǰ���ѭ�� Ҫ��ƥ�䵽��*   �˴��͵���s�г��� ��p��ȵ�Ԫ��  û�в�false
						return false;
					s++;
					str=s-1;
					ptr=p-1;
					cout<<*str<<"   "<<*ptr<<endl;
				}
				//���磺123b  *b���һ�����   ����ѭ��  p���� OK
			}
		}
		while(*ptr=='*')//s������ p��û���� ʱ
			ptr++;
		return(*ptr=='\0');
	}
};








int main()
{
	Solution2 s;
	if(s.isMatch("123b", "*b"))
		cout<<"Yes"<<endl;
	else
	    cout<<"False"<<endl;
	 

	return 0;
}

