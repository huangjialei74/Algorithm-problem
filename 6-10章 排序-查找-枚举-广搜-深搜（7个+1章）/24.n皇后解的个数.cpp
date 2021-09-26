#include<iostream>
using namespace std;
#include<vector>


// O(n!*n) O(n)
class Solution
{
public:
	int totalNQueens(int n)
	{
		this->count=0;
		vector<int>C(n,0);
	  dfs(C,0);
	  return this->count;
	}
private:
	int count;
		 void dfs(vector<int>&C,int row)
		 {
			 const int N=C.size();
			 if(row==N)//找到可行解
			 {
				 ++this->count;
				 return;
			 }

			 for(int j=0; j<N; ++j)
			 {
				  const bool ok=isValid(C, row, j);
				  if(!ok)  continue;
				  C[row]=j;
				  dfs(C, row+1);//递归进去
			 }
		 }
		  bool  isValid(const vector<int>&C,int row,int col)
		  {
			  for(int i=0; i<row; ++i)
			  {
				  if(C[i]==col)
					  return false;
				  if(abs(i-row)==abs(C[i]-col))
					  return false;
			  }
			  return true;
		  }
};





// O(n!) O(n)
class Solution2
{
public:
	int totalNQueens(int n)
	{
		this->count=0;
		this->columns=vector<bool>(n,false);
		this->main_diag=vector<bool>(2*n-1,false);
		this->anti_diag=vector<bool>(2*n-1,false);
		vector<int>C(n,0);
		dfs(C,0);
		return this->count;
	}
private:int count;vector<bool>columns;
		vector<bool>main_diag;
		vector<bool>anti_diag;
		void dfs(vector<int>&C,int row)
		{
			const int N=C.size();
			if(row==N)
			{
				++this->count;
				return;
			}
			for(int j=0; j<N; ++j)
			{
				  const bool ok= !columns[j] && !main_diag[row-j+N] && !anti_diag[row+j];
				  if(!ok)
					  continue;
				   C[row]=j;
				   columns[j]=main_diag[row-j+N]=anti_diag[row+j]=true;
				   dfs(C,row+1);
				   columns[j]= main_diag[row-j+N] =anti_diag[row+j] =false;
			}
		}
};










int main()
{
	 

	return 0;
}

