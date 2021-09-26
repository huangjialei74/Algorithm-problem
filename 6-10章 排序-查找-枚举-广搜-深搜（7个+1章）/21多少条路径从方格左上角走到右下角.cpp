#include<iostream>
using namespace std;

#include<vector>


//���� �󼯺ϻᳬʱ
class Solution
{
public:
	int uniquePaths(int m,int n)
	{
		if(m<1||n<1)
			return 0;//��ֹ����
		if(m==1 && n==1)//1��1��������
			return 1;//��������
		return uniquePaths(m-1,n) + uniquePaths(m,n-1);
	}
};




//����¼��O(n^2)  O(n^2)
class Solution2
{
public:
	int uniquePaths(int m,int n)
	{
      vector<int>v1; 
	  for(int i = 0;i<n;i++) v1.push_back(0);
	  for(int j = 0;j<m;j++) f.push_back(v1);//��ʼ�� ȫ0
	 
		f[0][0]=1;	//f[x][y]��ʾ��(0,0)��(x,y)��·������
		return dfs(m-1,n-1);
	}
private: 
	vector< vector<int> >f;//����
	
	int dfs(int x,int y)
	{
		if(x<0||y<0)//���ݷǷ� ��ֹ����
			return 0;
		if(x==0 && y==0)
			return f[0][0];	//�ص���� ��������

		if(f[x][y]>0)		//�м�¼ -��������ͷ��
		{
			return f[x][y];
		}
		else //û�м�¼ �ͼ���
		{
			return f[x][y] = dfs(x-1,y) + dfs(x,y-1);
		}
	}
 
};



// ����O(n^2) O(n) //�벻��ԭ��
class Solution3
{
public:
	int uniquePaths(int m,int n)
	{
		vector<int>f(n,0);
		f[0]=1;
		for(int i=0; i<m; i++)//����
		{
			for(int j=1; j<n; j++)//����
			{
				//��ߵ�f[j]��ʾ���º��f[j]���빫ʽ�е�f[i][j]��Ӧ
				//�ұߵ�f[j]��ʾ�ɵ�f[j] ��   �빫ʽ�е�f[i-1][j]��Ӧ
				f[j]=f[j]+f[j-1];//f[i][j]= f[i-1][j]+ f[i-2][j]
			}
		}
		return f[n-1];
	}
};

 

int main()
{
	Solution3 s;
	cout<<s.uniquePaths(2,2)<<endl;
	 

	return 0;
}

