#include<iostream>
using namespace std;
#include<string>
#include<stack>

//() [] {}

class Solution
{
public:
	bool isValid(string const&s)
	{
		string left="([{";
		string right=")]}";

		stack<char>stk;
		//for(auto c:s)s[i]
		for(int i = 0; i<s.length(); i++)
		{  
			if(left.find(s[i]) != string::npos)//查找字符串a是否包含子串b   string:npos是个特殊值，说明查找没有匹配
			{
				stk.push(s[i]);//入栈
			}
			else
			{   //栈为空 或者现在要入栈的家伙（是")]}"中的一个）并且栈顶元素不匹配
				if(stk.empty() || stk.top() != left[right.find(s[i])])
					return false;
				else 
					stk.pop();//匹配则出栈
			}
		}
		return stk.empty();
	}
		
};


 
int main()
{
	 

	return 0;
}

