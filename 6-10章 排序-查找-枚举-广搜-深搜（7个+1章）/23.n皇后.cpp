#include<iostream>
using namespace std;
#include<vector>

#include<string>


//任意两个棋子不能出现在同行，同列，同斜线中
//O(n!*n)  O(n) 深搜+剪枝

class Solution
{
public:
	vector< vector<string> >solveNQueens(int n)
	{
		vector< vector<string> >result;
		vector<int>C(n,-1);//C[i]表示第i行皇后所在的列编号
		dfs(C, result, 0);
		return result;
	}
private:
	void dfs(vector<int>&C, vector< vector<string> >&result, int row)
	{
		const int N=C.size();
		if(row==N)//终止条件，收敛条件 意味着找到了一个可行解
		{
			vector<string>solution;
			for(int i=0; i<N; ++i)
			{
				string s(N,'.');
				for(int j=0; j<N; ++j)
				{
					if(j==C[i])
						s[j]='Q';
				} //cout<<s<<endl;
				solution.push_back(s);
			}
	/*for(vector<string>::iterator it = solution.begin();  it !=solution.end();   it++)
			{
		 		cout<<(*it)<<"\t";
		 		cout<<endl;
			}cout<<"==============找到一组可行解============="<<endl;
	*/	
    	result.push_back(solution);
			return;
		}
		
		for(int j=0; j<N; ++j)//   一列一列地试
		{	 //if(row == 0)  	cout<<"----------------------------------"<<endl;
			const bool ok=isValid(C, row, j);
			if(!ok){
			 //	cout<<row<<"  "<<j<<"不行"<<endl;
				continue;//该行该列不能放       继续尝试下一列
			}
			 // cout<<row<<"  "<<j<<"行"<<endl;
			
			C[row]=j; //记录可行的列
			dfs(C, result, row+1);//该行可以放一个 就扩展下一行
            // cout<<"该组位置不合法，即将递归回row为"<<row<<"的那一层"<<endl;
			
			//C[row]=-1;//撤销动作
		}
	}
	 

	/*能否在(row,col)放一个皇后. 
	row当前正在处理的行 前面的行已经放了皇后了
		col当前列  
	能否放一个皇后*/
	bool isValid(const vector<int>&C, int row, int col)
	{
	   for(int i =0; i<row; ++i)
	   {	   
		   if(C[i]==col)return false;//在同一列
		  
		   if(abs(i-row)==abs(C[i]-col)) return false;//在同一对角线上
			   
	   }
	   return true;
	}
};


//O(n!)  O(n) 深搜+剪枝

class Solution2
{
public:
	vector< vector<string> >solveNQueens(int n)
	{
		this->columns=vector<bool>(n, false);
		this->main_diag=vector<bool>(2*n-1, false);
		this->anti_diag=vector<bool>(2*n-1, false);

		vector< vector<string> >result;
		vector<int>C(n, -1);//C[i]表示每行皇后所在的列编号
		
		dfs(C, result, 0);
		return result;
	}
private:
	//这三个变量用于剪枝 
	vector<bool>columns;//表示已经放置的皇后占据了哪些列
	vector<bool>main_diag;//占据了那些主对角线
	vector<bool>anti_diag;///占据了哪些副对角线

	void dfs(vector<int>&C, vector< vector<string> >&result, int row)
	{
		const int N=C.size();
		if(row==N)// 终止条件，收敛条件 意味着找到了一个可行解
		{
			vector<string>solution;
			for(int i=0; i<N; ++i)
			{
				string s(N,'.');
				for(int j=0; j<N; ++j)
				{
					if(j==C[i])
						s[j]='Q';
				}
				solution.push_back(s);
			}
			result.push_back(solution);
			return;
		}
		for(int j=0; j<N; ++j)
		{
			 const bool ok= !columns[j] && !main_diag[row-j+N-1] && !anti_diag[row+j];//列 主对角线 副对角线 都满足
			 if(!ok)
				 continue;
			 C[row]=j;
			 columns[j] = main_diag[row-j+N-1] = anti_diag[row+j] = true;//记录
			 dfs(C,result,row+1);//递归下一行
			 columns[j] = main_diag[row-j+N-1] = anti_diag[row+j] = false;//撤销
		}
	}
};






int main()
{
	 Solution2  s;
	 vector< vector<string> > V = s.solveNQueens(4);
 
	 for(vector< vector<string> >::iterator it0 = V.begin();  it0 != V.end();  it0++)
	 {
	 	for(vector<string>::iterator it = (*it0).begin();  it !=(*it0).end();   it++)
		{
				cout<<(*it) <<endl; 
		}
			cout<<endl;
	 }
 
	return 0;
}

