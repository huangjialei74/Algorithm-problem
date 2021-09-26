#include<iostream>
using namespace std;
#include<string>
//暴力枚举  以每个元素为中间元素 同时左右出发 复杂度O(n2)
//记忆化搜索
/*动归 设f(i, j)  = true :        i = j
                    s[i] == s[j]     j=i+1
					S[i] == S[j]andf(i+1,j?1),    j>i+1
*/
//Manacher's Algorithm,   http://leetcode.com/2011/11/longest.palindromic-substring-part-ii.html

/*
记忆化搜索 和 Manacher's Algorithm太难了
*/



//动归 O(n2) O(n2)

class Solution
{
public:
	string longestPalindrome(const string &s)
	{
		const int n=s.size(); 
/*
下面两个for循环嵌套时，只用到了存储空间的一半  对于一个正方形，如果左下角为（0，0）时，只用到了y=x那条线的下方
*/
		//二维动态数组
		bool **f = new bool*[n]; // 先开辟高一级的动态数组
		size_t i, j ;
		for(i = 0;i<n;i++)
			f[i] = new bool[n];  // 然后开辟低一级的动态数组
	
		for( i = 0; i<n ;i++) 
			for( j = 0; j<n;j++)
				f[i][j]= false;
			  
		// vector会超时
		size_t max_len=1,start=0;//起点 和终点
		for( i=0; i<s.size(); i++)//"1234554300"
		{
			f[i][i]=true;
			for( j=0; j<i; j++)//j<i
			{ 
				f[j][i] = (s[j]==s[i] && (i-j<2 || f[j+1][i-1]) );
/*例如上面的字符串  当i是最后一个字符0时,  i=str.size()-1, j从0开始   判断s[j]==s[i]指首尾的字符相不相等，
再看f[j+1][i-1]从两边往中间的字符是否相等*/
				if(f[j][i] && max_len<(i-j+1))
				{
					max_len=i-j+1;//新的最大长度
					start=j;//起点是j
				}
			}
		}

		for(i = 0;i<n;i++)//先释放第一级多态数组
		{
			delete [](f[i]) ;
		} 
	 	delete []f;// 然后释放高一级的动态数组
		return s.substr(start, max_len);
	}
 
};









int main()
{
	Solution s;
	cout<<s.longestPalindrome2("1234554300")<<endl;
	 

	return 0;
}

