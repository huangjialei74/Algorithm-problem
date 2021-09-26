#include<iostream>
using namespace std;




//Partition函数了，它的作用就是将整个数组分成小于基准值的左边，和大于基准值的右边。
int Partition(int *array , int lo, int hi)
{
	int key=array[lo];
	while(lo<hi)
	{
		while(array[hi]>key && hi>lo)
		{
			hi--;
		}
		array[lo]=array[hi];
		while(array[lo]<=key && hi>lo)
		{
			lo++;
		}
		array[hi]=array[lo];
	}
	array[hi]=key;
	return hi;
}

//O(n) 前提是允许修改数组
void GetLeastNumbers(int *input, int n, int *output, int k)
{
	if(input==NULL || n==0)
		return ;
	int start=0, end=n-1;
	int index=Partition(input, start, end);
	while(index != k-1)
	{
		if(index > k-1)
		{
			end=index-1;
			index=Partition(input,  start, end);
		}
		else
		{
			start=index+1;
			index=Partition(input,   start, end);
		}
	}
	for(int i=0; i<k; i++)
		output[i]=input[i];
}


//nlogk，特别适合处理海量数据


//懒得写









int main()
{
	 

	return 0;
}

