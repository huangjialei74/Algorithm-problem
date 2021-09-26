#include<iostream>
using namespace std;
#include<vector>

/*
����·��  �� 
gas[i] : ������ڼ���վ�ܲ��������
cost[i] :��i��i+1վ�����ĵ�����

������������һȦ����ʼ�������   
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
			int length =0, sum=0,cur = i;//cur��ǰ��ʼλ��  sum��ǰ����   length���˶�Զ
			while(length < gas.size())
			{		
				sum =sum +gas[cur] -cost[cur];
				if(sum<0) 
						break; 
				if(cur==gas.size()-1)//����ĩβ
				{
				//	cout<<i<<"����������������ʼת��       ";
						cur=1;					
				}
			
				length++;	//�Ѿ��߹��ľ���
				cur++;
			}				
			if(length ==gas.size())
			{
				//cout<<i<<"�������������ɹ�"<<endl;
				result.push_back(i);		 
			}
		}
		return result;
	}
};
 

int main()
{
	 vector<int> gas;//0��2��3��5���Ի���һ��
	 gas.push_back(3);  gas.push_back(3);  gas.push_back(3);  gas.push_back(3); gas.push_back(3); gas.push_back(3);
     
	 vector<int> cost;
	 cost.push_back(2); cost.push_back(4); cost.push_back(3);cost.push_back(2);  cost.push_back(4); cost.push_back(3);
 
	 Solution s;
vector<int> v=s.canCompleteCircuit(gas,cost);

for(vector<int>::iterator it = v.begin(); it !=v.end();it++)//������
cout<<(*it)<<endl;


	return 0;
}
 