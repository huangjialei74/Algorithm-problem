#include<iostream>
using namespace std;
#include<vector>
// O(n) O(1)


//数组第一个下标是最低位    vector容器begin()是最低位
class Solution
{
public:
	vector<int> plusOne(vector<int>& digits,int digit)
	{
		add(digits,digit);
		return digits;
	}
private:
	// digit现在可以无限大了
	void add(vector<int>& digits,int digit)
	{
		int c=digit;//初始进位
	    for(vector<int>::iterator it = digits.begin(); it != digits.end(); it++)	 
		{
			*it += c;//先与进位相加
			c = *it/10;//后计算剩余 进位
			*it %= 10;//剩余
		}
		while(c>0)//digit大于digits时 进位可能大于10
		{
		    int stay =c%10;
			c=c/10;
			digits.push_back(stay);
		} 
	}
		 
};

 


 
int main()
{
	 vector<int> v1;
	 //逆序输入
	 v1.push_back(5); v1.push_back(9); v1.push_back(9);//995

	 Solution s;
	  vector<int> v = s.plusOne(v1,19005 );

	  //逆序输出
	 for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
		 cout<<(*it)<<" ";

	return 0;
}

