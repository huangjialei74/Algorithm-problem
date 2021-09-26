#include<iostream>
using namespace std;
#include<vector>
#include <unordered_map>

#define max(a,b)((a)>=(b)?(a):(b))

//要求O(n)   快速排序后再取为O（n*logn）

/*
用哈希表unordered_map<int,bool>used记录每个元素是否使用  对每个元素 从中心往左右扩张  记录最大长度
O(n)  O(n) 
*/

class Solution{
public:
	int longestConsecutive(const vector<int>&nums)
	{ 
	    unordered_map<int,bool>used;
	    for(auto i:nums)
			used[i]=false;
		int longest=0;
		int j;
		for(auto i:nums)
		{
			if(used[i])
				continue;
			int length=1;
			used[i]=true;
			
			for(j=i+1; used.find(j)!=used.end(); ++j)//右边扩张
			{
				used[j]=true;
				++length;
			}
			for(j=i-1;used.find(j)!=used.end();--j)//左边扩张
			{
				used[j]=true;
				++length;
			}
			longest=max(longest,length);
		}
		return longest;
	}
};











int main()
{
	 

	return 0;
}

