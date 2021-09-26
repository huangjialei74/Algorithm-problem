#include<iostream>
using namespace std;


//O(1)   �ж��Ƿ��Ѿ�����������nλ�� -- ����������ַ��������ֵ���޸�  ��3λ��996���997
bool Increment(char* number)//number����ָ�룬number�����ı�
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for(int i = nLength-1; i>=0; i--)//--------------------------------���ַ��������һ���ַ���ʼ
	{
		int nSum = number[i] -'0' + nTakeOver;//��һλ�Ľ�λ
		if(i==nLength-1)
			nSum++;
		if(nSum>=10)//������һλ�Ľ�λ����ڵ���10
		{
			if(i==0)
				isOverflow = true;//����������nλ��
			else{
				nSum -=10;
				nTakeOver = 1;//��λ�Ľ�λ
				number[i] ='0'+nSum;//���λ��λ��ʣ�µ�
			}
		}
		else//������һλʱ�ٲ�����λ��
		{
			number[i] = '0'+nSum;//number[i]�����ַ���С���
			break;
		}
	}
	return isOverflow;
}


void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	for(int i=0; i<nLength; ++i)
	{
		if(isBeginning0 && number[i] != '0')//���ֵĿ�ͷ����Ϊ0
			isBeginning0 =false;
		if(!isBeginning0)
		{
			cout<<number[i] ;
		}
	}
	cout<<"\t";
}


 

void Print1ToMaxOfNDigits(int n)
{
	if(n<=0)
		return ;
	char *number = new char[n+1];
	memset(number,'0',n);
 
	int i;
//	for(i = 0;i<n;i++)
//	cout<<number[i]; cout<<endl;


	number[n] = '\0';
	while(!Increment(number))
	{
		PrintNumber(number);
	}	

 	cout<<endl;
 	for(i = 0; i<n;i++)
    cout<<number[i]; 


	delete []number;
}

 

//����2 �������� �ݹ�
void Print1ToMaxOfNDigitsRecursively2(char* number, int length, int index)
{
	if(index == length-1)
	{
		PrintNumber(number);//��ӡ�ַ���
		return ;
	} 
	for(int i=0; i<10; ++i)
	{ 
		number[index+1] = i+'0';//
		Print1ToMaxOfNDigitsRecursively2(number,length,index+1);		
	}
}


void Print1ToMaxOfNDigits2(int n)
{
	if(n<=0)
		return ;
	char *number = new char[n+1];
	number[n] ='\0';
	for(int i=0; i<10; ++i)
	{
		number[0] = i+'0';cout<<" \n------------------------------------------------"<<number<<endl;
		Print1ToMaxOfNDigitsRecursively2(number,n,0);
		
	}
	delete []number;
}





int main()
{
	Print1ToMaxOfNDigits2(3);
	 

	return 0;
}

