#include<iostream>
using namespace std;
#include<vector>

/*
环形路线  ： 
gas[i] : 代表该在加油站能补充的油量
cost[i] :从i到i+1站所消耗的油量

返回能所有绕一圈的起始点的坐标   
*/

// O(n) O(1)
class Solution
{
public:
	vector<int> canCompleteCircuit(vector<int>&gas, vector<int>& cost)
	{
		vector<int>result;
		for(int i=0 ; i<gas.size(); ++i)
		{
			int length =0, sum=0,cur = i;//cur当前开始位置  sum当前油量   length走了多远
			while(length < gas.size())
			{		
				sum =sum +gas[cur] -cost[cur];
				if(sum<0) 
						break; 
				if(cur==gas.size()-1)//数组末尾
				{
				//	cout<<i<<"处出发的汽车，开始转弯       ";
						cur=1;					
				}
			
				length++;	//已经走过的距离
				cur++;
			}				
			if(length ==gas.size())
			{
				//cout<<i<<"处出发的汽车成功"<<endl;
				result.push_back(i);		 
			}
		}
		return result;
	}
};
 

int main()
{
	 vector<int> gas;//0，2，3，5可以环游一周
	 gas.push_back(3);  gas.push_back(3);  gas.push_back(3);  gas.push_back(3); gas.push_back(3); gas.push_back(3);
     
	 vector<int> cost;
	 cost.push_back(2); cost.push_back(4); cost.push_back(3);cost.push_back(2);  cost.push_back(4); cost.push_back(3);
 
	 Solution s;
vector<int> v=s.canCompleteCircuit(gas,cost);

for(vector<int>::iterator it = v.begin(); it !=v.end();it++)//输出结果
cout<<(*it)<<endl;


	return 0;
}
 