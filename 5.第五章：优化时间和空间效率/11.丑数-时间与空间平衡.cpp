#include<iostream>
using namespace std;


/*我们把只含因子2 3 5，的数称为丑数，求按从小到大顺序的第1500个丑数 
例如6，8是丑数  14不是，因为它含有因子7 习惯上把1当作丑数*/


//逐个判断是否为丑数  不高效
 bool IsUgly(int number)
 {
	 while(number % 2 == 0)
		 number /= 2;
	 while(number % 3 == 0)
		 number /= 3;
	 while(number % 5 == 0)
	     number /= 5;
	 return number == 1;
 }

int GetUglyNumber(int index)
{
	if(index <= 0)
        return 0;
	int number = 0;
	int uglyFound=0;
	while(uglyFound < index)
	{
		++number;
		if(IsUgly(number))
			++uglyFound;
	}
	return number;
}

/*
即使一个数不是丑数  也要对其进行计算 效率不高

  创建一个数组  每个丑数都是前面的数 乘以2 3 5得到的
  关键在于确保数组里面丑数是排好序的
  已有的丑数是按照顺序存放在数组中的 对于乘以2而言  肯定存在某一个丑数T2 ，排在它之前的每一个丑数乘以2 得到的结果都会小于已有的最大丑数，其之后的每个丑数乘以2都会大于当时最大丑数，只需记录该丑数位置，每次生成新的丑数时更新该值 对于乘以3 5 而言  也存在同样的T3 T5
*/




int Min(int number1,int number2, int number3)
{
	int min= number1<number2 ?number1:number2;
	return min<number3 ? min: number3;
}
//空间换时间
int GetUglyNumber_Solution(int index)
{
	if(index<=0)
		return 0;
	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	while(nextUglyIndex < index)
	{
		int min=Min(*pMultiply2 * 2 ,*pMultiply3 * 3 ,*pMultiply5 * 5 );
        pUglyNumbers[nextUglyIndex]=min;

		while(*pMultiply2 * 2 <  pUglyNumbers[nextUglyIndex]) 
			++pMultiply2; 
		while(*pMultiply3 * 3 <  pUglyNumbers[nextUglyIndex]) 
			++pMultiply3; 
		while(*pMultiply5 * 5 <  pUglyNumbers[nextUglyIndex]) 
			++pMultiply5; 

		++nextUglyIndex;
	}

	int ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[]pUglyNumbers;
	return ugly;
 

}









int main()
{
	 

	return 0;
}

