#include<iostream>
using namespace std;



#include<string>
int lomgestSubstring(const string & str)
{
	int curLength=0;
	int maxLength=0;

	int *position = new int[26];
	int i;
	for(i=0; i<26; i++)
		position[i]=-1;
	for(i=0; i<str.length(); i++)
	{
		int prevIndex=position[str[i]-'a'];
		if(prevIndex<0 || i-prevIndex>curLength)
			++curLength;
		else
		{
			if(curLength > maxLength)
			    maxLength = curLength;
			curLength = i-prevIndex;
		}
		position[str[i]-'a']=i;
	}
	if(curLength > maxLength)
		maxLength=curLength;
	delete[] position;
	return maxLength;
}















int main()
{
	 

	return 0;
}

