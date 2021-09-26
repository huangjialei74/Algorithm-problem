#include<iostream>
using namespace std;
#include<vector>
/*
����010�м���1ͻ������  �ռ�����
101�м���0���벿��  �����ռ�1
*/


/*
��ɨ��һ�� ��ȡ��ߵ�
�������
�����ұ�
O(n) O(1)
*/

class Solution
{
public:
	int trap(const vector<int>&A)
	{
		const int n=A.size();
		int max=0,i,peak,top; 
		for(i=0; i<n; i++)
			if(A[i]>A[max])
				max=i; 

		int water=0;
		//��ߵ����
		for(i=0,peak=0;  i<max;  i++)
			if(A[i]>peak)//peak����ߵĽ��޵���ߴ� ȡ��ֵ
				peak=A[i];
			else               
				water += peak-A[i]; //С�ھ��ռ�  ��֮ǰ��ֵ��������ߵ��ȥ �õ�   

		//��ߵ��ұ�
		for(i=n-1,top=0;  i>max;  i--)
			if(A[i]>top)//top���ұ߽��޵���ߴ� ȡ��ֵ
				top=A[i];
			else
				water += top-A[i];
		return water;
	}
	//�Լ�д���棺
	int getWater(int nums[],int n)
	{
		int water = 0 ;
		int max = 0;
		int i;
		for(i=0; i<n; i++)
			if(nums[i]>nums[max]) max = i;

		int leftHighest = 0;
		for(i=0; i<max; i++)
		{
			if(nums[i]>leftHighest)
                 leftHighest = nums[i];
			else
			water += leftHighest-nums[i];
		}

        int rightHighest = 0;
		for(i=n-1; i>max; i--)
		{ 
			if(nums[i]>rightHighest)
                 rightHighest = nums[i];
			else
			water += rightHighest-nums[i];
		} 
		return water;
	}
};
















int main()
{
	 Solution s;
	 vector<int> v1 ;
	 int a[11] = { 0,1,0,2,1,0,1,3,2,1,2};
	 for(int i = 0;i<11;i++) v1.push_back(a[i]);
	 cout<<s.getWater(a,11)<<endl;

	return 0;
}

