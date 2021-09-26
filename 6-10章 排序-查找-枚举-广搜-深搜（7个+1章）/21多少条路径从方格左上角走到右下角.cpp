#include<iostream>
using namespace std;

#include<vector>


//深搜 大集合会超时
class Solution
{
public:
	int uniquePaths(int m,int n)
	{
		if(m<1||n<1)
			return 0;//终止条件
		if(m==1 && n==1)//1，1即到达了
			return 1;//收敛条件
		return uniquePaths(m-1,n) + uniquePaths(m,n-1);
	}
};




//备忘录法O(n^2)  O(n^2)
class Solution2
{
public:
	int uniquePaths(int m,int n)
	{
      vector<int>v1; 
	  for(int i = 0;i<n;i++) v1.push_back(0);
	  for(int j = 0;j<m;j++) f.push_back(v1);//初始化 全0
	 
		f[0][0]=1;	//f[x][y]表示从(0,0)到(x,y)的路径条数
		return dfs(m-1,n-1);
	}
private: 
	vector< vector<int> >f;//缓存
	
	int dfs(int x,int y)
	{
		if(x<0||y<0)//数据非法 终止条件
			return 0;
		if(x==0 && y==0)
			return f[0][0];	//回到起点 收敛条件

		if(f[x][y]>0)		//有记录 -不用再重头算
		{
			return f[x][y];
		}
		else //没有记录 就计算
		{
			return f[x][y] = dfs(x-1,y) + dfs(x,y-1);
		}
	}
 
};



// 动规O(n^2) O(n) //想不懂原理
class Solution3
{
public:
	int uniquePaths(int m,int n)
	{
		vector<int>f(n,0);
		f[0]=1;
		for(int i=0; i<m; i++)//行数
		{
			for(int j=1; j<n; j++)//列数
			{
				//左边的f[j]表示更新后的f[j]，与公式中的f[i][j]对应
				//右边的f[j]表示旧的f[j] ，   与公式中的f[i-1][j]对应
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

