#include<iostream>
using namespace std;
#include<vector>
//û������



/*
count[i]��ʾ�ڵ�iλ�ϳ���1�Ĵ��������count[i]��3�������� �����  ����ȡ����λ��ɴ�
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
				count[j] += (nums[i] >> j) & 1;//���� �� &1�ܱ�ֻ֤�ڵ�jλ������һ��1
				count[j] %= 3;//count[]��3�������� �����
			}
		}
		  
		int result=0;
		for( j=0; j<W; j++)//���仹ԭ
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
	  cout<<" ����Ԫ����====="<<s.singleNumber(v1)<<endl;
 

	return 0;
}

