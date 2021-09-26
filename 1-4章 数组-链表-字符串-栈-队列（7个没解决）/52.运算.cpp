#include<iostream>
using namespace std;
#include<string>
#include<stack>
/*
Some examples:
["2","1","+","3","*"]->((2+1)*3)->9
["4","13","5","/","+"]->(4+(13/5))->6
ÿһ�����ű�ʾǰ�������ֵ������ϵ

*/

  
class Solution
{
public:
	int getResult(string s)
	{
		stack<int>sta;
		for(int i = 0; i<s.size(); i++)
		{
			if(s[i]-'0'<0 || s[i]-'9'>0)//��������� �ؽ�������
			{
			   int result = Get(sta,s[i]); 
				sta.push(result);
			}		 
		    else//������ջ
			{
		          sta.push(s[i]-'0');  
			}
		}
		return sta.top();//���ջ��
	}


private:
	int Get(stack<int>&sta, char c)//��������� ���ؽ��
	{
		int a = 0 ,b = 0 ;
		b = sta.top();  sta.pop(); a = sta.top(); sta.pop(); cout<<a<<b<<endl; //ȡջ������������

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

