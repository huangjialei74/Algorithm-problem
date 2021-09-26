#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>


//无重复的排序数组
 
/*
 //增量构造
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
 二进制法-集合的元素不超过int位数
 第i位为1表示选择 0表示不选择

 */
//  O(2^n)  O(1)
class Solution
{
public:
	vector< vector<int> >subsets(vector<int>&S)
	{
	 	 sort(S.begin(),S.end());
		 vector< vector<int> >result;
		 const size_t n = S.size();//无符号数
		 vector<int>v;
		 for(size_t i=0; i< 1<<n; i++)//一共添加1*2*2*2...组元素进result，  每组的数  就是二进制形式i为1的各个位
		 {
		//	 cout<<"\n ***** "<<i<<" ***** "<<endl;
			 for(size_t j=0; j<n; j++) 
			 {
				 if(i & 1<<j)// i & 1<<j表示i的第j位（从右往左数） 是否为1   为1  就添加S[j]
				 {
					 v.push_back(S[j]); // cout<<i<<"和"<<(1<<j)<<"相同， i="<<i<<", j="<<j<<", S[j]="<<S[j]<<endl;
				 }
				// else
					// cout<<i<<"和"<<(1<<j)<<"不同"<<endl;
			 }		 
			 result.push_back(v);			
			 v.clear(); //清空 		  
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

