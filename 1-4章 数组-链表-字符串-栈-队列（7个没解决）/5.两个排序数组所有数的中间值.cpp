#include<iostream>
using namespace std;
#include<vector>

#define min(a,b)((a)<=(b)?(a):(b))
/*
计数器 记录当前找了 第m大的数 
pA pB指向两数组
*/


//充分利用有序 
/*
假设A B 都有k/2个元素  将  A[k/2-1]与 B[k/2-1]相比
A[k/2-1]< B[k/2-1] 时 前K个元素必包括  所有的 A:0-k/2-1 --->  第k个元素 可能在A的k/2-1后面一点 或者   B:0-k/2-1 内   于是删掉A:0-k/2-1
A[k/2-1]与 B[k/2-1]         删掉B:0-k/2-1
A[k/2-1]与 B[k/2-1]   返回 A[k/2-1]或 B[k/2-1]
*/

class Solution
{
public:
	double findMedianSortedArrays(const vector<int>&A,const vector<int>&B)
	{
		const int m=A.size();
		const int n=B.size();
		int total=m+n;
		if(total & 0x1)
			return find_kth(A.begin(), m, B.begin(), n, total/2+1); //总数为奇数
		else 
			return(find_kth(A.begin(), m, B.begin(), n, total/2) + 
			       find_kth(A.begin(), m, B.begin(), n, total/2+1)) /2.0;//偶数
	}
private:
	static int find_kth(vector<int>::const_iterator A,int m, vector<int>::const_iterator B,int n,int k)
	{ // m=A.size(); n=B.size(); 
	  /*极限情况： 
		           A的长度m ==0时                       	return*(B+k-1)    
				   中位数的位置 k==1时    A B 的长度均为1，return min(*A,*B);
		*/
		if(m>n)
			return find_kth(B,n,A,m,k);//先把第一个数组减完
		if(m==0)  
			return*(B+k-1);      //把短的剪完
		if(k==1)                 
			return min(*A,*B);    //已经到达了第k个值
	
		int ia= min(k/2,m),  ib=k-ia;
		if(*(A+ia-1) < *(B+ib-1))
			return find_kth(A+ia,m-ia,B,n,k-ia); //剪A :A的长度减少  ia  ， 要寻找的第k个数减少ia

		else if(*(A+ia-1)>*(B+ib-1))
			return find_kth(A,m,B+ib,n-ib,k-ib); //剪B
		else
			return A[ia-1];
		 
	}
};











int main()
{
	 Solution s;
	 vector<int> v1;
	 v1.push_back(1);
	 v1.push_back(2);
	 v1.push_back(3);
	 v1.push_back(4);
 v1.push_back(5);

	 vector<int> v2;
	 v2.push_back(1); v2.push_back(1);
	 v2.push_back(2);
	 v2.push_back(4);
 	  v2.push_back(6); v2.push_back(7);
	cout<< s.findMedianSortedArrays(v1,v2)<<endl;

	return 0;
}

