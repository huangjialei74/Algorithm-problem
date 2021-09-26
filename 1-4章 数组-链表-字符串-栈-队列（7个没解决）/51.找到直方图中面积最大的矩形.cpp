#include<iostream>
using namespace std;
#include<stack>
#include<vector>

#define max(a,b) a>b ? a:b ;


//对每个柱子 左右扩展 碰到比自己小的 就即使矩形的面积 ---会超时 O(n2)



// O(n) O(n)
class Solution
{
public:
	int largestRectangleArea(vector<int>& height)
	{
		stack<int>s;
		height.push_back(0);
		int result=0;
		for(int i=0;  i<height.size(); )
		{
		//	cout<<i<<"  "<<height[i]<<endl;
			if(s.empty() || height[i]>height[s.top()])
				//小于栈顶的元素不会入栈--这样height[tmp]*(s.empty() ? i: i-s.top()-1))可以得到栈顶元素到当前i处的面积
				s.push(i++);//i++在这里的原因是  小于栈顶就会出栈 计算一下当前到前面各处的最大值
			else{
				int tmp  =s.top();
				s.pop(); // cout<<result<<"----和----" <<height[tmp]*(s.empty() ? i: i-s.top()-1)<<endl;
				result = max(result , height[tmp]*(s.empty() ? i: i-s.top()-1));
				
			} 		
		}
		return result;
	}
};



int main()
{
	vector<int>v; v.push_back(2);  v.push_back(2); v.push_back(5); v.push_back(6); v.push_back(2); v.push_back(3);
	 Solution s;
	 cout<<s.largestRectangleArea(v)<<endl;

	 

	return 0;
}

