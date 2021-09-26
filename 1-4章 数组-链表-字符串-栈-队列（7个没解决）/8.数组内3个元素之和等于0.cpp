#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<iterator>
/*
先排序  再左右夹逼 
O(n2),O(1)
*/

class Solution{ 
public:
	vector< vector<int> >threeSum(vector<int>& nums)
	{
		vector< vector<int> >result;
		if(nums.size()<3)
			return result;
		sort(nums.begin(),nums.end());
		const int target=0;
		int*  last=nums.end();
		for(int*  i=nums.begin(); i<last-2; ++i)
		{  
			int*  j=i+1; //i在原地 j首 k尾  小于目标值,或者*j==*(j-1)  j++    大于目标值 或者*k==*(k+1) j--;
			if(i>nums.begin()&&*i==*(i-1))
				continue;
			int*  k=last-1;
			while(j<k)
			{
				if(*i + *j + *k < target)
				{
					++j;
					while(* j== *(j-1) && j<k)//j后移动到与其值相等的最后一个位置  j 与 j-1 
						++j;
				}else if(*i + *j + *k > target)
				{
					--k;
					while(*k == *(k+1)&&j<k)//  k 与 k+1
						--k;
				}else
				{
					vector<int> v; v.push_back(*i);   v.push_back(*j);   v.push_back(*k); 
					result.push_back(v);
					++j;
					--k;
					while(*j == *(j-1) && *k == *(k+1)&&j<k)
						++j;	//此处只需要变动一个   j或者k			 
				}
			}
		}
		return result;
	}
        //复习时写的
		vector< vector<int> >threeSum2(vector<int>& nums )
		{	
			vector< vector<int> >result;	if(nums.size()<3)return result;
     	sort(nums.begin(),nums.end());	
	     for(int i=0; i<nums.size()-2; i++)
			{
			   if(i>0 && nums[i]== nums[i-1])//nums[i] 与nums[i-1]相等 
			      	continue;
				int second = i+1;
				int thrid = nums.size()-1;
			while(second < thrid)
			{
				if(nums[second] + nums[thrid] + nums[i]< 0)
				{
					second++;
					while(nums[second] == nums[second-1]&&second<thrid  )
						second++;
				}
				else if(nums[second] + nums[thrid] + nums[i]> 0)
				{
					thrid--;
					while(nums[thrid] == nums[thrid+1]&&second<thrid )
						thrid--;
				}
				else
				{
					vector<int>v;   v.push_back(nums[i]);  v.push_back(nums[second]);  v.push_back(nums[thrid]);
					result.push_back(v);
					second++;
					thrid--;
					if(nums[second] ==nums[second-1] && nums[thrid] ==nums[thrid+1] && second<thrid)//其它情况不用管
						second++;	 
				}
			}

			}
			return result;

		}
};








int main()
{
	vector<int>v;
	v.push_back(1);  v.push_back(3); 	v.push_back(5);  
	v.push_back(0);
	v.push_back(-1);  v.push_back(-3); 	v.push_back(-5);  
	Solution s;
	  vector< vector<int> >V= s.threeSum2(v);
	 	 for(vector< vector<int> >::iterator it0 = V.begin();  it0 != V.end();  it0++)
	 {
	 	for(vector<int>::iterator it = (*it0).begin();  it !=(*it0).end();   it++)	 
				cout<<(*it)<<"\t";				 	 
			cout<<endl;
	 }
 

	return 0;
}

