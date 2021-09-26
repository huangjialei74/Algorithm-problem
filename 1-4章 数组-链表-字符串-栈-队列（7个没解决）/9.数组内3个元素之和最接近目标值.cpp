#include<iostream>

#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;


class Solution{
public:
	int threeSumClosest(vector<int>&nums,int target)//返回那个最接近的和值
	{
		int result=0;
		int min_gap=INT_MAX;
		sort(nums.begin(),nums.end());
		for(int  a=nums[0]; a<= nums[nums.size()-2]; ++a)//prev(iterator,n) n为正数时 返回iterator的左边第n个位置的元素
		{
			int  b= a+1 ;//a后面第一个
			int  c=   nums.size()-1;;// 
			while(b<c)
			{ 
			    int sum=nums[a]+ nums[b]+ nums[c];
		   	    int gap= sum-target ; 	
				gap = gap>0? gap:-gap;//求绝对值函数
				if(gap<min_gap)
				{
					result=sum;//返回值
					min_gap=gap;//最接近的值
				}
				if(sum<target)//初期误差过于大  移动至更接近
					++b;
				else
					--c;
			}
		}
		return result;
	}
};

















int main()
{
	 

	return 0;
}

