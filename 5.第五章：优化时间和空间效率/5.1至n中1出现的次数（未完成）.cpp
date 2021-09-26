#include<iostream>
using namespace std;


//²»¿¼ÂÇÊ±¼ä
int numberOf1(int n)
{
	int  number=0;
	while(n!=0)
	{
		if(n%10 == 1)
			number++;
		n = n/10;
	}
	return number;
}

int number(int n)
{
	int num=0;
	for(unsigned int i=0; i<n; i++)
		num += numberOf1(i);
	return num;
}

















int main()
{
	 

	return 0;
}

