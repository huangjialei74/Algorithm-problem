#include<iostream>
using namespace std;

/*
//遇到负数时会出错
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


//把n和1做与运算，再把1左移一位 得到2， 再和n做与运算， 
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
把整数减去1后再与原来的整数做为与运算  得到的结果相当于把整数的二进制表示中最右边的1变成0  
*/


//高级解法：二进制中有多少个1就可以进行多少次与的操作   
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
 //负数补码存储
	 cout<<bitset<32>(0xFFFFFFFF)<<endl;

	 /*
	 正数 ox7FFFFFFF 
	 负数 0x80000000  0xFFFFFFFF
	 */
	return 0;
}

