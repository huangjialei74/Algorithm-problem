#include<iostream>
using namespace std;
#include<string>

class Solution
{
public:
	/*
	bool isPalindrome(string s)
	{
	 	transform(s.begin(), s.end(), s.begin(), ::tolower);
		auto left=s.begin(), right=prev(s.end());
		while(left < right)
		{
			if(!::isalnum(*left))
				++left;
			else if(!::isalnum(*right))
				--right;
			else if(*left!=*right)
				return false;
			else
			{
				left++,right--;
			}
		}
		return true;
	}

  */
	bool isPalindrome(string s)
	{
		int len = s.length();
		int i, j;
		for(i = 0, j = len-1; i < len/2-1 ; i++, j--)  
		{
		    if(s[i]-'A'>= 0 && s[i]-'Z'<= 0) s[i] = s[i]-'A'+'a';
			if(s[j]-'A'>= 0 && s[j]-'Z'<= 0) s[j] = s[j]-'A'+'a';//小写化
		}
		for( i = 0, j = len-1; i < len/2-1 ; i++,j--)//i++,j--遍历
		{ 
			if((s[i]-'a'< 0 || s[i]-'z'> 0 )&&(s[i]-'0'< 0 || s[i]-'9'> 0))   i++ ; //i++,j--忽略非数字字母
			if((s[i]-'a'< 0 || s[i]-'z'> 0 )&&(s[j]-'0'< 0 || s[j]-'9'> 0))   j-- ;  

			if(s[i] != s[j])     return false; 
		}	 	 
		return true;
	}


};


 

int main()
{
	string s = "123a=66A321";// "123a,=-,./';[ A321 ";
	Solution so;
	if(so.isPalindrome2(s))
	{
		cout<<"yes"<<endl;
	}
	
	 

	return 0;
}

