#include<iostream>
using namespace std;
#include<vector>
#include<iterator>
/*
n:[1-9]
���б��룺n�����ظ���Ԫ�� ��k�� ������a1,a2,a3,,,,an
a1��ʲô�� ��a1ȥ��  ʣ�µ���n-1��Ԫ��   ����n-1��������
 �� a1 = k/(n-1)!

  ͬ��  k2 = k/(n-1)!
  k2=k%(n-1)!
  a2=k2/(n-2)!
  ������
  kn-1=kn-2%2!
  an-1=kn-1/1!
  an=0


*/


class Solution
{
public:
	string getPermutation(int n,int k)
	{
		string s(n,'0');
		string result;
		for(int i=0; i<n; ++i)
			s[i]+=i+1;
		return kth_permutation(s,k);
    }
private:
	int factorial(int n)
	{
		int result=1;
		for(int i=1;i<=n; ++i)
			result *=i;
		return result;
	}
	
	template<typename Sequence>
	Sequence kth_permutation(const Sequence &seq,int k)
	{
		const int n=seq.size();
		Sequence S(seq);
		Sequence result;
		int base=factorial(n-1);
		--k;
		for(int i=n-1;  i>0;  k%=base,base/=i,--i)
		{
			auto a=next(S.begin(), k/base);
			result.push_back(*a);
			S.erase(a);
		}
		result.push_back(S[0]);
		return result;
	} 
};













int main()
{
	 

	return 0;
}

