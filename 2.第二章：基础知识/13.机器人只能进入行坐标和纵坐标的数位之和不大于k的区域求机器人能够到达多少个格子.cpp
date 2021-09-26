#include<iostream>
using namespace std;





int getDigitSum(int number)
{
	int sum = 0;
	while(number>0)
	{
		sum += number%10;
		number/=10;
	}
	return sum;
}


bool check(int threshold, int rows, int cols, int row , int col ,bool* visited)//visited为false表示 以前没有被访问过
{
	if(row>=0 && row<rows && col>=0 && col<cols && getDigitSum(row)+getDigitSum(col) <=threshold && !visited[row*cols+col])
		return true;
	return false;
}
//(0,0)开始 准备进入(i,j)时，看能否进入(i,j-1), (i-1,j), (i,j+1), (i+1,j)  回溯算法
int movingCountCore(int threshold, int rows, int cols, int row , int col ,bool *visited)
{
	int count = 0;
	if(check(threshold, rows, cols, row, col, visited))
	{
		visited[row*cols+col] = true;
		count = 1+ movingCountCore(threshold, rows, cols, row-1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col-1, visited)
			+ movingCountCore(threshold, rows, cols, row+1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col+1, visited);
	}
	return count;
}

int movingCounting(int threshold, int rows, int cols)
{
	if(threshold<0 || rows<=0 || cols<=0)
		return 0;
	bool *visited = new bool[rows*cols];
	for(int i = 0; i<rows*cols; i++)
		visited[i] = false;

	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
	delete []visited;
	return count;
}


















int main()
{
	 

	return 0;
}

