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
			if(left.find(s[i]) != string::npos)//�����ַ���a�Ƿ�����Ӵ�b   string:npos�Ǹ�����ֵ��˵������û��ƥ��
			{
				stk.push(s[i]);//��ջ
			}
			else
			{   //ջΪ�� ��������Ҫ��ջ�ļһ��")]}"�е�һ��������ջ��Ԫ�ز�ƥ��
				if(stk.empty() || stk.top() != left[right.find(s[i])])
					return false;
				else 
					stk.pop();//ƥ�����ջ
			}
		}
		return stk.empty();
	}
		
};


 
int main()
{
	 

	return 0;
}

