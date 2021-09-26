#include<iostream>

#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;


class Solution{
public:
	int threeSumClosest(vector<int>&nums,int target)//�����Ǹ���ӽ��ĺ�ֵ
	{
		int result=0;
		int min_gap=INT_MAX;
		sort(nums.begin(),nums.end());
		for(int  a=nums[0]; a<= nums[nums.size()-2]; ++a)//prev(iterator,n) nΪ����ʱ ����iterator����ߵ�n��λ�õ�Ԫ��
		{
			int  b= a+1 ;//a�����һ��
			int  c=   nums.size()-1;;// 
			while(b<c)
			{ 
			    int sum=nums[a]+ nums[b]+ nums[c];
		   	    int gap= sum-target ; 	
				gap = gap>0? gap:-gap;//�����ֵ����
				if(gap<min_gap)
				{
					result=sum;//����ֵ
					min_gap=gap;//��ӽ���ֵ
				}
				if(sum<target)//���������ڴ�  �ƶ������ӽ�
					++b;
				else
					--c;
			}
		}
		return result;
	}
};

















int main()
{
	 

	return 0;
}

