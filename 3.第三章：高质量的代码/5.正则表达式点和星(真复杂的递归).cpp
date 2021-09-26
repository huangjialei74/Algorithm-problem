#include<iostream>
using namespace std;
 
//�����⼯�ϵĽⷨ
class Solution
{
public:
	bool isMatch(const string&s,const string&p)
	{
		return isMatch2(s.c_str(), p.c_str());
	}
private:
	bool isMatch2(const char*s, const char*p)
	{
		if(*p=='\0')
			return *s=='\0';
		
		if(*(p+1)!='*')//next char is not'*', then must match current character 
		{
			if(*p==*s||(*p=='.'&&*s!='\0'))
				return isMatch2(s+1,p+1); //û��*ʱ  һ�����ж�
			else
				return false;
		}
		else
		{
			//next char is'*'
			while(*p==*s||(*p=='.'&&*s!='\0'))
			{ 
				if(isMatch2(s,p+2))//���Ƶ�����ĸ�'*'����ȥ   ��Ŀ����ʽ  û�и����ʱ��
				{   
					return  true;
				}
				s++;//Ŀ����ʽ �и����ʱ��(ÿ���ж�����λ) �����ܶ��ƥ��
			}
			return isMatch2(s, p+2);		
		}
	
	}};



//.*
bool matchCore(char* str, char* pattern)
{
	// cout<<*str<<*pattern<<"��Ƚ�          " ;
	if(*str=='\0' && *pattern=='\0')//ͬʱ����
		return true;
	if(*str!='\0' && *pattern=='\0')//ԭ��ĩβ ��������ʽ��û�е��ַ�
		return false;
	if(*(pattern+1) == '*')
	{
		if(*pattern==*str || (*pattern=='.' && *str != '\0'))
		{
			/*
	    	if(*pattern==*str ){
		          cout<<"���ʱ" <<*str<<*pattern<<endl;
			}
	    	else{
                  cout<<"�����ʱ" <<*str<<*pattern<<endl;
			}*/
			return matchCore(str+1, pattern+2)               //*pattern=='.'     .*ֻƥ��һ���ַ�   ֱ�Ӻ����
			      ||  matchCore(str+1, pattern)              //*pattern==*str     *ֻƥ��һ��   �����ܲ�����ƥ������
			      ||  matchCore(str, pattern+2) ;            //*pattern=='.'      .*  һ���ַ�Ҳ��ƥ��   ֱ�Ӻ����
		}
		else
			return matchCore(str,pattern+2) ; 
	}
	if(*str==*pattern || (*pattern=='.' && *str!='\0'))
	{
	//	cout<<"һ��ƥ��һ��"<<*str<<endl;
		return  matchCore(str+1,pattern+1) ; 
	}
	return false;
}


bool match(char* str, char* pattern)
{
	if(str == NULL || pattern == NULL)
		return false;
	return matchCore(str, pattern);
}




int main()
{
	char str[] = "3345";
	char pattern[] =".*4.";
	if(match(str,pattern))
		cout<<"ƥ��"<<endl;

	return 0;
}

