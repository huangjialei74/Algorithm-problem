#include<iostream>
using namespace std;
#include<vector>

#include<string>


//�����������Ӳ��ܳ�����ͬ�У�ͬ�У�ͬб����
//O(n!*n)  O(n) ����+��֦

class Solution
{
public:
	vector< vector<string> >solveNQueens(int n)
	{
		vector< vector<string> >result;
		vector<int>C(n,-1);//C[i]��ʾ��i�лʺ����ڵ��б��
		dfs(C, result, 0);
		return result;
	}
private:
	void dfs(vector<int>&C, vector< vector<string> >&result, int row)
	{
		const int N=C.size();
		if(row==N)//��ֹ�������������� ��ζ���ҵ���һ�����н�
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
			}cout<<"==============�ҵ�һ����н�============="<<endl;
	*/	
    	result.push_back(solution);
			return;
		}
		
		for(int j=0; j<N; ++j)//   һ��һ�е���
		{	 //if(row == 0)  	cout<<"----------------------------------"<<endl;
			const bool ok=isValid(C, row, j);
			if(!ok){
			 //	cout<<row<<"  "<<j<<"����"<<endl;
				continue;//���и��в��ܷ�       ����������һ��
			}
			 // cout<<row<<"  "<<j<<"��"<<endl;
			
			C[row]=j; //��¼���е���
			dfs(C, result, row+1);//���п��Է�һ�� ����չ��һ��
            // cout<<"����λ�ò��Ϸ��������ݹ��rowΪ"<<row<<"����һ��"<<endl;
			
			//C[row]=-1;//��������
		}
	}
	 

	/*�ܷ���(row,col)��һ���ʺ�. 
	row��ǰ���ڴ������ ǰ������Ѿ����˻ʺ���
		col��ǰ��  
	�ܷ��һ���ʺ�*/
	bool isValid(const vector<int>&C, int row, int col)
	{
	   for(int i =0; i<row; ++i)
	   {	   
		   if(C[i]==col)return false;//��ͬһ��
		  
		   if(abs(i-row)==abs(C[i]-col)) return false;//��ͬһ�Խ�����
			   
	   }
	   return true;
	}
};


//O(n!)  O(n) ����+��֦

class Solution2
{
public:
	vector< vector<string> >solveNQueens(int n)
	{
		this->columns=vector<bool>(n, false);
		this->main_diag=vector<bool>(2*n-1, false);
		this->anti_diag=vector<bool>(2*n-1, false);

		vector< vector<string> >result;
		vector<int>C(n, -1);//C[i]��ʾÿ�лʺ����ڵ��б��
		
		dfs(C, result, 0);
		return result;
	}
private:
	//�������������ڼ�֦ 
	vector<bool>columns;//��ʾ�Ѿ����õĻʺ�ռ������Щ��
	vector<bool>main_diag;//ռ������Щ���Խ���
	vector<bool>anti_diag;///ռ������Щ���Խ���

	void dfs(vector<int>&C, vector< vector<string> >&result, int row)
	{
		const int N=C.size();
		if(row==N)// ��ֹ�������������� ��ζ���ҵ���һ�����н�
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
			 const bool ok= !columns[j] && !main_diag[row-j+N-1] && !anti_diag[row+j];//�� ���Խ��� ���Խ��� ������
			 if(!ok)
				 continue;
			 C[row]=j;
			 columns[j] = main_diag[row-j+N-1] = anti_diag[row+j] = true;//��¼
			 dfs(C,result,row+1);//�ݹ���һ��
			 columns[j] = main_diag[row-j+N-1] = anti_diag[row+j] = false;//����
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

