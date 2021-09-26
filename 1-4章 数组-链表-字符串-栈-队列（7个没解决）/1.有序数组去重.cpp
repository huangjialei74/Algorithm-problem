#include<iostream>
using namespace std;
#include<vector> 

//ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1) 
 
class Solution1
{
public:
	int removeDuplicates(vector<int>&nums)
	{
		if(nums.empty())
			return 0;
		int index=0;//����           index��ʼΪ0�ͺ���   ��ʼΪ1��ǰ��
		for(int i=1;i<nums.size();i++)
		{
			if(nums[index]!=nums[i])
				nums[++index]=nums[i];//����Ⱦ��Ͽɸ���  ��֮���Ͽ�
		}
		return index+1;
	}
};

/*
 // ʹ��STL 
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

