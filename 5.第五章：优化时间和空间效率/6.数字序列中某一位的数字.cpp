#include<iostream>
using namespace std;
#include<algorithm>
#include<math.h>
int countOfIntegers(int digits)
{
	if(digits==1)
		return 10;
	int count=(int)pow(10, digits-1);
	return 9*count;
	
}
int beginNumber(int digits)
{
	if(digits==1)
		return 0;
	return (int)pow(10,digits-1);

}
 int digitAtIndex(int index,int digits)
 {
	 int number=beginNumber(digits) + index/digits;
	 int indexFromRight=digits-index%digits;
	 for(int i=0; i<indexFromRight; i++)
	      number /= 10;
	 return number%10;
 }

int digitAtIndex(int index)
{
	if(index<0)
		return -1;
	int digits=1;
	while(true)
	{
		int numbers = countOfIntegers(digits);
		if(index<numbers*digits)
			return digitAtIndex(index, digits);
		index -= digits*numbers;
		digits++;
	}
	return -1;
 
}
 

int main()
{
	 

	return 0;
}

