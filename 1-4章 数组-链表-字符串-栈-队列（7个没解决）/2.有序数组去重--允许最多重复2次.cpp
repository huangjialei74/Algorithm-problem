#include<iostream>
using namespace std;
#include<vector>
 
//��չ�Ժ�  index-2��Ϊ ����ظ�3��
class Solution1
{ 
public:
	int removeDuplicates(vector<int>&nums)
	{
		if(nums.size()<=2) 
			return nums.size();
		int index=2; //index��ֵȡ2    ����   (index���ܴ�1 ��ʼ  ǰ��)
		for(int i=2;i<nums.size();i++) 
		{
			if(nums[i]!=nums[index-2])//�˴��Ǻ�index-2�Ƚ�
				nums[index++]=nums[i];
		 
		}
		for(int j = index-1; j<nums.size();j++)
		nums.pop_back();
		return index;
	}
};


 //�Լ�� 
class Solution2
{
public:
	int removeDuplicates(vector<int>&nums)
	{
		const int n=nums.size();
		int index=0;
		for(int i=0;i<n;++i)
		{
			if(i>0 && i<n-1 && nums[i]==nums[i-1] && nums[i]==nums[i+1])
				continue;
			nums[index++]=nums[i];
		}
		return index;
	}
};







int main()
{
	vector<int>v1 ;

	v1.push_back(1);
	v1.push_back(2);
 
	v1.push_back(3);v1.push_back(3);v1.push_back(3);
	v1.push_back(4);
	v1.push_back(4); 	v1.push_back(5);v1.push_back(5);v1.push_back(5);
	Solution1 s1;
	cout<<s1.removeDuplicates(v1)<<endl;

 	for(vector<int>::iterator it =v1.begin();it!=v1.end();it++)
 		cout<<(*it)<<" ";

	 

	return 0;
}

