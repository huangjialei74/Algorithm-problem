#include<iostream>
using namespace std;


/*  
 '*'  与上题不同  匹配任何序列（包括空序列）
 '?'  匹配任意字符
*/
//isMatch("ab","?*")→true


//递归版 超时了
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




//迭代版
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
			 	while(*p=='*')//'*'  匹配任何序列  单独出现 发挥作用
					p++; 
				if(*p=='\0')
					return true;
				str=s-1;//往前一个  因为*可能匹配了不应该匹配的字符  //例如：123b  *b ： 1和*匹配后 正则还没结束  str ptr都还原   
				ptr=p-1;
			//	cout<<*str<<"   "<<*ptr<<endl;
				break;
			default:
				if(*str != *ptr)
				{						
					if(!star) //前面的循环 要是匹配到了*   此处就等着s中出现 和p相等的元素  没有才false
						return false;
					s++;
					str=s-1;
					ptr=p-1;
					cout<<*str<<"   "<<*ptr<<endl;
				}
				//例如：123b  *b最后一个相等   结束循环  p结束 OK
			}
		}
		while(*ptr=='*')//s结束了 p还没结束 时
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

