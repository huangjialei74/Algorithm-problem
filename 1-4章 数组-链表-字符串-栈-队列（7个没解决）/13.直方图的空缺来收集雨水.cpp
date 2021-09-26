#include<iostream>
using namespace std;
#include<vector>
/*
例如010中间是1突出部分  收集不了
101中间是0凹入部分  可以收集1
*/


/*
先扫描一遍 获取最高点
处理左边
处理右边
O(n) O(1)
*/

class Solution
{
public:
	int trap(const vector<int>&A)
	{
		const int n=A.size();
		int max=0,i,peak,top; 
		for(i=0; i<n; i++)
			if(A[i]>A[max])
				max=i; 

		int water=0;
		//最高点左边
		for(i=0,peak=0;  i<max;  i++)
			if(A[i]>peak)//peak是左边的界限的最高处 取大值
				peak=A[i];
			else               
				water += peak-A[i]; //小于就收集  用之前赋值而来的最高点减去 该点   

		//最高点右边
		for(i=n-1,top=0;  i>max;  i--)
			if(A[i]>top)//top是右边界限的最高处 取大值
				top=A[i];
			else
				water += top-A[i];
		return water;
	}
	//自己写的玩：
	int getWater(int nums[],int n)
	{
		int water = 0 ;
		int max = 0;
		int i;
		for(i=0; i<n; i++)
			if(nums[i]>nums[max]) max = i;

		int leftHighest = 0;
		for(i=0; i<max; i++)
		{
			if(nums[i]>leftHighest)
                 leftHighest = nums[i];
			else
			water += leftHighest-nums[i];
		}

        int rightHighest = 0;
		for(i=n-1; i>max; i--)
		{ 
			if(nums[i]>rightHighest)
                 rightHighest = nums[i];
			else
			water += rightHighest-nums[i];
		} 
		return water;
	}
};
















int main()
{
	 Solution s;
	 vector<int> v1 ;
	 int a[11] = { 0,1,0,2,1,0,1,3,2,1,2};
	 for(int i = 0;i<11;i++) v1.push_back(a[i]);
	 cout<<s.getWater(a,11)<<endl;

	return 0;
}

