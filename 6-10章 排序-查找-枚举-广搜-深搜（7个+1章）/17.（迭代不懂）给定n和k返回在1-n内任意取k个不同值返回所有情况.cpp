#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>

 // O(n!) O(n)
class Solution
{
public:
	vector< vector<int> >combine(int n,int k)
	{
		vector<vector<int> >result;
		vector<int>path;
		dfs(n, k, 1, 0, path,result);
		return result;
	}
private:
	//start��ʼ����,cur�Ѿ�ѡ�����
	static void dfs(int n, int k, int start, int cur, vector<int>&path, vector< vector<int> >&result)
	{
		if(cur==k)//����
		{
			result.push_back(path);		 
		}
		for(int i=start; i<=n; ++i)
		{
			path.push_back(i);
			dfs(n, k, i+1, cur+1, path, result);//��i+1��ʼ, cur+1�Ѿ�ѡ�������+1 
			path.pop_back(); // ����  
		
		}	
	}
};


 
#include <numeric> 

//����O((n-k)!)  O(n)
class Solution2
{
public:
	vector< vector<int> >combine(int n,int k)
	{
		vector<int>values(n,1); 
	//	iota(values.begin(),values.end(),1);
		vector<bool>select(n,false);
		fill_n(select.begin(), k, true);
		vector< vector<int> >result;
		int num=0;
		do
		{ 
			vector<int>one(k);
			for(int i=0, index=0; i<n; ++i)
				if(select[i])
					one[index++] = values[i];
				result.push_back(one);
		}
		while(prev_permutation(select.begin(), select.end())&& num++ <20);//������бȵ�ǰ����С�����У�˳���ǴӴ�С û�о�false
		return result;
	}
};

 



int main()
{
	 
 
	 Solution2  s;
	 vector< vector<int> > V = s.combine(4, 2);
 
	 for(vector< vector<int> >::iterator it0 = V.begin(); it0 != V.end();it0++)
	 {
	 	for(vector<int>::iterator it = (*it0).begin();it !=(*it0).end();it++)
				cout<<(*it)<<"  ";
			cout<<endl;
	 }
	  
	return 0;
}

