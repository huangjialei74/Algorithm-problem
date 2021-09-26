#include<iostream>
using namespace std;
#include<math.h>
#include<algorithm>



bool g_InvalidInput = false;//全局变量用来处理错误   只不过此处没有写处理错误的函数
/*
//全面但不高效
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	double result = 1.0;
	for(int i = 1; i<=exponent; i++)
		result *=base;
	return result;
}
*/

/*
a^n = a^(n/2) *  a^(n/2)       偶数 
a^n = a^(n/2) *  a^(n/2) * a   奇数
*/
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if(exponent == 0) return 0;
	if(exponent == 1) return base;
	double result = PowerWithUnsignedExponent(base, exponent>>1);//假设是偶数  ---递归  位运算代替除以2 
	result *= result;
	if(exponent & 0x1 == 1)//exponent 为奇数  与运算代替取余%
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
	unsigned int absExponent = (unsigned int)(exponent);//正数
	if(exponent<0)
		absExponent =(unsigned int)(-exponent);//负数

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

