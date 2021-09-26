#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>


//���ظ�����������
/*
ÿ��Ԫ�أ�����ѡ�� ѡ���߲�ѡ



//�ݹ�

�������취 ����O(2^n) O(n)
*/

// O(2^n)  O(n)

class Solution
{
public:
	vector< vector<int> > subsets(vector<int>&S)
	{
		sort(S.begin(),S.end());
		 vector< vector<int> >result;
		 vector<int>path;
		 subsets(S,path,0,result);
		 return result;
	}
private:
	static void subsets(const vector<int>&S, vector<int>&path, int step, vector< vector<int> >&result)
	{
		if(step==S.size())
		{//	for(vector<int>::iterator it = path.begin();it !=path.end();it++)
		//		cout<<(*it)<<"  ";	//	cout<<endl;
		
			result.push_back(path);
			return;
		}
		//��ѡS[step]
		 subsets(S, path, step+1, result); //û�����S[step]  --���������
		 //ѡS[step]
		 path.push_back(S[step]);//���S[step]
    
		subsets(S, path, step+1, result);//�����S[step]���������
	 	path.pop_back();//����
	}
	 
};

 



//��һ��λ����bool selected[n]ÿ��Ԫ�ؿ�ѡ�ɲ�ѡ
//O(2^n) O(n)
class Solution2
{
public:
	vector< vector<int> > subsets(vector<int>&S)
	{
		 sort(S.begin(),S.end());
		 vector< vector<int> >result;
		 vector<bool>selected(S.size(),false);
		 subsets(S ,selected, 0, result);
		 return result;
	}
private:
	static void subsets(const vector<int>&S, vector<bool>& selected, int step, vector< vector<int> >&result)
	{
		if(step==S.size())
		{
			vector<int>subset;
			for(int i=0; i<S.size(); i++)//��ͷ��  �Ͱ�Ϊtrue��ȫ�����
			{
				if(selected[i])
					subset.push_back(S[i]);
			}
			result.push_back(subset);//���subset
			return;
		}
		//��ѡS[step]
		selected[step]=false;
		subsets(S,selected,step+1,result);    //ÿ�ζ���������� ѡ�����  ��ѡ���
		//ѡS[step]
		 selected[step]=true;
		 subsets(S,selected,step+1,result);		 		 
	}
};


 
int main()
{
	 vector<int>v;
	 v.push_back(1);  v.push_back(2);  v.push_back(3);  

	 Solution s;
	 vector< vector<int> > V = s.subsets(v);

cout<<"-----------------------------------"<<endl;
	 for(vector< vector<int> >::iterator it0 = V.begin(); it0 != V.end();it0++)
	 {
	 	for(vector<int>::iterator it = (*it0).begin();it !=(*it0).end();it++)
				cout<<(*it)<<"  ";
			cout<<endl;
	 }
	return 0;
}

