                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
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
/*����չ�ĺ���
���жϲ��ֵ��߼���ܳ������ ���жϵı�׼���һ������ָ��
*/
bool isExen(int n)//�Ƿ�Ϊż��
{
	return (n & 0x1==0);
}
bool isPlus(int n)
{
	return (n>0);//�Ƿ�Ϊ����
} 


void Reorder(int *pData, unsigned int length,bool (*func)(int))
{
	if(pData==NULL || length==0)//��
		return;
	int *pBegin = pData, *pEnd = pData+length-1;//��β
	while(pBegin<pEnd)
	{
		if(pBegin<pEnd &&  !func(*pBegin))
			pBegin++;
		if(pEnd>pBegin &&  func(*pEnd))
			pEnd--;
		if(pBegin<pEnd)//����
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

