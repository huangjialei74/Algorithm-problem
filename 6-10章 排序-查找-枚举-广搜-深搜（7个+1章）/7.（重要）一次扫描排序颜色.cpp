#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>



/*
use the integers 0,1,and 2 to represent the color red,white,and blue
the same color are adjacent
counting sort is a two-pass algorithm
*/

//法1  
class Solution1
{
public:
	void sortColors(vector<int>&A)
	{
		int counts[3]={0}  ;		
		for(int k=0; k<A.size(); k++)
			counts[A[k]]++;
		for(int i=0,index=0; i<3; i++)
			for(int j=0; j<counts[i]; j++)
				A[index++]=i;
	}
};

//法2 双指针
class Solution2
{
public:
	void sortColors(vector<int>&A)
	{
		 int red=0,blue=A.size()-1;//跟两头交换//把0移到前面，2移到后面
		 for(int i=0; i<blue+1; )
		 {
			 if(A[i]==0)
				 swap(A[i++], A[red++]);//此处为i++ 和 red++ 
			 else if(A[i]==2)
				 swap(A[i], A[blue--]);//此处为i  和 blue--  因为i与blue交换后， A[i]需要在下一轮中被判断
			 else
				  i++;
		 }
	}
	 
};

/*
class Solution3
{
public:
	void sortColors(vector<int>&nums)
	{
		partition(partition(nums.begin(), nums.end(), bind1st(equal_to<int>(),0)), nums.end(), bind1st(equal_to<int>(), 1));
	}
};
class Solution4
{
public: 
	void sortColors(vector<int>&nums)
	{
		partition(partition(nums.begin(), nums.end(), bind1st(equal_to<int>(), 0)), nums.end(), bind1st(equal_to<int>(),1));
	}
private:
	template<typename ForwardIterator,typename UnaryPredicate>
		ForwardIterator partition(ForwardIterator first,ForwardIterator last,UnaryPredicate pred)
	{
		auto pos=first;
		for(; first!=last; ++first)
			if(pred(*first))
				swap(*first,*pos++);
			return pos;
	}
};
*/

int main()
{
	 

	return 0;
}

