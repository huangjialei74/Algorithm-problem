#include<iostream>
using namespace std;
#include<vector>
//没搞明白



/*
count[i]表示在第i位上出现1的次数，如果count[i]是3的整数倍 则忽略  否则取出该位组成答案
*/
class Solution
{
public:
	int singleNumber(vector<int>&nums)//1211232
	{
		const int W = sizeof(int)*8;//32
		int  count[W];	 
		fill_n(&count[0], W, 0);
		int i,j;
		for(i=0; i<nums.size(); i++)
		{
			for( j=0; j<W; j++)
			{
				count[j] += (nums[i] >> j) & 1;//左移 再 &1能保证只在第j位上留下一个1
				count[j] %= 3;//count[]是3的整数倍 则忽略
			}
		}
		  
		int result=0;
		for( j=0; j<W; j++)//将其还原
		{
			result +=(count[j]<<j); 
		}
		return result;
	}
		 
};



//O(n) O(1)
class Solution2
{
public:
	int singleNumber(vector<int>&nums)
	{
		int one=0, two=0, three=0;
		for(int i = 0; i< nums.size(); i++)
		{
			two |= (one & nums[i]);
			one ^= nums[i];
			three =~ (one & two);
			one &= three;
			two &= three;
		}
		return one;
	}
};




int main()
{
	 vector<int> v1;
	 v1.push_back(1);  v1.push_back(2);  v1.push_back(1);  v1.push_back(1);  
	 v1.push_back(2);  v1.push_back(3);  v1.push_back(2);  
	 Solution s;
	  cout<<" 单个元素是====="<<s.singleNumber(v1)<<endl;
 

	return 0;
}

