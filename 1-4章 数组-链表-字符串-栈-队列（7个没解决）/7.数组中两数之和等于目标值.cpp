#include<iostream>
using namespace std;
#include<vector>
#include<hash_map>

//哈希存储 每个数对应的下标 O(n)



class Solution
{
public:
	vector<int> twoSum(vector<int>&nums, int target)
	{
		hash_map<int,int>mapping;
		vector<int>result;
		for(int i=0;i<nums.size();i++)
		{
			mapping[nums[i]]=i;  //key为元素数值   value为下标
		}
		for(int i=0;i<nums.size();i++)
		{
			const int gap=target-nums[i];
			if(mapping.find(gap)!=mapping.end() && mapping[gap]>i)//index1 must be less than index2.
			{
				result.push_back(i+1);
				result.push_back(mapping[gap]+1);//返回的是下标+1
				break;
			}
		}
		return result;
	}
};












int main()
{
	 

	return 0;
}

