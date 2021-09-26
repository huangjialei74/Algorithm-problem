#include<iostream>
using namespace std;
#include<vector>
#include <unordered_map>

#define max(a,b)((a)>=(b)?(a):(b))

//Ҫ��O(n)   �����������ȡΪO��n*logn��

/*
�ù�ϣ��unordered_map<int,bool>used��¼ÿ��Ԫ���Ƿ�ʹ��  ��ÿ��Ԫ�� ����������������  ��¼��󳤶�
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
			
			for(j=i+1; used.find(j)!=used.end(); ++j)//�ұ�����
			{
				used[j]=true;
				++length;
			}
			for(j=i-1;used.find(j)!=used.end();--j)//�������
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

