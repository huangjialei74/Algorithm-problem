#include<iostream>
using namespace std;
#include<string>
/*
罗马数字
相同的数字连写，  表示这些数字相加                            如 Ⅲ=3；
小的数字在大的数字的右边，表示这些数字相加，                  如 Ⅷ=8、Ⅻ=12；
小的数字（限于 Ⅰ、X 和 C）在大的数字的左边，表示 大数减小数，如 Ⅳ=4、Ⅸ=9；
在一个数的上面画一条横线，表示这个数增值 1,000 倍，如=5000。
*/

// O(num) O(1)
class Solution 
{
public:
	string intToRoman(int num)
	{
		const int radix[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
		const string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		string roman;
		for(size_t i=0; num>0; ++i)
		{
			int count=num/radix[i];//从大数开始除
			num %= radix[i];
			for(  ; count>0 ; --count)
				roman += symbol[i]; //相同的数字连写，但大部分数最多一个  少数数字1才会连接
		}
		return roman;
	}
};



int main()
{
	Solution s;
	cout<<s.intToRoman(12)<<endl;
	 

	return 0;
}

