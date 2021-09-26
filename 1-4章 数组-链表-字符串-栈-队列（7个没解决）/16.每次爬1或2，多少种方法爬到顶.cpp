#include<iostream>
using namespace std;
#include<algorithm>
#include<math.h>

//��ѧ��ʽO(1)  O(1)
class Solution
{
public:
	int climbStairs(int n)
	{
		const double s = sqrt(5);
		return floor((pow((1+s)/2, n+1) + pow((1-s)/2, n+1))/s + 0.5);
	}
};



/*
����O(n)  O(1)  --�����ȵݹ��

������n�׵�ѡ��
��n-1��ǰ��1��  ��n-1��ǰ��2��
��f(n) = f(n-1) + f(n-2)
*/


class Solution2
{
public:
	int climbStairs(int n)
	{
		int prev=0;
		int cur=1;
		for(int i=1; i<=n; ++i)// ��cur����ÿ�� ��ǰ��cur + ��һ�ε�cur
		{
			int tmp =cur;//��¼��ǰcur
			cur += prev; //��cur = ��ǰcur + ��һ�ε�cur
			prev =tmp;//��ǰcur ÿ�ζ���ֵ��prev
		}
		return cur;
	}
 
	 
};














int main()
{
	 

	return 0;
}

