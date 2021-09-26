#include<iostream>
using namespace std;
#include<string>







//O(n)    O(1)
class Solution
{
public:
	inline int map(const char c)
/*在函数声明或定义中，函数返回类型前加上关键字inline，即可以把函数指定为内联函数。
这样可以解决一些频繁调用的函数大量消耗栈空间（栈内存）的问题*/
	{
		switch(c)
		{
		case'I':
			return 1;
		case'V':
			return 5;
		case'X':
			return 10;
		case'L':
			return 50;
		case'C':
			return 100;
		case'D':
			return 500;
		case'M':
			return 1000;
		default:
			return 0;
		}
	}

	int romanToInt(const string&s)
	{
		int result=0;
		for(size_t i=0; i<s.size();i++)
		{
			if(i>0 && map(s[i]) > map(s[i-1]))
			{
				result += (map(s[i]) - 2*map(s[i-1]));//例如IV :5-1=4 , 减去两倍的s[i-1]的原因是  之前已经加了一次 
			}
			else
			{
				result += map(s[i]);
			}
		}
		return result;
	}
	 
};


 
int main()
{
	 

	return 0;
}

