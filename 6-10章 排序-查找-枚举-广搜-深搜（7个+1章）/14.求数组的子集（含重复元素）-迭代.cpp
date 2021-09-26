#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>

 //增量构造法
 // O(2^n)   O(1)
class Solution
{
public:
	vector< vector<int> >subsetsWithDup(vector<int>&S)
	{
		sort(S.begin(), S.end());
		vector< vector<int> >result(1);//添加了一个空
		size_t previous_size=0;
		for(size_t i=0; i<S.size(); ++i)
		{
			const size_t size=result.size();//result的大小 
		//	cout<<"result大小"<<size<<endl;
			for(size_t j=0; j<size; ++j)// 把之前result中的所有集合复制  在末尾都插入S[i]
			{
                 // S[i]与S[i-1]不相等(不和上一轮插入相同的S[i]);  或者j大于上一轮result之前的大小、
                 // 大于 previous_size时，复制的就是result末尾那些新添加的集合 ，S[j]就被添加到那些新添加的集合中去， 不会和前面的集合重复)		
				if(i==0 || S[i]!=S[i-1] || j>=previous_size)	{
					result.push_back(result[j]);  
				 //	cout<<"复制了"; for(vector<int>::iterator it=result[j].begin(); it!=result[j].end();it++) cout<<(*it)<<" ";cout<<"插入了"<<S[i]<<endl; 
					result.back().push_back(S[i]);  //把result中末尾元素复制一个  并在复制元素中插入S[j]
				}
			}
		 	previous_size=size; 
		   //	cout<<"------------------"<<endl;
		}
		return result;
	}
};


 
//二进制O(2^n) O(1)
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

