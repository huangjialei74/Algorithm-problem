#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>

 //�������취
 // O(2^n)   O(1)
class Solution
{
public:
	vector< vector<int> >subsetsWithDup(vector<int>&S)
	{
		sort(S.begin(), S.end());
		vector< vector<int> >result(1);//�����һ����
		size_t previous_size=0;
		for(size_t i=0; i<S.size(); ++i)
		{
			const size_t size=result.size();//result�Ĵ�С 
		//	cout<<"result��С"<<size<<endl;
			for(size_t j=0; j<size; ++j)// ��֮ǰresult�е����м��ϸ���  ��ĩβ������S[i]
			{
                 // S[i]��S[i-1]�����(������һ�ֲ�����ͬ��S[i]);  ����j������һ��result֮ǰ�Ĵ�С��
                 // ���� previous_sizeʱ�����Ƶľ���resultĩβ��Щ����ӵļ��� ��S[j]�ͱ���ӵ���Щ����ӵļ�����ȥ�� �����ǰ��ļ����ظ�)		
				if(i==0 || S[i]!=S[i-1] || j>=previous_size)	{
					result.push_back(result[j]);  
				 //	cout<<"������"; for(vector<int>::iterator it=result[j].begin(); it!=result[j].end();it++) cout<<(*it)<<" ";cout<<"������"<<S[i]<<endl; 
					result.back().push_back(S[i]);  //��result��ĩβԪ�ظ���һ��  ���ڸ���Ԫ���в���S[j]
				}
			}
		 	previous_size=size; 
		   //	cout<<"------------------"<<endl;
		}
		return result;
	}
};


 
//������O(2^n) O(1)
class Solution2
{
public:
	vector< vector<int> >subsetsWithDup(vector<int>&S)
	{
		sort(S.begin(),S.end());
		 vector< vector<int> >result;
		 const size_t n=S.size();
		 vector<int>v;
		 for(size_t i=0; i< 1U<<n; ++i)
		 {
			 for(size_t j=0; j<n; ++j)
			 {
				 if(i & 1<<j )
					 v.push_back(S[j]);
			 }
			 result.push_back(v);
			 v.clear();
		 }
		 vector< vector<int> >real_result;
		 copy(result.begin(), result.end(), back_inserter(real_result));
		 return real_result;
	}
};
 


 




int main()
{
	 
	 vector<int>v;
	 v.push_back(1);  v.push_back(2);  v.push_back(2);  

	 Solution s;
	 vector< vector<int> > V = s.subsetsWithDup(v);
 
	 for(vector< vector<int> >::iterator it0 = V.begin(); it0 != V.end();it0++)
	 {
	 	for(vector<int>::iterator it = (*it0).begin();it !=(*it0).end();it++)
				cout<<(*it)<<"  ";
			cout<<endl;
	 }
	  
	return 0;
}

