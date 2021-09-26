#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
For example,given candidate set2,3,6,7 and target 7,
A solution setis:[7][2,2,3]
*/


// O(n!) O(n)
class Solution
{
public:
	vector< vector<int> >combinationSum(vector<int>&nums, int target)
	{
		sort(nums.begin(), nums.end());
		vector< vector<int> >result;
		vector<int>path;
		dfs(nums, path, result, target, 0);
		return result;
	}
private:
	void dfs(vector<int>&nums, vector<int>&path, vector< vector<int> >&result, int gap,int start)
	{
		if(gap==0)//�ҵ��Ϸ���
		{
			 result.push_back(path);
			 return;
		}
		for(size_t i=start; i<nums.size(); i++)
		{
		   if(gap<nums[i])   return;//���Ҳ����Ϻ�Ҫ���nums[i]��----����Ҫ�� ��֦
		   path.push_back(nums[i]);//�����ҵõ�
		   dfs(nums, path, result, gap-nums[i], i);//gap-nums[i] �� i��ʾ�´λ������start��ʼ
		   path.pop_back();//����
		}
	}
};














int main()
{
	 vector<int>v;  v.push_back(2);  v.push_back(3);  v.push_back(6); v.push_back(7);
	Solution  s;
	 vector< vector<int> > V = s.combinationSum(v,7);
 
	 for(vector< vector<int> >::iterator it0 = V.begin();  it0 != V.end();  it0++)
	 {
	 	for(vector<int>::iterator it = (*it0).begin();  it !=(*it0).end();   it++)	 
				cout<<(*it)<<"\t";				 	 
			cout<<endl;
	 }
 

	return 0;
}

