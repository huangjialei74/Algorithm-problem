#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>

 

//递归
//增量构造法O(2^n) O(n)

class Solution
{
public:
	vector< vector<int> >subsetsWithDup(vector<int>&S)
	{
		sort(S.begin(),S.end());//排序
		vector< vector<int> >result;
		vector<int>path;
		dfs(S, S.begin(), path, result);
		 return result;	
	}
private:
	static void dfs(const vector<int>&S, vector<int>::iterator start, vector<int>&path,vector< vector<int> >&result)
	{
		 result.push_back(path);	//不添加该元素时的序列	  	
	 	//  cout<<"\n-------------------"<<endl;//添加了一个path进result
		 for(vector<int>::iterator i=start; i!=S.end(); i++)//以每一位元素为起点，求对应的各个子序列（递归中循环 大问题简化成小问题）
		 {
			 if(i!=start && *i==*(i-1)) //i-1时已经求了一次 以该值为 首位时的子序列了  此处不需要再求， 
				 //此句代码在循环中发生作用， 在递归时不起作用(递归时start已经后移了，i不会和前面的数比较)   
				 continue; 
			 path.push_back(*i);       //  cout<<(*i)<<"进path        ";
			 dfs(S, i+1, path, result); // cout<<*(path.end()-1)<<"pop了"<<endl;
			  path.pop_back(); //撤销
		 }  
		 
	}

};

/*

// O(2^n)  O(n)  增量构造法版本2
class Solution 
{
public:
	vector< vector<int> >subsetsWithDup(vector<int>&S)
	{
		vector< vector<int> >result;
		sort(S.begin(), S.end());
		unordered_map<int,int>count_map;
		for_each(S.begin(), S.end(), [&count_map](inte)
		{
			if(count_map.find(e)!=count_map.end())
				count_map[e]++;
			elsecount_map[e]=1;
		}	);
		//
		vector<pair<int,int>>elems;
		for_each(count_map.begin(), count_map.end(), [&elems](constpair<int,int>&e)
		{
			elems.push_back(e);
		});
		sort(elems.begin(), elems.end());
		vector<int>path; 
		subsets(elems, 0, path, result);
		return result;	
	}
private:
	static void subsets(const vector< pair<int,int> >&elems,size_tstep,
		vector<int>&path, vector< vector<int> >&result)
	{
		if(step==elems.size()){result.push_back(path);
		return;
		}
		for(int i=0; i<=elems[step].second; i++)
		{
			for(int j=0; j<i; ++j)
			{
			   path.push_back(elems[step].first);
			}
			subsets(elems,step+1,path,result);
			for(int j=0;j<i;++j)
			{
				path.pop_back();
			}
		}
	}
};


*/
//位向量法
//  O(2^n) O(n)
/*
class Solution 
{
public:
	vector<vector<int> >subsetsWithDup(vector<int>&S)
	{
		vector<vector<int> >result;
		sort(S.begin(),S.end());
		vector<int>count(S.back()-S.front()+1,0);
		for(auto i:S)
		{
			count[i-S[0]]++;
		}
		
		vector<int>selected(S.back()-S.front()+1,-1);
		subsets(S,count, selected, 0, result);
		return result;
	}
private:
	static  void subsets(const vector<int>&S,vector<int>&count,vector<int>& selected,size_t step,vector<vector<int> >&result)
	{
		if(step==count.size())
		{
			vector<int>subset;
			for(size_t i=0; i<selected.size(); i++)
			{
				for(int j=0;j<selected[i];j++)
				{
					subset.push_back(i+S[0]);
				}
			}
			result.push_back(subset);
			return;
		}
		for(int i=0;i<=count[step];i++)
		{
			selected[step]=i;
			subsets(S,count,selected,step+1,result);
		}
	}
	
};

*/
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

