#include<iostream>
using namespace std;  
 

class Solution 
{
public:
	bool VerifySequenceOfBST(int sequence[], int length)
	{
		if(sequence==NULL || length<=0 )
			return false;
		int root=sequence[length-1];
		int i = 0;��
		for(; i<length-1; i++)
		{
			if(sequence[i]>root)//����i����������
				break;
		}
		for(int j=i; j<length-1; j++)//��������Ҫ���б�rootС��ֵ  �Ͳ���Ҫ��
		{
			if(sequence[j]<root)
				return false;
		}
		bool left=true;
		if(i>0)
			left=VerifySequenceOfBST(sequence, i); //����Ϊi
		bool right=true;
		if(i<length-1)
			right=VerifySequenceOfBST(sequence+i, length-i-1);//sequence+i�ж�������
		return (left && right); 
	}
 
};








 

//������
int main()
{
  
	Solution s;
	int arr[]={5,7,6,9,11,10,8};
	if(s.VerifySequenceOfBST(arr,7))
		cout<<"YES"<<endl;
	 


 
 
	return 0;
}
  



