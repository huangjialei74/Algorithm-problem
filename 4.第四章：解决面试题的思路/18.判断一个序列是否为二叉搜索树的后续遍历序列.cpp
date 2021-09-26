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
		int i = 0;，
		for(; i<length-1; i++)
		{
			if(sequence[i]>root)//坐标i坐标是左树
				break;
		}
		for(int j=i; j<length-1; j++)//右子树中要是有比root小的值  就不符要求
		{
			if(sequence[j]<root)
				return false;
		}
		bool left=true;
		if(i>0)
			left=VerifySequenceOfBST(sequence, i); //长度为i
		bool right=true;
		if(i<length-1)
			right=VerifySequenceOfBST(sequence+i, length-i-1);//sequence+i判断右子树
		return (left && right); 
	}
 
};








 

//主函数
int main()
{
  
	Solution s;
	int arr[]={5,7,6,9,11,10,8};
	if(s.VerifySequenceOfBST(arr,7))
		cout<<"YES"<<endl;
	 


 
 
	return 0;
}
  



