#include<iostream>
using namespace std;
#include<string>
#include<stack>
/*
Some examples:
["2","1","+","3","*"]->((2+1)*3)->9
["4","13","5","/","+"]->(4+(13/5))->6
每一个符号表示前两个数字的运算关系

*/

  
class Solution
{
public:
	int getResult(string s)
	{
		stack<int>sta;
		for(int i = 0; i<s.size(); i++)
		{
			if(s[i]-'0'<0 || s[i]-'9'>0)//遇到运算符 必进行运算
			{
			   int result = Get(sta,s[i]); 
				sta.push(result);
			}		 
		    else//数字入栈
			{
		          sta.push(s[i]-'0');  
			}
		}
		return sta.top();//输出栈顶
	}


private:
	int Get(stack<int>&sta, char c)//传入运算符 返回结果
	{
		int a = 0 ,b = 0 ;
		b = sta.top();  sta.pop(); a = sta.top(); sta.pop(); cout<<a<<b<<endl; //取栈里面俩个数字

			if(c=='+')      return a+b;
			else if(c=='-') return a-b;
			else if(c=='*') return a*b;
			else if(c=='/') return a/b;
	}
	
};




int main()
{
	Solution s;
	cout<<s.getResult("21+3*")<<endl;
	 

	return 0;
}

