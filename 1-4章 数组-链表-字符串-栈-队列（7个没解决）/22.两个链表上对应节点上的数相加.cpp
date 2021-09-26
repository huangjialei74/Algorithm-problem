#include<iostream>
using namespace std;
#include<list>

class Solution
{
public:
	list<int> addTwoNUmbers(list<int>  l1,list<int>  l2)
	{
		list<int>  retu;//返回
		int value, carry = 0;//当前位上的数 和 进位
		for(list<int>::const_iterator it1 =l1.begin(), it2 =l2.begin(); 
		it1 !=l1.end(),  it2 !=l2.end(); it1++, it2++)
		{
			int a = it1 !=l1.end() ?(*it1) : 0;//不存在即为0
			int b = it2 !=l2.end() ?(*it2) : 0;
			value = (a+b +carry)%10;
			carry = (a+b +carry)/10;
			retu.push_back(value);

		}
		if(carry > 0) retu.push_back(carry);
		return retu;
	
	}


};












int main()
{ 
	list<int>l1; l1.push_back(5);   l1.push_back(5);  l1.push_back(5);
	list<int>l2; l2.push_back(1);   l2.push_back(1);  l2.push_back(1);
	Solution s;
	list<int> retu = s.addTwoNUmbers(l1,l2);
	for(list<int>::const_iterator it =retu.begin();  it !=retu.end(); it++)
		cout<<(*it)<<" ";


	return 0;
}

