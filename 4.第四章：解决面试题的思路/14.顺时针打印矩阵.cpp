#include<iostream>
using namespace std;

/*
�Ѿ��������ɸ�Ȧ��ÿ�δ�ӡһ��Ȧ
����ÿ��Ȧ������㣨���Ͻǣ���start,start��������ѭ����ӡÿ��Ȧ�������� columns>2*startX, columns>2*startY
��ӡ���һ��������Ȧ��ʣ�µĹ�����һ��Ȧ��3�����������ֻ��ִ�д�ӡȦ�е�1-2�������������ӡһ��  ����ӡһ�������ŵ�һ�У���ӡһ���Ѿ������һ��
*/

void PrintMatrixInCircle(int numbers[][5], int columns, int rows,int start)//����������޹ؽ�Ҫnumbers[][4]
{
	int endX=columns-1-start;//2
	int endY=rows-1-start;//3

	int i;
	//�����Ҵ�ӡһ��
	for(i=start; i<=endY; ++i)
		cout<<numbers[start][i]<<" ";
	//���ϵ��´�ӡһ��
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
		int **f = new int*[3]; // �ȿ��ٸ�һ���Ķ�̬����
	
		int  i,j;
		for(i = 0;i<3;i++)
			f[i] = new int[4];  // Ȼ�󿪱ٵ�һ���Ķ�̬����
	
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

