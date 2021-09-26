#include<iostream>
using namespace std;



#include<string>
#include<vector>
/*
1:
2:abc
3:def
4:ghi
5:jkl
6:mno
7:pqrs
8:tuv
9:wxyz
*/

/*
Input:Digitstring"23"
Output:["ad","ae","af","bd","be","bf","cd","ce","cf"].
*/

/*
//µ›πÈO(3^n) O(n)
class Solution
{
public:
	 
	vector<string> letterCombinations(string  digits, vector<string> keyboard)
	{		
		vector<string> result;
		if(digits.empty())
			return result;
		dfs(digits, 0, " ", result, keyboard);
		return result;
	}
	void dfs(string  digits, size_t cur, string path, vector<string>& result, vector<string> keyboard)
	{
		if(cur==digits.size())
		{
			result.push_back(path);
			return;
		}
	 
	//	for(auto c:keyboard[digits[cur]-'0'])
		 while(cur<=1) 
		 { cout<<cur<<endl;
			 string c = keyboard[digits[cur]-'0'];
			dfs(digits, cur+1, path+c, result,   keyboard);
			cur++;
		}
	}
};

*/
 
 

//µ¸¥˙O(3^n)  O(1)
class Solution2
{
public:
//	const vector<string>keyboard{" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
	vector<string>letterCombinations(const string& digits,vector<string> keyboard)
	{
		if(digits.empty())
			return vector<string>();
		vector<string>result(1,"");
		for(auto d:digits)
		{
			const size_t n = result.size();
			const size_tm = keyboard[d-'0'].size();
			result.resize(n*m);
			for(size_t i=0; i<m; ++i)
				copy(result.begin(), result.begin() + n, result.begin()+n*i);
			for(size_t i=0; i<m; ++i)
			{
				vector<string>::iterator begin=result.begin();
				for_each(begin+n*i, begin+n*(i+1), [&](string&s)
				{
					s+=keyboard[d-'0'][i];
				});
			}
		}
		return result;
	}
};



 







int main()
{
	Solution2 s;
    vector<string> keyboard;	
    keyboard.push_back(" ");    keyboard.push_back("");     keyboard.push_back("abc");   keyboard.push_back("def");  keyboard.push_back("ghi");
  	keyboard.push_back("jkl");  keyboard.push_back("mno");  keyboard.push_back("pqrs");  keyboard.push_back("tuv");  keyboard.push_back("wxyz");
	


 	vector<string> v = s.letterCombinations("23", keyboard);
 	for(vector<string>::iterator it = v.begin(); it !=v.end();it++)
 		cout<<(*it)<<"  ";
	 

	return 0;
}

