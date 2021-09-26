#include<iostream>
using namespace std;
#include<vector>

#define min(a,b)((a)<=(b)?(a):(b))
/*
������ ��¼��ǰ���� ��m����� 
pA pBָ��������
*/


//����������� 
/*
����A B ����k/2��Ԫ��  ��  A[k/2-1]�� B[k/2-1]���
A[k/2-1]< B[k/2-1] ʱ ǰK��Ԫ�رذ���  ���е� A:0-k/2-1 --->  ��k��Ԫ�� ������A��k/2-1����һ�� ����   B:0-k/2-1 ��   ����ɾ��A:0-k/2-1
A[k/2-1]�� B[k/2-1]         ɾ��B:0-k/2-1
A[k/2-1]�� B[k/2-1]   ���� A[k/2-1]�� B[k/2-1]
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
			return find_kth(A.begin(), m, B.begin(), n, total/2+1); //����Ϊ����
		else 
			return(find_kth(A.begin(), m, B.begin(), n, total/2) + 
			       find_kth(A.begin(), m, B.begin(), n, total/2+1)) /2.0;//ż��
	}
private:
	static int find_kth(vector<int>::const_iterator A,int m, vector<int>::const_iterator B,int n,int k)
	{ // m=A.size(); n=B.size(); 
	  /*��������� 
		           A�ĳ���m ==0ʱ                       	return*(B+k-1)    
				   ��λ����λ�� k==1ʱ    A B �ĳ��Ⱦ�Ϊ1��return min(*A,*B);
		*/
		if(m>n)
			return find_kth(B,n,A,m,k);//�Ȱѵ�һ���������
		if(m==0)  
			return*(B+k-1);      //�Ѷ̵ļ���
		if(k==1)                 
			return min(*A,*B);    //�Ѿ������˵�k��ֵ
	
		int ia= min(k/2,m),  ib=k-ia;
		if(*(A+ia-1) < *(B+ib-1))
			return find_kth(A+ia,m-ia,B,n,k-ia); //��A :A�ĳ��ȼ���  ia  �� ҪѰ�ҵĵ�k��������ia

		else if(*(A+ia-1)>*(B+ib-1))
			return find_kth(A,m,B+ib,n-ib,k-ib); //��B
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

