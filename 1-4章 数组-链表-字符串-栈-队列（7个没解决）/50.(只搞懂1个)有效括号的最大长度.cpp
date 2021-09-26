#include<iostream>
using namespace std;
#include<string>
#include<stack>
#include<vector>

#define max(a,b) a>b? a:b;

// 都是() 小括号

//使用栈
//O(n) O(n)
class Solution
{
public:
	int longestValidParentheses(const string&s)
	{
		int max_len=0, last=-1; //last初始值-1
		stack<int>lefts; 
		for(int i=0; i<s.size(); ++i)
		{
			if(s[i]=='(')
			{
				lefts.push(i);
			}
			else
			{
				if(lefts.empty())//no matching left
				{
					last=i;
				}
				else
				{//find a matching pair 
					lefts.pop();
					if(lefts.empty())
					{
						max_len =max(max_len, i-last);//出栈后空则 减去last
				        cout<<"空"<<max_len<<endl;
					}
					else
					{
						max_len =max(max_len, i-lefts.top());//出栈后非空则 减去栈顶数字	 
						cout<<"非空"<<max_len<<endl;
					}
				}
			}
		}
		return max_len;
	}
	 
};

//Dynamic Programming   O(n)  O(n)
class Solution2
{
public:
	int longestValidParentheses(const string&s)//   (((()
	{
		vector<int>f(s.size(), 0);
		int ret=0;
		for(int i=s.size()-2; i>=0;  --i)
		{
			int match = i+f[i+1]+1;  //case:"((...))"
			if(s[i]=='(' && match<s.size() && s[match]==')' )
			{
				f[i]=f[i+1]+2;//他的后面长度为2 
				//if a valid sequence exist after wards"((...))()"
				if(match+1 < s.size())
					f[i] += f[match+1];
			}
			ret=max(ret,f[i]);
		}
		return ret;
	}
};




//两遍扫描  O(n)   O(1)
class Solution3
{
public:
	int longestValidParentheses(const string&s)
	{
		int answer=0, depth=0, start=-1;
		for(int i=0; i<s.size(); ++i)
		{
			if(s[i]=='(')
			{
				++depth;
			}
			else
			{
				--depth;
				if(depth<0)
				{
					start=i;//保存
					depth=0;//更换
				}
				else if(depth==0)//  ( 和 )次数相等时才会 赋值  才是匹配的
				{
					answer=max(answer, i-start);
				} 
			}				
		}
		cout<<answer<<endl;
		depth=0;
		start=s.size();
		for(int j =s.size()-1; j>=0; --j)
		{
			if(s[j]==')')
			{
				++depth;
			}
			else
			{
				--depth;
				if(depth<0)
				{
					start=j;
					depth=0;
				}
				else if(depth==0)
				{
					answer=max(answer,start-j);
				}
			}
		}
		return answer;
	}
};






int main()
{
	 Solution s;
  	 cout<<s.longestValidParentheses("((())))")<<endl;

	return 0;
}

