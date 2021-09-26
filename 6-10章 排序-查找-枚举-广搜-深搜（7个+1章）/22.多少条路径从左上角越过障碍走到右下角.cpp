#include<iostream>
using namespace std;

#include<vector>

//����¼��
class Solution
{
public:
	int uniquePathsWithObstacles(const vector< vector<int> >& obstacleGrid)
	{
		const int m= obstacleGrid.size();
		const int n= obstacleGrid[0].size();
		if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)//������ Ŀ�ĵ� ���ϰ��Ļ���...
			return 0;
		f=vector< vector<int> >(m, vector<int>(n,0));//��ʼ״̬���ϰ�

	//	f[0][0] = obstacleGrid[0][0]==1 ? 0: 1; ΪʲôҪ�жϣ� 
		f[0][0] =1;
		return dfs(obstacleGrid, m-1, n-1);
	}
private:
	vector< vector<int> >f;	//����

	// return��(0,0)��(x,y)·������
	int dfs(const vector< vector<int> >&obstacleGrid, int x, int y)
	{
		if(x<0||y<0)
			return 0;//���ݷǷ� ��ֹ����
		  
		if(obstacleGrid[x][y])//�ߵ����ϰ�����----����������
			return 0;

		if(x==0 && y==0)
			return f[0][0];//�ص����  ��������

		if(f[x][y]>0)
		{
			return f[x][y];//����֮ǰ��¼������
		}
		else
		{
			return f[x][y]=dfs(obstacleGrid, x-1, y) + dfs(obstacleGrid, x, y-1);
		}
	}
};


//����  O(n^2   O(n)
class Solution2
{
public:
	int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid)
	{
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();
		if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
			return 0;

		vector<int>f(n,0);
	//	f[0]=obstacleGrid[0][0]==1 ? 0: 1;  ΪʲôҪ�жϣ� 
		f[0]=1;
		for(int i=0; i<m; i++)
		{
		//	f[0]= f[0]==0 ? 0: (obstacleGrid[i][0]==1 ? 0 : 1); //Ϊʲô���滹Ҫ�ж�f[0]==0  ��
			f[0]=obstacleGrid[i][0]==1 ? 0 : 1;
			for(int j=1; j<n; j++)
				f[j] = obstacleGrid[i][j]==1 ? 0 : (f[j]+f[j-1]); 
		}
		return f[n-1];
	}
};

 

int main()
{
	/*
	 vector< vector<int> > obstacleGrid;
	 vector<int>v1(3,0);  v1[2]=1;
	 vector<int>v2(3,0); // v2[1] = 1;
	 vector<int>v3(3,0);  //v3[2]=1;
	 obstacleGrid.push_back(v1);  obstacleGrid.push_back(v2);  obstacleGrid.push_back(v3);
    Solution2  s;
	cout<<s.uniquePathsWithObstacles(obstacleGrid)<<endl;
*/	 

	return 0;
}

