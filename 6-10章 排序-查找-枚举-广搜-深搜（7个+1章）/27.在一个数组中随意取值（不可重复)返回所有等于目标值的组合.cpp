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
     static void dfs(const vector<int>&nums, vector<int>&path, vector< vector<int> >&result, int gap,int start)
	 {
		 if(gap==0)
		 {
			 result.push_back(path);
			 return;
		 }
		 
		 int previous=-1;//记录前一个nums[i]
		 for(size_t i=start; i<nums.size(); i++)
		 {
			  if(previous==nums[i])    continue;//前一个nums[i] 不能与当前的nums[i]相等
			  if(gap<nums[i])	  return;			  

			  previous=nums[i];
			  path.push_back(nums[i]);
			  dfs(nums, path, result, gap-nums[i], i+1); //下一次的起点 从i+1开始, 避免重复
			  path.pop_back();
			  
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

