#include<iostream>
using namespace std;
#include<vector>
#include<iterator>
#include<algorithm>


/*
[1,3,5,6],5��2
[1,3,5,6],2��1
[1,3,5,6],7��4
[1,3,5,6],0��0
*/
//O(logn) O(1)


class Solution
{
public:
	int searchInsert(vector<int>&nums, int target)
	{
		return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));//�ӿ�ͷ����һ�����ڵ���Ŀ��ֵ�ľ���
	}

	//���ֲ���
	template<typename ForwardIterator,typename T>
	ForwardIterator lower_bound(ForwardIterator first,ForwardIterator last,T value)//�����ǵ�����ָ��
	{
		while(first!=last)//ֱ��first==last  ���п��ܴ���*first=value
		{
			int* mid= first+ distance(first,last)/2 ;
			if(value > *mid)
				first = mid+1;
			else
				last=mid;
		}
		return first;
	}
	 
};

 

int main()
{
	vector<int>v;
	v.push_back(1);v.push_back(3);v.push_back(4);v.push_back(5);
	Solution s;
cout<<	s.searchInsert(v,2)<<endl;
cout<<	s.searchInsert(v,6)<<endl;
cout<<	s.searchInsert(v,5)<<endl;
	 

	return 0;
}

