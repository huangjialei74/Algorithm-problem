#include<iostream>
using namespace std;

#include<vector>
 
 //һ��û���������   �ҵ�������״̬ʱ��ʧ��һ��Ԫ��
//For example,Given[1,2,0] return 3,and[3,4,-1,1] return2.

//Ͱ���� 
//A[i]!=i+1  A[i]��A[A[i]-1]����  ֱ���޷�����Ϊֹ����ֹ������  A[i]==A[A[i]-1] 
// O(n)   O(1)
class Solution
{
public:
	int firstMissingPositive(vector<int>&nums)
	{
		bucket_sort(nums);//Ͱ����
		 for(vector<int>::iterator it = nums.begin();it != nums.end();it++) cout<<(*it)<<endl;
		for(int i=0; i<nums.size(); ++i)//ֻ���ҳ�ȱ�ٵ�����
			if(nums[i]!=(i+1))
				return i+1;
		return nums.size()+1;
	}
private:
	static void bucket_sort(vector<int>&A)
	{
		const int n=A.size();//n����  ���ֵ ��Сֵ ��Χ����Ϊ1-n
		for(int i=0; i<n; i++)
		{
			while(A[i]!=i+1)
			{
				if(A[i]<=0||A[i]>n||A[i]==A[A[i]-1])// �ᵼ�³��� ����ԭ������ͬ
					break;
				swap(A[i],A[A[i]-1]);			
			}
		}
	}
};



 

int main()
{
	 vector<int>v;
	 v.push_back(5);v.push_back(4);v.push_back(-1);v.push_back(3);

	 Solution s;
	 cout<< s.firstMissingPositive(v)<<endl;
	 

	return 0;
}

