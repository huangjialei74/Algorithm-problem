#include<iostream>
using namespace std;
#include<vector>


// O(m+n) O(1)
class Solution
{
public:
	void merge(int A[],int m, int B[],int n)
	{
		int ia=m-1,ib=n-1,icur=m+n-1;
		while(ia>=0 && ib>=0)//双指针a，b   从数组A尾部开始 添加--从前面添加会产生挪动
		{
			A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
		}
		//B先结束就直接整合完毕
		while(ib>=0)//A全部插入到后面了  B还有剩余
		{
			A[icur--]=B[ib--];
		}
	}
 
};


 



int main()
{/*
	vector<int> A;
	A.push_back(1); 	A.push_back(2); 	A.push_back(3); 	A.push_back(4); 	A.push_back(5); 	A.push_back(6);
	 vector<int> B;
	B.push_back(1); 	B.push_back(2); 	B.push_back(3); 	B.push_back(4); 	B.push_back(5); 	B.push_back(6);
	
*/
	int A[12] = {1,2,3,4,5,6};int B[5] = {1,2,3,4,5 };
	
	Solution s;
	s.merge(A,6,B,5);

	for(int i = 0; i<sizeof(A)/sizeof(A[0]); i++) cout<<A[i]<<"  ";

	return 0;
}

