#include<iostream>
using namespace std;
#include<string>
//����ö��  ��ÿ��Ԫ��Ϊ�м�Ԫ�� ͬʱ���ҳ��� ���Ӷ�O(n2)
//���仯����
/*���� ��f(i, j)  = true :        i = j
                    s[i] == s[j]     j=i+1
					S[i] == S[j]andf(i+1,j?1),    j>i+1
*/
//Manacher's Algorithm,   http://leetcode.com/2011/11/longest.palindromic-substring-part-ii.html

/*
���仯���� �� Manacher's Algorithm̫����
*/



//���� O(n2) O(n2)

class Solution
{
public:
	string longestPalindrome(const string &s)
	{
		const int n=s.size(); 
/*
��������forѭ��Ƕ��ʱ��ֻ�õ��˴洢�ռ��һ��  ����һ�������Σ�������½�Ϊ��0��0��ʱ��ֻ�õ���y=x�����ߵ��·�
*/
		//��ά��̬����
		bool **f = new bool*[n]; // �ȿ��ٸ�һ���Ķ�̬����
		size_t i, j ;
		for(i = 0;i<n;i++)
			f[i] = new bool[n];  // Ȼ�󿪱ٵ�һ���Ķ�̬����
	
		for( i = 0; i<n ;i++) 
			for( j = 0; j<n;j++)
				f[i][j]= false;
			  
		// vector�ᳬʱ
		size_t max_len=1,start=0;//��� ���յ�
		for( i=0; i<s.size(); i++)//"1234554300"
		{
			f[i][i]=true;
			for( j=0; j<i; j++)//j<i
			{ 
				f[j][i] = (s[j]==s[i] && (i-j<2 || f[j+1][i-1]) );
/*����������ַ���  ��i�����һ���ַ�0ʱ,  i=str.size()-1, j��0��ʼ   �ж�s[j]==s[i]ָ��β���ַ��಻��ȣ�
�ٿ�f[j+1][i-1]���������м���ַ��Ƿ����*/
				if(f[j][i] && max_len<(i-j+1))
				{
					max_len=i-j+1;//�µ���󳤶�
					start=j;//�����j
				}
			}
		}

		for(i = 0;i<n;i++)//���ͷŵ�һ����̬����
		{
			delete [](f[i]) ;
		} 
	 	delete []f;// Ȼ���ͷŸ�һ���Ķ�̬����
		return s.substr(start, max_len);
	}
 
};









int main()
{
	Solution s;
	cout<<s.longestPalindrome2("1234554300")<<endl;
	 

	return 0;
}

