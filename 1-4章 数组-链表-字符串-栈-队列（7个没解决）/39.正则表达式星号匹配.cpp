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
			return *s=='\0';//递归结束条件
		
		if(*(p+1)!='*') //next char is not'*', then must match current character 
		{
			if(*p==*s||(*p=='.'&&*s!='\0'))
				return isMatch2(s+1,p+1); //没有*时  一个个判断
			else
				return false;
		}
		else//next char is'*'
		{			
			while(*p==*s||(*p=='.'&&*s!='\0'))
			{ 
				if(isMatch2(s,p+2))//后移到正则的该'*'后面去   当目标表达式  没有该项的时候
				{   
					return  true;
				}
				s++;//目标表达式 有该项的时候(每次判断其首位)  尽可能多的匹配
			}
			return isMatch2(s, p+2);//上式p* 匹配消耗了s ,现在p+2		
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

