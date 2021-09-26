#include<iostream>
using namespace std;
#include<algorithm>
#include<math.h>

//数学公式O(1)  O(1)
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
迭代O(n)  O(1)  --迭代比递归快

爬到第n阶的选择：
从n-1阶前进1步  从n-1阶前进2步
故f(n) = f(n-1) + f(n-2)
*/


class Solution2
{
public:
	int climbStairs(int n)
	{
		int prev=0;
		int cur=1;
		for(int i=1; i<=n; ++i)// 新cur等于每次 当前的cur + 上一次的cur
		{
			int tmp =cur;//记录当前cur
			cur += prev; //新cur = 当前cur + 上一次的cur
			prev =tmp;//当前cur 每次都赋值给prev
		}
		return cur;
	}
 
	 
};














int main()
{
	 

	return 0;
}

