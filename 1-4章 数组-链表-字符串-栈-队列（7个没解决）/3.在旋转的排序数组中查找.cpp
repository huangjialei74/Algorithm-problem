#include<iostream>
using namespace std;
#include<vector>
//һ����������   ��֪����ת��ʲô������
//���ֲ���  --�������ұ߽��ȷ��


// O(logn)   O(1)
class
Solution
{
public:
	int search(const vector <int> &nums,int target)
	{
		int first=0, last=nums.size();
		while(first!=last)
		{
			const int mid=first+(last-first)/2;
			if(nums[mid]==target)
				return mid;
			if(nums[first]<=nums[mid])//mid�ڵ�һ����������
			{
				if(nums[first]<=target && target<nums[mid])
					last=mid; //�÷�Χ����  �� Ŀ��ֵ�ڴ˷�Χ��
				else
				    first=mid+1;//�÷�Χ������  ��Ȼ������  ���� ����
			}
			else //mid�ڵڶ�����������
			{
				if(nums[mid]<target && target<=nums[last-1])
					first=mid+1;  //�÷�Χ����  �� Ŀ��ֵ�ڴ˷�Χ��
				else
					last=mid;//�÷�Χ������  ��Ȼ������  ���� ����    
			}
		}
		return -1;
	}
};




int main()
{
	vector<int>v;
	v.push_back(3);v.push_back(4);v.push_back(5);v.push_back(6);v.push_back(1);v.push_back(2);
	Solution s;
	cout<<s.search(v,6)<<endl;
	 

	return 0;
}

