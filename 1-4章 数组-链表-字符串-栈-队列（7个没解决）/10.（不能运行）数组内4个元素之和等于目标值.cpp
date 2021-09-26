#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
/*
用一个hashmap先缓存两数之和
时间复杂度：平均O(n2) 最坏：O(n4) 空间：O(n2)
*/


class Solution1
{
public:
	vector<vector<int>>fourSum(vector<int>&nums,int target)
	{
		vector<vector<int>>result;
		if(nums.size()<4)
			return result;
		sort(nums.begin(),nums.end());//先排序
		unordered_map<int, vector< pair<int,int> >  >cache;//pair()将两个数组成一组数

		for(size_t a=0; a<nums.size();  ++a) //把所有的两数组合的值记录  key为元素值之和    value为下标
		{
			for(size_t b=a+1;  b<nums.size();  ++b)//size_t无符号整数
			{
				cache[ nums[a]+nums[b] ].push_back( pair<int,int>(a,b) );
			}
		}
	 
			for(int c=0; c<nums.size(); ++c)//从0开始
			{
				for(size_t d=c+1; d<nums.size(); ++d)
				{
					const int key = target - nums[c] -  nums[d];
					if(cache.find(key)==cache.end())//不存在任意两数之和 等于 该值
						continue;
					const auto &vec = cache[key]; 
					for(size_t k=0; k<vec.size(); ++k) //存在就判断  ---------   一句话就判断是否相等
					{
						if(c <= vec[k].second)  //first<second 且c<d ,   故second <c时满足  互不相等
							continue;					 
						result.push_back({nums[vec[k].first], nums[vec[k].second], nums[c], nums[d]});
					}
				}
			}
			sort(result.begin(),result.end()); //排序一下
			result.erase(unique(result.begin(),result.end()),result.end());  //unique（）将重复的元素放到末尾 并返回其地址    
			return result;
	}
};



/*
O(n2) O(n2)
multimap可以保存重复的键值对 
算了  没搞懂
*/

class Solution2
{
public:
	vector<vector<int> >fourSum(vector<int>&nums,inttarget)
	{
		vector< vector<int> >result;
		if(nums.size()<4 )
			return result;
		sort(nums.begin(), nums.end());
		unordered_multimap<int, pair<int,int>>cache;

		for(int i=0; i+1<nums.size(); ++i)
			for(int j=i+1; j<nums.size(); ++j)
				cache.insert(make_pair(nums[i]+nums[j], make_pair(i,j)));


			for(auto i=cache.begin(); i!=cache.end();++i)
			{
				int x = target- i->first;//目标值减去第一个元素
				auto range = cache.equal_range(x);
				for(auto j = range.first;  j! = range.second; ++j)
				{
					auto a=i->second.first;
					autob=i->second.second;
					autoc=j->second.first;
					autod=j->second.second;
					if(a!=c && a!=d && b!=c && b!=d)
					{
						vector<int>vec={nums[a], nums[b], nums[c], nums[d]};
						sort(vec.begin(),vec.end());
						result.push_back(vec);
					}
				}
			}
			sort(result.begin(), result.end());
			result.erase(unique(result.begin(), result.end()), result.end());
			return result;
	}
};













int main()
{
	 

	return 0;
}

