#include<iostream>
using namespace std;




//左程云
int waterKing(int arr[],int n)
{
	if(n==0)
	{ 
		return -1;
	}
	int candidate = 0;
    int restHP = 0;

	for(int i = 0; i<n; i++)
	{
		if(restHP == 0)//当前没有候选
		{
			candidate = arr[i];
			restHP =1;
		}
		else if(arr[i] != candidate)  //有候选 当前数字和候选不一样
		{
			restHP--;
		}
		else
		{
			restHP++;
		}		
	}
	    if(restHP == 0)
		{
			return -1;
		}
        int count = 0;
		for(int j = 0;j<n;j++) //统计其出现次数 
		{
			if(arr[j] == candidate)
			{
				count++;
			}
		}
	//	cout<<"水王数出现了"<<count <<"次"<<endl;
		if(count > n/2)//是否超过了1/2
		{
			return candidate;
		}
		else
		{
			return -1;
		}
}




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

int waterKing2(int *array, int length)
{
	if(array==NULL || length==0)
		return 0;
	int middle=length>>1;
	int start=0;
	int end=length-1;
	int index=Partition(array ,start,end); 
	while(index != middle)
	{
		if(index > middle)
		{
			end=index-1;
			index=Partition(array, start,end);
		}
		else
		{
			start=index+1;
			index=Partition(array, start,end);
		}
	}
	int result=array[middle], count=0;
	for(int j=0; j<length; j++)
	{
		if(array[j]==result)
			count++;
	}
	if(count>(length>>1))
		return result;
	else
		return 0;
}

int main()
{

	int a[10] = {1,1,2,3,4,5,1,1,1,1};
	int water = waterKing2(a,10);
	cout<<"水王数："<<water<<endl;
	 

	cout<<endl;

	return 0;
}

