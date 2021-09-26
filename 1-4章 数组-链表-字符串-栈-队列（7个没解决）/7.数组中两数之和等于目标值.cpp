#include<iostream>
using namespace std;
#include<vector>
#include<hash_map>

//��ϣ�洢 ÿ������Ӧ���±� O(n)



class Solution
{
public:
	vector<int> twoSum(vector<int>&nums, int target)
	{
		hash_map<int,int>mapping;
		vector<int>result;
		for(int i=0;i<nums.size();i++)
		{
			mapping[nums[i]]=i;  //keyΪԪ����ֵ   valueΪ�±�
		}
		for(int i=0;i<nums.size();i++)
		{
			const int gap=target-nums[i];
			if(mapping.find(gap)!=mapping.end() && mapping[gap]>i)//index1 must be less than index2.
			{
				result.push_back(i+1);
				result.push_back(mapping[gap]+1);//���ص����±�+1
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

