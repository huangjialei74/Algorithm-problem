#include<iostream>
using namespace std;
#include<string>


/*
1,11,21,1211,111221,...
1  is read off as  11.
11 is read off as  21
21 is read off as  1211.

*/


// O(n^2) O(n)
class Solution
{
public:
	string countAndSay(int n)
	{
		string s("1");
		while(--n)
			s=getNext(s);
		return s;
	}
	string getNext(const string&s)
	{
		stringstream ss;
		 for(auto i=s.begin(); i!=s.end(); )
	//	for(auto i=0; i<s.size(); )
		 {
			 auto j=find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
		 	 ss<<distance(i,j)<<*i;
			 ss<<(j-i)<<*i;
			 i=j;
		 }
		 return ss.str();
	}
};













int main()
{
	 

	return 0;
}

