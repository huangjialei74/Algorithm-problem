#include<iostream>
using namespace std;
#include<vector>

//先沿着左下 右上的斜线翻转  再沿着水平对称轴翻转

// O(n^2) O(1)
class Solution
{
public: 
	void rotate(vector< vector<int> >& matrix)
	{
		const int n=matrix.size();
		int i,j;
		for(i=0;i<n;++i)// 
			for(j=0; j<n-i; ++j)
				swap(matrix[i][j], matrix[n-1-j][n-1-i]);//二维数组不是坐标轴    第一个是第几行 第二个是第几列
		for(i=0; i<n/2; ++i)// 沿着水平对称轴反转
			for(j=0;j<n;++j)
			    swap(matrix[i][j], matrix[n-1-i][j]);	
	}	
 

};



 
 

int main()
{
	
	 Solution s;
	 vector<int>v0; vector<int>v1; vector<int>v2;
	 		
		 v0.push_back(1); v0.push_back(2); v0.push_back(3);
		 v1.push_back(4); v1.push_back(5); v1.push_back(6);
		 v2.push_back(7);	v2.push_back(8);	 v2.push_back(9);	
	   
	 vector< vector<int> > v;
	 v.push_back(v0);
	 v.push_back(v1);
	 v.push_back(v2);

	 for(vector< vector<int> >::iterator it1 = v.begin() ;it1 != v.end() ;it1++)
	 {
		 for(vector<int>::iterator it3 = (*it1).begin(); it3 != (*it1).end() ; it3++)
		 {
			 cout<<(*it3)<<" ";
		 }
		 cout<<endl;
	 }
	 cout<<endl;

	 s.rotate(v);

	 for(vector< vector<int> >::iterator it = v.begin() ;it != v.end() ;it++)
	 {
		 for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end() ; it2++)
		 {
			 cout<<(*it2)<<" ";
		 }
		 cout<<endl;
	 }



	return 0;
}

