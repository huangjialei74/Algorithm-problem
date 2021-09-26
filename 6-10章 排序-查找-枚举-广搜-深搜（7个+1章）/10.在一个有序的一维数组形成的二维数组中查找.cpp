#include<iostream>
using namespace std;
#include<vector>




//二分查找O(logn) O(1)
class Solution
{
public:
	bool searchMatrix(const vector<vector<int> > &matrix, int target)
	{
		if(matrix.empty())
			return false;
		const size_t m=matrix.size();//行
		const size_t n=matrix.front().size();//列
		int first=0;
		int last=m*n;
		while(first<last)
		{
			int mid=first+(last-first)/2;//取中间
			int value=matrix[mid/n][mid%n];//取中间的值  n为列数
			if(value==target)
				return true;
			else if(value<target)
				first=mid+1;
			else
				last=mid;
		} 
		return false;
	}
		 
};


 

int main()
{
	 

	return 0;
}

