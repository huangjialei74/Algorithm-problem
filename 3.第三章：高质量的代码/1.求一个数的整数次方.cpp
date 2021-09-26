#include<iostream>
using namespace std;
#include<math.h>
#include<algorithm>



bool g_InvalidInput = false;//ȫ�ֱ��������������   ֻ�����˴�û��д�������ĺ���
/*
//ȫ�浫����Ч
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	double result = 1.0;
	for(int i = 1; i<=exponent; i++)
		result *=base;
	return result;
}
*/

/*
a^n = a^(n/2) *  a^(n/2)       ż�� 
a^n = a^(n/2) *  a^(n/2) * a   ����
*/
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if(exponent == 0) return 0;
	if(exponent == 1) return base;
	double result = PowerWithUnsignedExponent(base, exponent>>1);//������ż��  ---�ݹ�  λ����������2 
	result *= result;
	if(exponent & 0x1 == 1)//exponent Ϊ����  ���������ȡ��%
		result *=base;

	return result;
}

double Power(double base, int exponent)
{
	g_InvalidInput = false;
	if( (base-0.0 <0.000001 ) && (exponent < 0))
	{
		g_InvalidInput = true;
		return 0.0;
	}
	unsigned int absExponent = (unsigned int)(exponent);//����
	if(exponent<0)
		absExponent =(unsigned int)(-exponent);//����

	double result = PowerWithUnsignedExponent(base, absExponent);
	if(exponent < 0)
		return 1.0/result;
	return result;
}




 


int main()
{
	cout<<Power(2.0, -3)<<endl;
	 

	return 0;
}

