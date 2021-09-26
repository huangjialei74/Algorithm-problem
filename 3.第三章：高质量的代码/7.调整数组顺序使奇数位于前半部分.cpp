                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
#include<iostream>
using namespace std;

/*
void ReorderOddEven(int *pData, unsigned int length)
{
	if(pData || length==0)
		return;
	int *pBegin = pData, *pEnd = pData = pData+length+1;
	while(pBegin<pEnd)
	{
		if(pBegin<pEnd && (*pBegin & 0x1)!=0)
			pBegin++;
		if(pEnd>pBegin && (*pEnd & 0x1)==0)
			pEnd++;
		if(pBegin<pEnd)
		{
			int temp=*pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}
*/
/*可扩展的函数
将判断部分的逻辑框架抽象出来 把判断的标准变成一个函数指针
*/
bool isExen(int n)//是否为偶数
{
	return (n & 0x1==0);
}
bool isPlus(int n)
{
	return (n>0);//是否为正数
} 


void Reorder(int *pData, unsigned int length,bool (*func)(int))
{
	if(pData==NULL || length==0)//空
		return;
	int *pBegin = pData, *pEnd = pData+length-1;//首尾
	while(pBegin<pEnd)
	{
		if(pBegin<pEnd &&  !func(*pBegin))
			pBegin++;
		if(pEnd>pBegin &&  func(*pEnd))
			pEnd--;
		if(pBegin<pEnd)//交换
		{
			int temp=*pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}


int main()
{
	int arr[] = {-1,-2,3,4,-5,-6,8};
   // Reorder(arr, 7, isEven);
	Reorder(arr, 7, isPlus);
    int i;
    for(i=0; i<7; i++) cout<<arr[i]<<"  ";
	 
     
	return 0;
}

