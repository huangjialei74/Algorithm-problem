#include<iostream>
using namespace std;
#include<vector>
//一个排序数组   不知道旋转成什么样子了
//二分查找  --在于左右边界的确定


// O(logn)   O(1)
class
Solution
{
public:
	int search(const vector <int> &nums,int target)
	{
		int first=0, last=nums.size();
		while(first!=last)
		{
			const int mid=first+(last-first)/2;
			if(nums[mid]==target)
				return mid;
			if(nums[first]<=nums[mid])//mid在第一个增长上面
			{
				if(nums[first]<=target && target<nums[mid])
					last=mid; //该范围连续  且 目标值在此范围内
				else
				    first=mid+1;//该范围不连续  仍然是先增  悬崖 再增
			}
			else //mid在第二个增长上面
			{
				if(nums[mid]<target && target<=nums[last-1])
					first=mid+1;  //该范围连续  且 目标值在此范围内
				else
					last=mid;//该范围不连续  仍然是先增  悬崖 再增    
			}
		}
		return -1;
	}
};




int main()
{
	vector<int>v;
	v.push_back(3);v.push_back(4);v.push_back(5);v.push_back(6);v.push_back(1);v.push_back(2);
	Solution s;
	cout<<s.search(v,6)<<endl;
	 

	return 0;
}

