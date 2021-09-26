#include<iostream>
using namespace std;

#include<string>
 #include <algorithm>

class Solution
{
public:
	//反转字符串后 从首位开始相加
	string addBinary(string a,string b)
	{
		string result;
		const size_t n=a.size()>b.size()?a.size():b.size();//最大长度
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		int carry=0;
		for(size_t i=0;i<n;i++)
		{
			const int ai=i<a.size()?a[i]-'0':0;
			const int bi=i<b.size()?b[i]-'0':0;
			const int val=(ai+bi+carry)%2;
			carry=(ai+bi+carry)/2; 
		 	result.insert(result.begin(), val+'0');//从首部插入
		}
		if(carry==1)
		{
		 	result.insert(result.begin(),'1'); 
		}
		return result;
	}
	//自己写的玩
	string addBinary3(string a,string b)
	{
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		int carry=0;
		string result="";
		for(int i=0, j=0; i<a.length()||j<b.length(); i++,j++)
		{
			int ai=i<a.length()?a[i]-'0':0,   bi=j<b.length()?b[i]-'0':0;
			int val=ai+bi+carry;
			carry=val/2;
			val=val%2;
            result.insert(result.begin(),val+'0');
		}
		if(carry==1)
			result.insert(result.begin(),'1');
		return result;

	}

     //从字符串尾部  往前面每位相加
	string addBinary2(string a,string b)
	{
		string result  = ""; 
		int carry = 0;
		for(int i = a.size() -1, j = b.size()-1; i>=0||j>=0 ; i--,j--)
		{
			int x = i<0 ? 0 :a[i] -'0', y = j<0 ? 0 :b[j] -'0';	
			char v = (x+y+carry)%2+'0';
			carry = (x+y+carry)/2;
			result =   v  + result; 
		}
		if(carry==1) result =  '1' + result;
		 
		return result;
	}
};















int main()
{

 

	  Solution S;
	  cout<<S.addBinary("1100","0110001101")<<endl;
	  cout<<S.addBinary3("1100","0110001101")<<endl;

	return 0;
}

