#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
/*
��һ��hashmap�Ȼ�������֮��
ʱ�临�Ӷȣ�ƽ��O(n2) ���O(n4) �ռ䣺O(n2)
*/


class Solution1
{
public:
	vector<vector<int>>fourSum(vector<int>&nums,int target)
	{
		vector<vector<int>>result;
		if(nums.size()<4)
			return result;
		sort(nums.begin(),nums.end());//������
		unordered_map<int, vector< pair<int,int> >  >cache;//pair()�����������һ����

		for(size_t a=0; a<nums.size();  ++a) //�����е�������ϵ�ֵ��¼  keyΪԪ��ֵ֮��    valueΪ�±�
		{
			for(size_t b=a+1;  b<nums.size();  ++b)//size_t�޷�������
			{
				cache[ nums[a]+nums[b] ].push_back( pair<int,int>(a,b) );
			}
		}
	 
			for(int c=0; c<nums.size(); ++c)//��0��ʼ
			{
				for(size_t d=c+1; d<nums.size(); ++d)
				{
					const int key = target - nums[c] -  nums[d];
					if(cache.find(key)==cache.end())//��������������֮�� ���� ��ֵ
						continue;
					const auto &vec = cache[key]; 
					for(size_t k=0; k<vec.size(); ++k) //���ھ��ж�  ---------   һ�仰���ж��Ƿ����
					{
						if(c <= vec[k].second)  //first<second ��c<d ,   ��second <cʱ����  �������
							continue;					 
						result.push_back({nums[vec[k].first], nums[vec[k].second], nums[c], nums[d]});
					}
				}
			}
			sort(result.begin(),result.end()); //����һ��
			result.erase(unique(result.begin(),result.end()),result.end());  //unique�������ظ���Ԫ�طŵ�ĩβ ���������ַ    
			return result;
	}
};



/*
O(n2) O(n2)
multimap���Ա����ظ��ļ�ֵ�� 
����  û�㶮
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
				int x = target- i->first;//Ŀ��ֵ��ȥ��һ��Ԫ��
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

