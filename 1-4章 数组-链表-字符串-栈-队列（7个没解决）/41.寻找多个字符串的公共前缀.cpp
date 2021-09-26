#include<iostream>
using namespace std;
#include<string>
#include<vector>



//����ɨ��  ֱ����i������ͬ
//O(n1+n2+n3+...)
class Solution1
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		if(strs.empty())
			return "";
		for(int idx=0; idx<strs[0].size(); ++idx)//��һ���ַ����ĳ���
		{
			for(int i=1; i<strs.size(); ++i)
			{
				if(strs[i][idx] != strs[0][idx])//ʲôʱ��ĳ�ַ������һ���ַ����Ķ�Ӧλ��ͬ
					return strs[0].substr(0,idx);//��ȡ��ͬ����
			}
		}
		return strs[0];//ѭ�����ȫ��ִ������ �Ǿͱ�ʾȫ����ͬ
	}
	 
};




//����ɨ�� ÿ���ַ����� ��һ���ַ�����ƥ��  ĳ���ַ�����ͬʱ ����һ���ַ��� ��¼ÿ����󳤶�
//O(n1+n2+n3+...)
class Solution2
{
public:
	string longestCommonPrefix(vector<string>&strs)
	{		
		if(strs.empty()) 	return"";
		int right_most = strs[0].size() - 1; //��ͬ������󳤶�  ��ʼֵ����һ���ַ����ĳ���

		for(size_t i=1; i<strs.size(); i++)// �ַ���������
			for(int j=0; j<=right_most; j++) 
				if(strs[i][j] != strs[0][j]){
					 right_most = j-1;//���ϸ���  j����ͬ  right_mostȡj-1
					 break;//���Լ��ӵ�
				}
				return strs[0].substr(0,right_most+1);//right_mostΪ�±�  +1��Ϊ����
	}	 
};



int main()
{
	Solution2 s;
	 vector<string> v;
	 v.push_back("12345");  v.push_back("12356");  v.push_back("12367");  v.push_back("12378");
	 cout<<s.longestCommonPrefix(v)<<endl;
	 

	return 0;
}

