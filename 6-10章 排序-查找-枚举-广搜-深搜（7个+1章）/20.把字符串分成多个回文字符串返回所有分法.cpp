#include<iostream>
using namespace std;
#include<vector>
#include<string>


//每一步都可以判断中间结果是否为合法结果，用回溯法
//长度为n的字符串，有n-1个地方可以砍断，每个地方可断可不断，复杂度O(2^(n-1))
 

// O(2^n) O(n)
class Solution
{
public:
	vector< vector<string> > partition(string s)
	{
 	    vector< vector<string> >result;
 	    vector<string>path;
	 	dfs(s, path, result, 0 ,1);
 	    return result;
	}
	//prev表示前一个隔板,start表示当前隔板   start-1表示 子串最后一个字母
	void dfs(string  s, vector<string>& path, vector< vector<string> >&result, size_t prev, size_t start)//aab
	{    //cout<<"此时当前隔板值start"<<start<<endl;
		if(start==s.size())//最后一个隔板
		{	 
			if(isPalindrome(s, prev, start-1))//到达末尾了 检查prev到start是不是回文， 是的话就添加
			{			
				path.push_back(s.substr(prev, start-prev)); 
				//cout<<prev<<"到"<<start-1<<"  "<<s.substr(prev,start-prev)<<"----------末尾时添加--------"<<endl;
				result.push_back(path); 
				 // cout<<"====================划分完字符串了，添加了一个path到result里==========================="<<endl;
		 	    path.pop_back();
				 // cout<<"取出末尾元素,path还剩"<<path.size()<<"个元素------------------------------------------>>>"<<endl; 			
			}	 // cout<<"递归结束 马上返回上一层，start是"<<start-1<<endl;
			return;
		} 
		dfs(s, path, result, prev, start+1);//不管[prev,start-1]是回文，此处先不断开
	
		if(isPalindrome(s, prev, start-1))//断开---递归进去
		{   //cout<<"断开时path大小"<<path.size()<<endl;
			path.push_back(s.substr(prev,start-prev));
			//cout<<prev<<"到"<<start-1<<"  "<<s.substr(prev,start-prev)<<"----------断开时添加--------"<<endl;
			dfs(s, path, result, start, start+1);//---递归进去
			path.pop_back();   
		    //cout<<"取出末尾元素,path还剩"<<path.size()<<"个元素------------------------------------------>>>"<<endl; 
		}
	}


	bool isPalindrome(const string&s, int start,int end)
	{
		while(start<end && s[start]==s[end])
		{
			++start;
			--end;
		}
		return start>=end;
	}
};


//深搜二 O(2^n) O(n) 更简洁
class Solution2
{
public:
	vector< vector<string> >partition(string s)
	{
		vector< vector<string> >result;
		vector<string>path;
		 DFS(s,path,result,0);
		 return result;
	}
	//搜索必须以s[start]开头的partition方案
	 void DFS(string& s,vector<string>& path,vector< vector<string> >&result,int start)
	 {
		 if(start==s.size())
		 {
			 result.push_back(path); cout<<"=================添加了一个path================="<<endl;
			 return;
		 }
		 for(int i=start; i<s.size(); i++)
		 {
			 if(isPalindrome(s, start, i))//for循环找到i  符合要求 添加到path，递归进去
			 {
				  path.push_back(s.substr(start,i-start+1));//从i位置砍一刀
				  cout<<"添加"<<s.substr(start,i-start+1)<<endl;
				  DFS(s,path,result,i+1); 
				   path.pop_back();// 撤销掉 -- 为找到更长的子串
				  // cout<<"还剩"<<path.size()<<endl;
			 }
		 }
	 }


	 bool isPalindrome(const string&s,int start,int end)
	 {
		 while(start<end && s[start]==s[end])
		 {
			 ++start;
			 --end;
		 }
		 return start>=end;
	 }
};

 /*

//动规O(n^2) O(1) 
class Solution3
{
public:
	vector< vector<string> >partition(string s)
	{
		const int n=s.size();
		bool p[n][n];//whether s[i,j] is palindrome
		fill_n(&p[0][0], n*n, false);
		int i,j;
		for( i=n-1; i>=0; --i)
			for( j=i; j<n; ++j)
				p[i][j] = s[i]==s[j]&&((j-i<2)||p[i+1][j-1]);
			vector< vector<string> >sub_palins[n];//sub palindromes of s[0,i]
			for(  i=n-1; i>=0; --i)
			{
				for( j=i; j<n; ++j)
					if(p[i][j])
					{
						const string palindrome=s.substr(i,j-i+1);
						if(j+1<n)
						{
							for(auto v:sub_palins[j+1])
							{
								v.insert(v.begin(), palindrome);
								sub_palins[i].push_back(v);
							}
						}
						else
						{
							sub_palins[i].push_back( palindrome );
						}
					}
			}
			return sub_palins[0];
	}
};

*/

int main()
{
	 
 
	 Solution2  s;
	 vector< vector<string> > V = s.partition("aab");
 
	 for(vector< vector<string> >::iterator it0 = V.begin(); it0 != V.end();it0++)
	 {
	 	for(vector<string>::iterator it = (*it0).begin();it !=(*it0).end();it++)
				cout<<(*it)<<"  ";
			cout<<endl;
	 }
 
	return 0;
}

