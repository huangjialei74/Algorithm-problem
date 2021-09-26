#include<iostream>
using namespace std;


//O(1)   判断是否已经到达了最大的n位数 -- 并将传入的字符串代表的值做修改  如3位的996变成997
bool Increment(char* number)//number传入指针，number发生改变
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for(int i = nLength-1; i>=0; i--)//--------------------------------从字符串的最后一个字符开始
	{
		int nSum = number[i] -'0' + nTakeOver;//上一位的进位
		if(i==nLength-1)
			nSum++;
		if(nSum>=10)//加上上一位的进位后大于等于10
		{
			if(i==0)
				isOverflow = true;//到达了最大的n位数
			else{
				nSum -=10;
				nTakeOver = 1;//该位的进位
				number[i] ='0'+nSum;//向高位进位后剩下的
			}
		}
		else//进到这一位时再不够进位了
		{
			number[i] = '0'+nSum;//number[i]数字字符从小变大
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
		if(isBeginning0 && number[i] != '0')//数字的开头不能为0
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

 

//方法2 数字排列 递归
void Print1ToMaxOfNDigitsRecursively2(char* number, int length, int index)
{
	if(index == length-1)
	{
		PrintNumber(number);//打印字符串
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

