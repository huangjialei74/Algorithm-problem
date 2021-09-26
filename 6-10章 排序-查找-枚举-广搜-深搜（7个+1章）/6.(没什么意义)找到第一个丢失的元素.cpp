#include<iostream>
using namespace std;

#include<vector>
 
 //一个没排序的数组   找到他排序状态时丢失的一个元素
//For example,Given[1,2,0] return 3,and[3,4,-1,1] return2.

//桶排序 
//A[i]!=i+1  A[i]与A[A[i]-1]交换  直到无法交换为止，终止条件是  A[i]==A[A[i]-1] 
// O(n)   O(1)
class Solution
{
public:
	int firstMissingPositive(vector<int>&nums)
	{
		bucket_sort(nums);//桶排序
		 for(vector<int>::iterator it = nums.begin();it != nums.end();it++) cout<<(*it)<<endl;
		for(int i=0; i<nums.size(); ++i)//只能找出缺少的正数
			if(nums[i]!=(i+1))
				return i+1;
		return nums.size()+1;
	}
private:
	static void bucket_sort(vector<int>&A)
	{
		const int n=A.size();//n个数  最大值 最小值 范围划定为1-n
		for(int i=0; i<n; i++)
		{
			while(A[i]!=i+1)
			{
				if(A[i]<=0||A[i]>n||A[i]==A[A[i]-1])// 会导致出界 或者原本就相同
					break;
				swap(A[i],A[A[i]-1]);			
			}
		}
	}
};



 

int main()
{
	 vector<int>v;
	 v.push_back(5);v.push_back(4);v.push_back(-1);v.push_back(3);

	 Solution s;
	 cout<< s.firstMissingPositive(v)<<endl;
	 

	return 0;
}

