#include<iostream>
using namespace std;
#include<vector>
 
//��� �����Դ����ż���ε�
//O(n) O(1)
 
class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int	x=0;
		 
		for(int i = 0; i< nums.size(); i++)
		{
			x ^=nums[i];//һֱ�Ƕ�����
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

