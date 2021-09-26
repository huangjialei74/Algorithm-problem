#include<iostream>
using namespace std;
#include<vector>
#include <numeric>

#define max(a,b)((a)>=(b)?(a):(b))

 
 
//�ݹ� O��n�� O��n��
class Solution
{
public:
	int candy(const vector<int>&ratings)
	{
		vector<int>f(ratings.size());
		int sum=0;
		for(int i=0; i<ratings.size(); ++i)
			sum += solve(ratings,f,i);
		return sum;
	}
	int solve(const vector<int>&ratings, vector<int>&f, int i)
	{
		if(f[i]==0)//֮ǰû�м�¼�͵ݹ���ֵ  �м�¼��ֱ�ӷ���
		{
			f[i]=1;
			if(i>0 && ratings[i] > ratings[i-1])//�ӷǵ�һ����ʼ����
				f[i]=max(f[i], solve(ratings, f, i-1)+1); //��ǰһ��λ��+1 ��� ȡ��ֵ
			if(i< ratings.size()-1 && ratings[i] > ratings[i+1])//�ӷ����һ���½�
				f[i]=max(f[i], solve(ratings, f, i+1)+1);        
		}      //�½�ʱ�����˺���һ����solveֵ   �ݹ�ʱ���������solve����  ������һ�εݹ�ʱ�Ѿ���f[]����ֵ ����Ҫÿ�����ظ��ݹ�
		return f[i];
	}
	  
};





 
int main()
{
	Solution  s;
	vector<int> v ;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);

	 
 	cout<<s.candy(v)<<endl;
	 

	return 0;
}

