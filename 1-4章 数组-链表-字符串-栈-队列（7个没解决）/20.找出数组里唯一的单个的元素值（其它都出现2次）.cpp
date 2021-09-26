#include<iostream>
using namespace std;
#include<vector>
 
//异或 还可以处理掉偶数次的
//O(n) O(1)
 
class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int	x=0;
		 
		for(int i = 0; i< nums.size(); i++)
		{
			x ^=nums[i];//一直是二进制
	    	cout<<x<<endl;
		}		
		return x;
	}
};
 
 

 

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);  v.push_back(1);  v.push_back(2);  v.push_back(3);  v.push_back(2); v.push_back(3);
	 v.push_back(5); v.push_back(5);
	 cout<<s.singleNumber(v);
	 

	return 0;
}

