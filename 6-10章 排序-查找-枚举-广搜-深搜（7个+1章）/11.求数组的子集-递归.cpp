#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>


//无重复的排序数组
/*
每个元素，两种选择 选或者不选



//递归

增量构造法 深搜O(2^n) O(n)
*/

// O(2^n)  O(n)

class Solution
{
public:
	vector< vector<int> > subsets(vector<int>&S)
	{
		sort(S.begin(),S.end());
		 vector< vector<int> >result;
		 vector<int>path;
		 subsets(S,path,0,result);
		 return result;
	}
private:
	static void subsets(const vector<int>&S, vector<int>&path, int step, vector< vector<int> >&result)
	{
		if(step==S.size())
		{//	for(vector<int>::iterator it = path.begin();it !=path.end();it++)
		//		cout<<(*it)<<"  ";	//	cout<<endl;
		
			result.push_back(path);
			return;
		}
		//不选S[step]
		 subsets(S, path, step+1, result); //没有添加S[step]  --的所有情况
		 //选S[step]
		 path.push_back(S[step]);//添加S[step]
    
		subsets(S, path, step+1, result);//添加了S[step]的所有情况
	 	path.pop_back();//撤销
	}
	 
};

 



//开一个位向量bool selected[n]每个元素可选可不选
//O(2^n) O(n)
class Solution2
{
public:
	vector< vector<int> > subsets(vector<int>&S)
	{
		 sort(S.begin(),S.end());
		 vector< vector<int> >result;
		 vector<bool>selected(S.size(),false);
		 subsets(S ,selected, 0, result);
		 return result;
	}
private:
	static void subsets(const vector<int>&S, vector<bool>& selected, int step, vector< vector<int> >&result)
	{
		if(step==S.size())
		{
			vector<int>subset;
			for(int i=0; i<S.size(); i++)//到头了  就把为true的全部添加
			{
				if(selected[i])
					subset.push_back(S[i]);
			}
			result.push_back(subset);//添加subset
			return;
		}
		//不选S[step]
		selected[step]=false;
		subsets(S,selected,step+1,result);    //每次都分两种情况 选择这个  不选这个
		//选S[step]
		 selected[step]=true;
		 subsets(S,selected,step+1,result);		 		 
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

