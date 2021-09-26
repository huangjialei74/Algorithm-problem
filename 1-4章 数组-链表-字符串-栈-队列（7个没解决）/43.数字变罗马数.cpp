#include<iostream>
using namespace std;
#include<string>
/*
��������
��ͬ��������д��  ��ʾ��Щ�������                            �� ��=3��
С�������ڴ�����ֵ��ұߣ���ʾ��Щ������ӣ�                  �� ��=8����=12��
С�����֣����� ��X �� C���ڴ�����ֵ���ߣ���ʾ ������С������ ��=4����=9��
��һ���������滭һ�����ߣ���ʾ�������ֵ 1,000 ������=5000��
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
			int count=num/radix[i];//�Ӵ�����ʼ��
			num %= radix[i];
			for(  ; count>0 ; --count)
				roman += symbol[i]; //��ͬ��������д�����󲿷������һ��  ��������1�Ż�����
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

