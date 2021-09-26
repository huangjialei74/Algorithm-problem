#include<iostream>
using namespace std;



bool g_InvalidInput = false;
int FindGreatestSumOfSubArray(int *array, int length)
{
	if(array==NULL || length==0)
	{
        g_InvalidInput=true;
		return 0;
	}
	g_InvalidInput=false;
	int sum=0;
	int nGreatestSum=0x80000000;
	for(int i=0; i<length;  ++i)
	{
		if(sum<=0)//小于0时就重新开始
			sum=array[i];
		else
			sum += array[i];

		if(sum > nGreatestSum)
			nGreatestSum=sum;
	}
	return nGreatestSum;

}
















int main()
{
	 

	return 0;
}

