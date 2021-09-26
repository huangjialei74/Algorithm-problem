#include<iostream>
using namespace std;
#include<vector>
#include <numeric>

#define max(a,b)((a)>=(b)?(a):(b))

 
 
//递归 O（n） O（n）
class Solution
{
public:
	int candy(const vector<int>&ratings)
	{
		vector<int>f(ratings.size());
		int sum=0;
		for(int i=0; i<ratings.size(); ++i)
			sum += solve(ratings,f,i);
		return sum;
	}
	int solve(const vector<int>&ratings, vector<int>&f, int i)
	{
		if(f[i]==0)//之前没有记录就递归求值  有记录就直接返回
		{
			f[i]=1;
			if(i>0 && ratings[i] > ratings[i-1])//从非第一个开始上升
				f[i]=max(f[i], solve(ratings, f, i-1)+1); //和前一个位置+1 相比 取大值
			if(i< ratings.size()-1 && ratings[i] > ratings[i+1])//从非最后一个下降
				f[i]=max(f[i], solve(ratings, f, i+1)+1);        
		}      //下降时调用了后面一个的solve值   递归时多次利用了solve函数  由于上一次递归时已经把f[]给赋值 不需要每次再重复递归
		return f[i];
	}
	  
};





 
int main()
{
	Solution  s;
	vector<int> v ;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);

	 
 	cout<<s.candy(v)<<endl;
	 

	return 0;
}

