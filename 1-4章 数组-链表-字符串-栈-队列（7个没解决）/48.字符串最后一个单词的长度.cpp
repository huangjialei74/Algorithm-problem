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

// ˳��ɨ�� ��¼ÿ��word�ĳ���O(n)  O(1)
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
			if(*s++ != ' ')//(����ÿһ��)�� s ���ǿո� len��+1    s�ǿո� ���߲��ǿո�  s��+1
				++len; 
			else if(*s && *s !=' ')//�����s==' ' ��s++��ָ��s����һ���ַ�����ʱ��s��Ϊ' '���������µ���ʱ ��len����
				len=0;
		}
		return len;
	}
};
/*
s��Ϊ�ո�ʱ len++;
sΪ�� s����һ����Ϊ��ʱ�����µ���  len����
*/










int main()
{
	Solution s;
 	cout<<s.lengthOfLastWord("i kill you")<<endl;;



	/*
	int i = 0;
	if(i++ >1) cout<<">1 "<<endl;
	cout<<i<<endl;//  i++��ʹ������i++>1  d����i�Ѿ���Ϊ1��
   
	 */

	return 0;
}

