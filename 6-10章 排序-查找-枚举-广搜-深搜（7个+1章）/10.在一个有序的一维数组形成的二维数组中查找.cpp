#include<iostream>
using namespace std;
#include<vector>




//���ֲ���O(logn) O(1)
class Solution
{
public:
	bool searchMatrix(const vector<vector<int> > &matrix, int target)
	{
		if(matrix.empty())
			return false;
		const size_t m=matrix.size();//��
		const size_t n=matrix.front().size();//��
		int first=0;
		int last=m*n;
		while(first<last)
		{
			int mid=first+(last-first)/2;//ȡ�м�
			int value=matrix[mid/n][mid%n];//ȡ�м��ֵ  nΪ����
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

