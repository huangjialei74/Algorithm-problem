#include<iostream>
using namespace std;

/*
把矩阵当作若干个圈，每次打印一个圈
对于每个圈，对起点（左上角）（start,start）分析，循环打印每个圈的条件是 columns>2*startX, columns>2*startY
打印最后一个完整的圈后，剩下的构不成一个圈：3种情况，他们只能执行打印圈中的1-2个操作，例如打印一行  ，打印一个＋竖着的一列，打印一行已经下面的一行
*/

void PrintMatrixInCircle(int numbers[][5], int columns, int rows,int start)//数组的行数无关紧要numbers[][4]
{
	int endX=columns-1-start;//2
	int endY=rows-1-start;//3

	int i;
	//从左到右打印一行
	for(i=start; i<=endY; ++i)
		cout<<numbers[start][i]<<" ";
	//从上到下打印一行
	if(start<endY)
	{
	   for(i=start+1; i<endX; ++i)
	       cout<<numbers[i][endY]<<" ";
	}
	if(start<endY && start<endX)
	{
		for(i=endY; i>=start; --i)
	        cout<<numbers[endX][i]<<" ";
	}
	if(start<endY-1 && start<endX)
	{
		for(i=endX-1; i>start; --i)
	        cout<<numbers[i][start]<<" ";
	}
}

void PrintMatrixClockwisely(int numbers[][5], int columns, int rows)
{
	if(numbers==NULL || columns<=0 ||rows<=0)
		return ;
	int start=0;
	while(columns>start*2 && rows>start*2)
	{
		PrintMatrixInCircle(numbers, columns, rows, start);
		++start;
	}
}





int main()
{ 
	/*
		int **f = new int*[3]; // 先开辟高一级的动态数组
	
		int  i,j;
		for(i = 0;i<3;i++)
			f[i] = new int[4];  // 然后开辟低一级的动态数组
	
		for( i = 0; i<3 ;i++) 
			for( j = 0; j<4;j++)
				f[i][j]= j+1;
 */
	int f[3][5]={
	{1,2,3,4,5},
	{1,2,3,4,5},
	{1,2,3,4,5}
	};
	PrintMatrixClockwisely(f, 3, 5);

	 

	return 0;
}

