#include<iostream>
using namespace std;

#include<string>
//anagrams���Ĺ��ʣ� ����˳������γ��µĵ���

//�ص㣺���������ʰ���ĸ˳������� ��������� ������ͬһ��anagrams



class Solution
{
public:
	vector<string>anagrams(vector<string>&strs)
	{
		unordered_map< string, vector<string> >group;
		for(const auto&s:strs)//���ַ�������strs������ַ���  �����ϣ���У� key���������ַ���  ��ֵ���䲻ͬ˳���Ӧ�ĵ��ʣ������
		{
			string key=s;
			sort(key.begin(), key.end());//��ÿ����������  ������s���� 
			group[key].push_back(s);
		}
		vector<string>result;
		for(auto it=group.cbegin(); it!=group.cend(); it++)
		{
			if(it->second.size()>1)//һ���������ַ��� �䲻ͬ˳���ܱ�ʾ�ĵ�����������1��
				result.insert(result.end(), it->second.begin(), it->second.end());
		}
		return result;
	}
};




int main()
{
	 

	return 0;
}

