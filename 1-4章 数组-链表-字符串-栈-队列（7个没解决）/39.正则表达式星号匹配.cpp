#include<iostream>
using namespace std;




/*
'.'Matches any single character.  
 '*'Matches zero or more of the preceding element.
*/


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
			return *s=='\0';//�ݹ��������
		
		if(*(p+1)!='*') //next char is not'*', then must match current character 
		{
			if(*p==*s||(*p=='.'&&*s!='\0'))
				return isMatch2(s+1,p+1); //û��*ʱ  һ�����ж�
			else
				return false;
		}
		else//next char is'*'
		{			
			while(*p==*s||(*p=='.'&&*s!='\0'))
			{ 
				if(isMatch2(s,p+2))//���Ƶ�����ĸ�'*'����ȥ   ��Ŀ����ʽ  û�и����ʱ��
				{   
					return  true;
				}
				s++;//Ŀ����ʽ �и����ʱ��(ÿ���ж�����λ)  �����ܶ��ƥ��
			}
			return isMatch2(s, p+2);//��ʽp* ƥ��������s ,����p+2		
		}
	
	}
};












int main()
{
	Solution s;
	if(s.isMatch("ccccaaaa","c*aaaa"))
		cout<<"Yes"<<endl;
	 

	return 0;
}

