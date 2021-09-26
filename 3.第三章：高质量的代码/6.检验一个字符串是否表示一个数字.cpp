#include<iostream>
using namespace std;

 
//扫描连续的0-9的数位
bool scanUnsignedInteger(const char** str)
{
	const char* before = *str;
	while(**str !='\0' && **str>='0' && **str<='9')
	     ++(*str);
	return *str>before;//地址发生了移动  即存在0-9的数
}



//扫描可能以正负号开头的0-9的数位   
bool scanInteger(const char** str)
{
	if(**str=='+' || **str=='-')
		++(*str);
	return scanUnsignedInteger(str);//去正负号后 扫描0-9
}


/*

A[.]B[e|E]C  或者没有A  
先尽可能多的扫描0-9（有可能在起始处有'+'或'-'） 即A部分
如果遇到小数点  就在开始扫描0-9                 即B部分
如果遇到e|E, 就开始扫描0-9                      即C部分

*/

bool isNumeric(const char *str)
{
	if(str==NULL)
		return false;
	bool numeric = scanInteger(&str);
	if(*str=='.')
	{
		++str;
		/*
		||的原因：
		小数可以没有整数部分 如.123等于0.123
		小数点后可以没有数字 123.等于123.0
		小数点前后都有数字
		*/
		numeric = scanUnsignedInteger(&str)||numeric;
	}
	if(*str=='e' || *str=='E')
	{
		++str;
		/*
		&&的原因：
		e或者E前面没有数字时，整个字符串不能表示数字， 如e1,E1
        e或者E后面没有数字时，也不能表示数字
		*/
		numeric = numeric && scanInteger(&str);
	}
	return numeric && *str=='\0';
}








int main()
{
	 

	return 0;
}

