#include<iostream>
using namespace std;


#define max(a,b) a>b? a:b;

/*
在m*n的棋盘中每一格 放有一个礼物（礼物的价值大于0）  从左上角 走到右下角    请问最多能拿到价值多少的礼物
*/
//递归
int getMaxValue_solution(const int* value, int rows, int cols)
{
	if(value ==NULL || rows<=0 || cols<=0)
		return 0;
    int ** maxValues = new int*[rows];
	int  i;
	for(i=0; i<rows; i++)
		maxValues[i]=new int[cols];
	for(i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			int left=0;
			int up=0;
			if(i>0)
				up=maxValues[i-1][j];
			if(j>0)
				up=maxValues[i][j-1];
			maxValues[i][j] = max(left,up) + value[i*cols + j];
		}
	}
	int maxValue=maxValues[rows-1][cols-1];
	for( i=0; i<rows; i++)
		delete[]maxValues[i];
	delete []maxValues;
	return maxValue;
}
						 




//优化


int getMaxValue_solution2(const int* value, int rows, int cols)
{
	if(value ==NULL || rows<=0 || cols<=0)
		return 0;
    int * maxValues  =new int[cols];
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			int left=0;
			int up=0;
			if(i>0)
				up=maxValues[j];
			if(j>0)
				up=maxValues[j-1];
			maxValues[j] = max(left,up) + value[i*cols + j];
		}
	}
	int maxValue=maxValues[cols-1];
	delete []maxValues;
	return maxValue;
}
						 













int main()
{
	 

	return 0;
}

