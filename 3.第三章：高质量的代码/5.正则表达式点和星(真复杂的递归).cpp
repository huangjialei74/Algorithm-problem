#include<iostream>
using namespace std;
 
//力扣题集上的解法
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
				return isMatch2(s+1,p+1); //没有*时  一个个判断
			else
				return false;
		}
		else
		{
			//next char is'*'
			while(*p==*s||(*p=='.'&&*s!='\0'))
			{ 
				if(isMatch2(s,p+2))//后移到正则的该'*'后面去   当目标表达式  没有该项的时候
				{   
					return  true;
				}
				s++;//目标表达式 有该项的时候(每次判断其首位) 尽可能多的匹配
			}
			return isMatch2(s, p+2);		
		}
	
	}};



//.*
bool matchCore(char* str, char* pattern)
{
	// cout<<*str<<*pattern<<"相比较          " ;
	if(*str=='\0' && *pattern=='\0')//同时结束
		return true;
	if(*str!='\0' && *pattern=='\0')//原句末尾 有正则表达式中没有的字符
		return false;
	if(*(pattern+1) == '*')
	{
		if(*pattern==*str || (*pattern=='.' && *str != '\0'))
		{
			/*
	    	if(*pattern==*str ){
		          cout<<"相等时" <<*str<<*pattern<<endl;
			}
	    	else{
                  cout<<"不相等时" <<*str<<*pattern<<endl;
			}*/
			return matchCore(str+1, pattern+2)               //*pattern=='.'     .*只匹配一个字符   直接后面的
			      ||  matchCore(str+1, pattern)              //*pattern==*str     *只匹配一个   试试能不能再匹配后面的
			      ||  matchCore(str, pattern+2) ;            //*pattern=='.'      .*  一个字符也不匹配   直接后面的
		}
		else
			return matchCore(str,pattern+2) ; 
	}
	if(*str==*pattern || (*pattern=='.' && *str!='\0'))
	{
	//	cout<<"一个匹配一个"<<*str<<endl;
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
		cout<<"匹配"<<endl;

	return 0;
}

