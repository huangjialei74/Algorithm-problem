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
			 vector<string>ip;//����м���
			 dfs(s, ip, result, 0);
			 return result;
		 }
		 /*
		 �����ַ���
		 �ַ���s ��������
		 ip����м���
		 result������п��ܵ�ip��ַ
		 start��ǰ�������index
		 */
		 void dfs(string s, vector<string>&ip,  vector<string>&result,  size_t start)
		 {
			 if(ip.size()==4 && start==s.size())//�ҵ�һ���Ϸ���
			 {
				  result.push_back(ip[0]+'.'+ip[1]+'.'+ip[2]+'.'+ip[3]);
				  return;
			 }
			 if(s.size()-start > (4-ip.size())*3 ) return;//ʣ�³���ÿ��3λ ��֦
			 if(s.size()-start < (4-ip.size()) )   return;//ʣ�µĲ���ÿ��1λ  ��֦
			 int num=0;
			 for(size_t i=start; i<start+3; i++)//i<start+3�����3��
			 {
				 num=num*10+(s[i]-'0');//����λ������ �����ϱ��
				 if(num<0||num>255)  continue;//��֦
					 
				  ip.push_back(s.substr(start, i-start+1));
				  dfs(s,ip,result,i+1);//�ﵽҪ��͵ݹ��ȥ   

				  ip.pop_back();//����   
				  if(num==0) break;//������ǰ׺0  �� breakʹ����治�����֣�  ��������0
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

