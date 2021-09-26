#include<iostream>
using namespace std;
#include<string>



/*
//STL    (n) O(1) 
class Solution
{
public:
	int lengthOfLastWord(const string&s)
	{
		auto first=find_if(s.rbegin(), s.rend(), ::isalpha);
		auto last=find_if_not(first, s.rend(), ::isalpha);		
		return distance(first, last);	
    }
};
*/

// 顺序扫描 记录每个word的长度O(n)  O(1)
class Solution
{
public:
	int lengthOfLastWord(const string&s)
	{
		return lengthOfLastWord2(s.c_str());
	}
private:
	int lengthOfLastWord2(const char*s)
	{
		int len=0;
		while(*s)
		{
			if(*s++ != ' ')//(遍历每一个)， s 不是空格 len就+1    s是空格 或者不是空格  s都+1
				++len; 
			else if(*s && *s !=' ')//上面的s==' ' ，s++，指向s后面一个字符，此时若s不为' '，即出现新单词时 ，len清零
				len=0;
		}
		return len;
	}
};
/*
s不为空格时 len++;
s为空 s后面一个不为空时出现新单词  len归零
*/










int main()
{
	Solution s;
 	cout<<s.lengthOfLastWord("i kill you")<<endl;;



	/*
	int i = 0;
	if(i++ >1) cout<<">1 "<<endl;
	cout<<i<<endl;//  i++即使不满足i++>1  d但是i已经变为1了
   
	 */

	return 0;
}

