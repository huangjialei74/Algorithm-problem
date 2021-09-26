#include<iostream>
using namespace std;
#include<stack>
#include<vector>

#define max(a,b) a>b ? a:b ;


//��ÿ������ ������չ �������Լ�С�� �ͼ�ʹ���ε���� ---�ᳬʱ O(n2)



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
				//С��ջ����Ԫ�ز�����ջ--����height[tmp]*(s.empty() ? i: i-s.top()-1))���Եõ�ջ��Ԫ�ص���ǰi�������
				s.push(i++);//i++�������ԭ����  С��ջ���ͻ��ջ ����һ�µ�ǰ��ǰ����������ֵ
			else{
				int tmp  =s.top();
				s.pop(); // cout<<result<<"----��----" <<height[tmp]*(s.empty() ? i: i-s.top()-1)<<endl;
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

