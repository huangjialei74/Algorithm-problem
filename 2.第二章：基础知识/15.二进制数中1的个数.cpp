#include<iostream>
using namespace std;

/*
//��������ʱ�����
int NumberOf1(int n)
{
	int count = 0;
	while(n)
	{
		if(n&1)
			count++;
		n= n>>1;
	}
	return count;
}
*/


//��n��1�������㣬�ٰ�1����һλ �õ�2�� �ٺ�n�������㣬 
int NumberOf1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while(flag)
	{
		if(n&flag)
			count++;
		flag = flag<<1;
	}
	return count;
}


/*
��������ȥ1������ԭ����������Ϊ������  �õ��Ľ���൱�ڰ������Ķ����Ʊ�ʾ�����ұߵ�1���0  
*/


//�߼��ⷨ�����������ж��ٸ�1�Ϳ��Խ��ж��ٴ���Ĳ���   
  int numberOf1(int n)
{
	int count = 0;
 
	while(n)
	{ 
		++count;
		n = (n-1)&n;
	}
	return count;
}







 #include<bitset>


int main()
{
	 cout<<numberOf1(0xFFFFFFFF)<<endl;
 //��������洢
	 cout<<bitset<32>(0xFFFFFFFF)<<endl;

	 /*
	 ���� ox7FFFFFFF 
	 ���� 0x80000000  0xFFFFFFFF
	 */
	return 0;
}

