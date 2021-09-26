#include<iostream>
using namespace std;
#include<string>
#include<vector>



//纵向扫描  直到第i个不相同
//O(n1+n2+n3+...)
class Solution1
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		if(strs.empty())
			return "";
		for(int idx=0; idx<strs[0].size(); ++idx)//第一个字符串的长度
		{
			for(int i=1; i<strs.size(); ++i)
			{
				if(strs[i][idx] != strs[0][idx])//什么时候某字符串与第一个字符串的对应位不同
					return strs[0].substr(0,idx);//截取相同部分
			}
		}
		return strs[0];//循环如果全部执行完了 那就表示全部相同
	}
	 
};




//横向扫描 每个字符串和 第一个字符串相匹配  某个字符不相同时 换下一个字符串 记录每次最大长度
//O(n1+n2+n3+...)
class Solution2
{
public:
	string longestCommonPrefix(vector<string>&strs)
	{		
		if(strs.empty()) 	return"";
		int right_most = strs[0].size() - 1; //相同部分最大长度  初始值：第一个字符串的长度

		for(size_t i=1; i<strs.size(); i++)// 字符串的数量
			for(int j=0; j<=right_most; j++) 
				if(strs[i][j] != strs[0][j]){
					 right_most = j-1;//不断更新  j不相同  right_most取j-1
					 break;//我自己加的
				}
				return strs[0].substr(0,right_most+1);//right_most为下标  +1后即为长度
	}	 
};



int main()
{
	Solution2 s;
	 vector<string> v;
	 v.push_back("12345");  v.push_back("12356");  v.push_back("12367");  v.push_back("12378");
	 cout<<s.longestCommonPrefix(v)<<endl;
	 

	return 0;
}

