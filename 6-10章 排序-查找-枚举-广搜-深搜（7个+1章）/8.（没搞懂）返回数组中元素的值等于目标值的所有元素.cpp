#include<iostream>
using namespace std; 
#include<vector>
#include<algorithm>
#include <iterator> 

//排序数组

/*
//使用STL的lower_bound()   upper_bound()
// O(logn)  O(1)
class Solution
{
public:
	vector<int>searchRange(vector<int>&nums,int target)
	{
		const int l=distance(nums.begin(), lower_bound(nums.begin(), nums.end(),target));//lower_bound返回一个非递减序列[first, last)中的第一个大于等于值val的位置。
		const int u=distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));//upper_bound返回一个非递减序列[first, last)中第一个大于val的位置。
		if(nums[l]!=target){//not found			
			vector<int>v; v.push_back (-1); v.push_back(-1); return v;
		}
		else{ 		
			vector<int>v; v.push_back (l); v.push_back(u); return v;
		}
	}
};

*/



//重现lower_bound和 upper_bound
class Solution2
{
	 public:
		 vector<int>searchRange(vector<int>&nums, int target)
		 {
			 int * lower=lower_bound(nums.begin(), nums.end(), target);
			 int * uppper=upper_bound(lower, nums.end(), target);
			 if(lower==nums.end()||*lower!=target)
			 {
				 	vector<int>v; v.push_back (-1); v.push_back(-1); return v;
			 }
			 else
			 {
				 	vector<int>v;  v.push_back (distance(nums.begin(), lower)); v.push_back(distance(nums.begin(), uppper)-1);
					return v;
			 }			 
		 }

		 template<typename ForwardIterator,typename T>
		 ForwardIterator lower_bound(ForwardIterator first,ForwardIterator last,T value)//第一个大于等于值val的位置。
		 {
			 while(first!=last)
			 {
				 int* mid= first+ distance(first,last)/2 ;
				 if(value>*mid)//二分查找
					 first=++mid;
				 else
					 last=mid;
			 }
			 return first;
		 }
		template<typename ForwardIterator,typename T>
		ForwardIterator upper_bound(ForwardIterator first,ForwardIterator last,T value)//第一个大于val的位置。
		 {
			 while(first!=last)
			 {
				 int *mid= first+ distance(first,last)/2 ;
				 if(value>=*mid)
					 first=++mid;
				  else
					  last=mid;
			 }
			 return first;
		 }
};











int main()
{
	 

	return 0;
}

