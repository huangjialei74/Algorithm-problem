#include<iostream>
using namespace std;
#include<vector>
// O(n) O(1)


//�����һ���±������λ    vector����begin()�����λ
class Solution
{
public:
	vector<int> plusOne(vector<int>& digits,int digit)
	{
		add(digits,digit);
		return digits;
	}
private:
	// digit���ڿ������޴���
	void add(vector<int>& digits,int digit)
	{
		int c=digit;//��ʼ��λ
	    for(vector<int>::iterator it = digits.begin(); it != digits.end(); it++)	 
		{
			*it += c;//�����λ���
			c = *it/10;//�����ʣ�� ��λ
			*it %= 10;//ʣ��
		}
		while(c>0)//digit����digitsʱ ��λ���ܴ���10
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
	 //��������
	 v1.push_back(5); v1.push_back(9); v1.push_back(9);//995

	 Solution s;
	  vector<int> v = s.plusOne(v1,19005 );

	  //�������
	 for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
		 cout<<(*it)<<" ";

	return 0;
}

