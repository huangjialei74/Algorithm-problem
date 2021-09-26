#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>


//���ظ�����������
 
/*
 //��������
//  O(2^n)  O(1)
class Solution
{
public:
	vector< vector<int> >subsets(vector<int>&S)
	{
		sort(S.begin(),S.end());
		 vector< vector<int> >result(1);
		 for(auto elem:S)
		 {
			 result.reserve(result.size()*2);
			 auto half = result.begin()+result.size();
			 copy(result.begin(), half, back_inserter(result));
			 for_each(half,  result.end(), [&elem](decltype(result[0])&e)
			 {
				 e.push_back(elem);
			 });
		 }
		 return result;
	}
};
 
*/




/*
 �����Ʒ�-���ϵ�Ԫ�ز�����intλ��
 ��iλΪ1��ʾѡ�� 0��ʾ��ѡ��

 */
//  O(2^n)  O(1)
class Solution
{
public:
	vector< vector<int> >subsets(vector<int>&S)
	{
	 	 sort(S.begin(),S.end());
		 vector< vector<int> >result;
		 const size_t n = S.size();//�޷�����
		 vector<int>v;
		 for(size_t i=0; i< 1<<n; i++)//һ�����1*2*2*2...��Ԫ�ؽ�result��  ÿ�����  ���Ƕ�������ʽiΪ1�ĸ���λ
		 {
		//	 cout<<"\n ***** "<<i<<" ***** "<<endl;
			 for(size_t j=0; j<n; j++) 
			 {
				 if(i & 1<<j)// i & 1<<j��ʾi�ĵ�jλ�������������� �Ƿ�Ϊ1   Ϊ1  �����S[j]
				 {
					 v.push_back(S[j]); // cout<<i<<"��"<<(1<<j)<<"��ͬ�� i="<<i<<", j="<<j<<", S[j]="<<S[j]<<endl;
				 }
				// else
					// cout<<i<<"��"<<(1<<j)<<"��ͬ"<<endl;
			 }		 
			 result.push_back(v);			
			 v.clear(); //��� 		  
		 }
		 return result;
	}
 
};


 



int main()
{
	 vector<int>v;
	 v.push_back(1);  v.push_back(2);  v.push_back(3);  

	 Solution s;
	 vector< vector<int> > V = s.subsets(v);

cout<<"-----------------------------------"<<endl;
	 for(vector< vector<int> >::iterator it0 = V.begin(); it0 != V.end();it0++)
	 {
	 	for(vector<int>::iterator it = (*it0).begin();it !=(*it0).end();it++)
				cout<<(*it)<<"  ";
			cout<<endl;
	 }
	return 0;
}

