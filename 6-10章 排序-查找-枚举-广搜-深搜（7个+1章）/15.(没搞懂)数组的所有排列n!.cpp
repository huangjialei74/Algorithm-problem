#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


//重新实现std::next_permutation()
// O(n!) O(1)
/*
class Solution
{
public:
	vector< vector<int> >permute(vector<int>&num)
	{
		vector< vector<int> >result;
		sort(num.begin(), num.end());
		do{
			result.push_back(num);
		}while(next_permutation(num.begin(),num.end())); //2.12的next_permutation()我搞不懂
		return result;
	}
};
*/
// O(n!)   O(n)
/*
函数参数标记当前走到了哪步，还需要中间结果的引用，最终结果的引用 扩展节点 每次从左左到右，选一个没有出现的元素
收敛条件是当前走到了最后一个元素
*/
class Solution2
{
public:
	vector< vector<int> > permute(vector<int> num)
	{
		sort(num.begin(),num.end());
		vector< vector<int> >result;
		vector<int>path;
		 dfs(num, path, result);
		 return result;
	}
private:
	void dfs(  vector<int> num, vector<int>&path, vector< vector<int> >&result)
	{
		if(path.size()==num.size())
		{
			 result.push_back(path);
			 return;
		} 
		 for(vector<int>::iterator i = num.begin(); i!= num.end(); i++)
		 {
			  int* pos=find(path.begin(), path.end(),i);
			  if(pos==path.end())
			  {
				  path.push_back(*i);
				  dfs(num, path, result);
				  path.pop_back();
			  }
		 }
	}
};



 

int main()
{
	 

    	vector<int>v;
	 v.push_back(1);  v.push_back(2);  v.push_back(3);  

//	 Solution2 s;
	// vector< vector<int> > V = s.permute(v);
 //
	// for(vector< vector<int> >::iterator it0 = V.begin(); it0 != V.end();it0++)
	// {
	 //	for(vector<int>::iterator it = (*it0).begin();it !=(*it0).end();it++)
	//			cout<<(*it)<<"  ";
	//		cout<<endl;
	// }
	  
 

	return 0;
}

