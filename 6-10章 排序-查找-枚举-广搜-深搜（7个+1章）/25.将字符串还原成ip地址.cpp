#include<iostream>
using namespace std;

#include<vector>
#include<string>
/*
For example:
Given"25525511135",
return["255.255.11.135", "255.255.111.35"] 
*/


// O(n^4) O(n)
class Solution
{
	 public:
		 vector<string> restoreIpAddresses(const string& s)
		 {
			 vector<string>result;
			 vector<string>ip;//存放中间结果
			 dfs(s, ip, result, 0);
			 return result;
		 }
		 /*
		 解析字符串
		 字符串s 输入数据
		 ip存放中间结果
		 result存放所有可能的ip地址
		 start当前正处理的index
		 */
		 void dfs(string s, vector<string>&ip,  vector<string>&result,  size_t start)
		 {
			 if(ip.size()==4 && start==s.size())//找到一个合法解
			 {
				  result.push_back(ip[0]+'.'+ip[1]+'.'+ip[2]+'.'+ip[3]);
				  return;
			 }
			 if(s.size()-start > (4-ip.size())*3 ) return;//剩下超过每段3位 剪枝
			 if(s.size()-start < (4-ip.size()) )   return;//剩下的不足每段1位  剪枝
			 int num=0;
			 for(size_t i=start; i<start+3; i++)//i<start+3最多试3次
			 {
				 num=num*10+(s[i]-'0');//随着位数增多 数不断变大
				 if(num<0||num>255)  continue;//剪枝
					 
				  ip.push_back(s.substr(start, i-start+1));
				  dfs(s,ip,result,i+1);//达到要求就递归进去   

				  ip.pop_back();//撤销   
				  if(num==0) break;//不允许前缀0  ， break使其后面不接数字，  但允许单个0
			 }
		 }
		
};











int main()
{
	 Solution s;
	 vector<string> v=s.restoreIpAddresses("25525511135");
	 for(vector<string>::iterator it=v.begin(); it!=v.end();it++)
		 cout<<(*it)<<endl;

	return 0;
}

