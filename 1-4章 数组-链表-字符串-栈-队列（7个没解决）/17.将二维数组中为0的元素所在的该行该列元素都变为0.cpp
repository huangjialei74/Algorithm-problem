#include<iostream>
using namespace std;
#include<vector>



class Solution
{
public:
	void setZeroes(vector< vector<int> >& matrix)
	{
		const size_t m=matrix.size();//行数
		const size_t n=matrix[0].size();//列数
	 
        size_t i,j;
	 
		for(i=1;i<m;i++)
			for(j=1;j<n;j++)
				if(matrix[i][j]==0)
				{
					matrix[0][j]=0;			//哪个元素为0 就让该行 该列第一个为0		
			    	matrix[i][0]=0;
				}

		for(i=0;i<n;i++)//第一行
			if(matrix[0][i]==0)
			{
				 for(j=0; j<m ;j++)
					 matrix[j][i]=0;  //将该列赋值为0
			}
		for(i=0;i<m;i++)//第一列
			if(matrix[i][0]==0)
			{
				for(j=0; j<n ;j++) 
					matrix[i][j]=0;//将该行赋值为0
			} 
	}
 
 
};


int main()
{
	 vector<int>v1 ;
	 v1.push_back(1); v1.push_back(1); v1.push_back(1); v1.push_back(1);

	 vector<int>v2;
	 v2.push_back(1); v2.push_back(0); v2.push_back(1); v2.push_back(1);

	 vector<int>v3 ;
	 v3.push_back(1); v3.push_back(1); v3.push_back(1); v3.push_back(1);

	 vector<int>v4;
	 v4.push_back(1); v4.push_back(1); v4.push_back(1); v4.push_back(1);

	 vector< vector<int> >v;
	 v.push_back(v1); v.push_back(v2); v.push_back(v3); v.push_back(v4);

	 Solution s;
	 s.setZeroes (v);

	 for(vector< vector<int> >::iterator it1 = v.begin() ;it1 != v.end() ;it1++)
	 {
		 for(vector<int>::iterator it3 = (*it1).begin(); it3 != (*it1).end() ; it3++)
		 {
			 cout<<(*it3)<<" ";
		 }
		 cout<<endl;
	 }



	return 0;
}

