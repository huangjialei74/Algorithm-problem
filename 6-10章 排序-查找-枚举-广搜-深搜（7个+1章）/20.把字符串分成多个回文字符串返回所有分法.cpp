#include<iostream>
using namespace std;
#include<vector>
#include<string>


//ÿһ���������ж��м����Ƿ�Ϊ�Ϸ�������û��ݷ�
//����Ϊn���ַ�������n-1���ط����Կ��ϣ�ÿ���ط��ɶϿɲ��ϣ����Ӷ�O(2^(n-1))
 

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
	//prev��ʾǰһ������,start��ʾ��ǰ����   start-1��ʾ �Ӵ����һ����ĸ
	void dfs(string  s, vector<string>& path, vector< vector<string> >&result, size_t prev, size_t start)//aab
	{    //cout<<"��ʱ��ǰ����ֵstart"<<start<<endl;
		if(start==s.size())//���һ������
		{	 
			if(isPalindrome(s, prev, start-1))//����ĩβ�� ���prev��start�ǲ��ǻ��ģ� �ǵĻ������
			{			
				path.push_back(s.substr(prev, start-prev)); 
				//cout<<prev<<"��"<<start-1<<"  "<<s.substr(prev,start-prev)<<"----------ĩβʱ���--------"<<endl;
				result.push_back(path); 
				 // cout<<"====================�������ַ����ˣ������һ��path��result��==========================="<<endl;
		 	    path.pop_back();
				 // cout<<"ȡ��ĩβԪ��,path��ʣ"<<path.size()<<"��Ԫ��------------------------------------------>>>"<<endl; 			
			}	 // cout<<"�ݹ���� ���Ϸ�����һ�㣬start��"<<start-1<<endl;
			return;
		} 
		dfs(s, path, result, prev, start+1);//����[prev,start-1]�ǻ��ģ��˴��Ȳ��Ͽ�
	
		if(isPalindrome(s, prev, start-1))//�Ͽ�---�ݹ��ȥ
		{   //cout<<"�Ͽ�ʱpath��С"<<path.size()<<endl;
			path.push_back(s.substr(prev,start-prev));
			//cout<<prev<<"��"<<start-1<<"  "<<s.substr(prev,start-prev)<<"----------�Ͽ�ʱ���--------"<<endl;
			dfs(s, path, result, start, start+1);//---�ݹ��ȥ
			path.pop_back();   
		    //cout<<"ȡ��ĩβԪ��,path��ʣ"<<path.size()<<"��Ԫ��------------------------------------------>>>"<<endl; 
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


//���Ѷ� O(2^n) O(n) �����
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
	//����������s[start]��ͷ��partition����
	 void DFS(string& s,vector<string>& path,vector< vector<string> >&result,int start)
	 {
		 if(start==s.size())
		 {
			 result.push_back(path); cout<<"=================�����һ��path================="<<endl;
			 return;
		 }
		 for(int i=start; i<s.size(); i++)
		 {
			 if(isPalindrome(s, start, i))//forѭ���ҵ�i  ����Ҫ�� ��ӵ�path���ݹ��ȥ
			 {
				  path.push_back(s.substr(start,i-start+1));//��iλ�ÿ�һ��
				  cout<<"���"<<s.substr(start,i-start+1)<<endl;
				  DFS(s,path,result,i+1); 
				   path.pop_back();// ������ -- Ϊ�ҵ��������Ӵ�
				  // cout<<"��ʣ"<<path.size()<<endl;
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

//����O(n^2) O(1) 
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

