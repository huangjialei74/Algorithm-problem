 
#include<iostream>
using namespace std; 
#include<vector>
#include<stack>
#include <algorithm>


#define OK 1
#define ERROR  0
#define OVERFLOW -2
 
//���ݽṹ���� 
typedef  int TElemType;  

struct TreeNode
{
	TElemType val;
	struct TreeNode *left, *right;
}; 
 
/*
����
  3
  /\
  9 20
    /\
   15 7
   return [[15,7],[9,20],[3]]
*/

 
//�ݹ� O(n) O(n)
class Solution
{
public:
	vector< vector<int> >levelOrderBottom(TreeNode*root)
	{
		vector< vector<int> >result;
		traverse(root, 1, result);
		reverse(result.begin(), result.end());//��ת˳��
		return result;
	}
	void traverse(TreeNode* root, size_t level, vector< vector<int> >&result)
	{
		if(!root)
			return;
		if(level>result.size())
			result.push_back(vector<int>());
		result[level-1].push_back(root->val);
		traverse(root->left, level+1, result);
		traverse(root->right, level+1, result);
	}
};




#include<queue

//����O(n)  O(1)
class Solution2
{
public:
	vector< vector<int> >levelOrder(TreeNode* root)
	{
		vector< vector<int> >result;
		queue<TreeNode*>current, next; //����
		if(root==NULL)
			return result;	
		else
			current.push(root);//ֻ��Ӹ��ڵ�
	
		while(!current.empty())
		{
			vector<int>level; 
			while(!current.empty())//ѭ��
			{
				TreeNode*node=current.front();//�����һ�ȡ
				current.pop();
				level.push_back(node->val);
				if(node->left != NULL)
					next.push(node->left);//��ڵ���next����
				if(node->right != NULL)
					next.push(node->right);	//�ҽڵ���next����
			}
			result.push_back(level);//��Ӹ���
			swap(next,current);//    һ����  ���� �� ������ ����
		}

		reverse(result.begin(),result.end());//��ת˳��
		return result;
	}
};
 

//����������
void CreateBiTree(TreeNode* &T)
{
	T=NULL;//ָ���ַΪ�� 
	TElemType ch;
		
//	scanf("%c",&ch); 
	cin>>ch;
 	   
	if(ch == -1)
		T=NULL;
	else 
	{ 
		T= new TreeNode;
		if(!T)
			exit(OVERFLOW); 
		T->val = ch;

		CreateBiTree(T->left);
		CreateBiTree(T->right); 
	} 
} 



//��������ʾ
void DisplayTree(TreeNode* T,int i)//���������˳��������
{
	int j;
	if (T == NULL) return;
	if(T->left!=NULL)
		DisplayTree(T->left,i+1); 	
	for(j=1;j<=i;j++) 	
		cout<<"\t"; 
	cout<<"       "<<T->val;
	for(j=i+1;j<=8;j++)		
		cout<<"--------";
	cout<<endl;
	if(T->right!=NULL)
		DisplayTree(T->right,i+1);
} 


// ��ʼ����: ������T���ڡ��������: ���ٶ�����T
void DestroyBiTree(TreeNode* &T)
{ 
	if(T) // �ǿ���
	{ 
		if(T->left) // ������
			DestroyBiTree(T->left); // ������������
		if(T->right) // ���Һ���
			DestroyBiTree(T->right); // �����Һ�������
		delete T; // �ͷŸ����
		T=NULL; // ��ָ�븳0
	} 
}//���ٶ������ĵݹ��㷨


//������
int main()
{
 
	TreeNode* T ; 	 
	cout<<"���������������չ�������У�" ;				
	CreateBiTree(T);//����   //1 2 3 -1 -1 4 -1 -1 5 -1 -1
	DisplayTree( T,0);


	Solution s ;
	vector< vector<int> >v = s.levelOrderBottom(T);
	for(vector< vector<int> >::iterator it = v.begin(); it != v.end(); it++)
	{
		for(vector<int>::iterator it2 =  it->begin(); it2 != it->end(); it2++)
		{
			cout<<(*it2)<<" ";
		}
		cout<<endl;  
	}


 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



