#include<iostream>
using namespace std;
#include<string>


//暴力遍历
//O(m*n) m是haystack的长度  n是 m-目标字符串的长度
 
	int strStr(const string& haystack, const string &needle)
	{
		if(needle.empty()) return 0;
		const int N=haystack.size() - needle.size() + 1;//两者长度相减  减少遍历次数
		for(int i=0; i<N; i++)
		{
			int j=i;
			int k=0;
			while(j < haystack.size() && k<needle.size() && haystack[j] == needle[k])
			{
				j++;
				k++;
			}
			if(k == needle.size())
				return i;
		}
		return -1;
	}
	//自己写的玩
	int strStr2(const string& haystack, const string &needle)
	{
		int len1=haystack.size();
		int len2=needle.size();
		int N=len1-len2+1;
		for(int i=0; i<N; i++)
		{
			if(haystack[i]==needle[0])
			{ 
				int j,k;
				for(j=i+1, k=1; k<len2; j++,k++)
				{
					if(haystack[j]!=needle[k]) break;
				}
				if(k==len2) return i;
			}
		}
		return -1;
	}
 
 


int main()
{
	 string s1="1234567",s2="567";
	 cout<<strStr2(s1,s2)<<endl;

	return 0;
}

