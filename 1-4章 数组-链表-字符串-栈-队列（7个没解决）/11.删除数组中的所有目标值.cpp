 #include<iostream>
using namespace std;
#include<vector>


class Solution1
{
public:
	int removeElement(vector<int>&nums, int target)
	{
		int index=0;
		for(int i=0; i<nums.size(); ++i)
		{
			if(nums[i]!=target)
			{
				nums[index++]=nums[i];
			}
		}
		return index;
	}
	 
};


/*
//使用了remove函数
class Solution{
public:
	int removeElement(vector<int>&nums, int target)
	{
		return distance(nums.begin(), remove(nums.begin(), nums.end(), target));
	}
};
*/












int main()
{
	 

	return 0;
}

