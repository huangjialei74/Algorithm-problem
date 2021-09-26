#include<iostream>
using namespace std;
#include<vector> 

//时间复杂度O(n) 空间复杂度O(1) 
 
class Solution1
{
public:
	int removeDuplicates(vector<int>&nums)
	{
		if(nums.empty())
			return 0;
		int index=0;//长度           index初始为0就后增   初始为1就前增
		for(int i=1;i<nums.size();i++)
		{
			if(nums[index]!=nums[i])
				nums[++index]=nums[i];//不相等就认可该数  反之不认可
		}
		return index+1;
	}
};

/*
 // 使用STL 
class Solution2
{
public:
	int removeDuplicates(vector<int>&nums)
	{
		return distance(nums.begin(), unique(nums.begin(), nums.end()));
	}
};

*/
int main()
{
	vector<int>v1 ;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);

	Solution1 s1;
	cout<<s1.removeDuplicates(v1)<<endl;

	 

	return 0;
}

