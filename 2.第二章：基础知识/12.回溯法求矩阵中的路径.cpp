#include<iostream>
using namespace std;
//二维方格内运动都可以回溯法解决


//用来判断该点 有没有下一个    pathLength会被改动  ------ 该函数会被大量调用
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char*str, int& pathLength, bool* visited)
{
	cout<<"调用"<<endl;
	if(str[pathLength] == '\0')//已经找到完整字符串了
	return true;
	bool hasPath = false;
	//下标の界限
	if(row>=0 && row<rows && col>=0 && col<cols && matrix[row*cols +col] == str[pathLength] && !visited[row*cols+col])
	{
		//假设有可行的下一个点
		++pathLength;
		visited[row*cols+col] = true;//免得递归过程中访问到自己了

		hasPath = hasPathCore(matrix, rows, cols, row, col-1, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row-1, col, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row, col+1, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row+1, col, str, pathLength, visited);
 	cout<<"行"<<row<<col<<endl;
	    if(!hasPath)//假设失败
		{
	    	--pathLength;
		    visited[row*cols+col] = false;
		}		 
	}
	return hasPath;//该节点符合要求 或者不符合要求---递归回去
}




bool hasPath(char *matrix,int rows,int cols,char *str)
{
	if(matrix == NULL || rows<1 || cols < 1 ||str == NULL)
	{
		return false;
	}
	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);//设置全0:  全部没有被访问
	int pathLength = 0;
	for(int row = 0; row<rows; ++row)
	{	 
		for(int col = 0; col<cols; ++col)//把所有点试一遍，看其是否能作为字符串起点
		{
			if(hasPathCore(matrix, rows, cols, row, col,str, pathLength, visited))//递归函数 检查该点能否形成一个字符串
			{		
				return true;
			} 
		}
	}
	delete []visited;
	return false;
}

 


 
int main()
{
	
 char *matrix = "1102c311d3311234" ;
if(hasPath( matrix, 4, 4,"1234"))
{
    cout<<"找得到"<<endl;
}
	return 0;
}

