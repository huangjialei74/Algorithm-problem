#include<iostream>
using namespace std;
//��ά�������˶������Ի��ݷ����


//�����жϸõ� ��û����һ��    pathLength�ᱻ�Ķ�  ------ �ú����ᱻ��������
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char*str, int& pathLength, bool* visited)
{
	cout<<"����"<<endl;
	if(str[pathLength] == '\0')//�Ѿ��ҵ������ַ�����
	return true;
	bool hasPath = false;
	//�±�ν���
	if(row>=0 && row<rows && col>=0 && col<cols && matrix[row*cols +col] == str[pathLength] && !visited[row*cols+col])
	{
		//�����п��е���һ����
		++pathLength;
		visited[row*cols+col] = true;//��õݹ�����з��ʵ��Լ���

		hasPath = hasPathCore(matrix, rows, cols, row, col-1, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row-1, col, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row, col+1, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row+1, col, str, pathLength, visited);
 	cout<<"��"<<row<<col<<endl;
	    if(!hasPath)//����ʧ��
		{
	    	--pathLength;
		    visited[row*cols+col] = false;
		}		 
	}
	return hasPath;//�ýڵ����Ҫ�� ���߲�����Ҫ��---�ݹ��ȥ
}




bool hasPath(char *matrix,int rows,int cols,char *str)
{
	if(matrix == NULL || rows<1 || cols < 1 ||str == NULL)
	{
		return false;
	}
	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);//����ȫ0:  ȫ��û�б�����
	int pathLength = 0;
	for(int row = 0; row<rows; ++row)
	{	 
		for(int col = 0; col<cols; ++col)//�����е���һ�飬�����Ƿ�����Ϊ�ַ������
		{
			if(hasPathCore(matrix, rows, cols, row, col,str, pathLength, visited))//�ݹ麯�� ���õ��ܷ��γ�һ���ַ���
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
    cout<<"�ҵõ�"<<endl;
}
	return 0;
}

