 
#include<iostream>
using namespace std; 
#include<vector>
#include<stack>



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



// O(n) O(n)
class Solution
{
public:
	vector<int>inorderTraversal(TreeNode* root)
	{
		vector<int>result;
		stack<const TreeNode*>s;
		const TreeNode*p=root;
		while(!s.empty()||p!=NULL)
		{
			if(p!=NULL)
			{
				s.push(p);
				p=p->left;
			}
			else//pΪ�վ�ȡջ�� 
			{
				p=s.top();
				s.pop();
				result.push_back(p->val);
				p=p->right;//ȡ������--��Ϊif���Ѿ����������������ˣ�   Ϊ��--��һ��ȡջ��Ԫ�أ����ڵ㣩��   ��Ϊ��--��һ����ջ�۲�
			}
		}
		return result;
	}
};



 /*
Morris���� O(n) O(1)
*/
class Solution2
{
public:
	vector<int>inorderTraversal(TreeNode* root)
	{
		vector<int>result;
		TreeNode*cur=root;//, *prev=NULL;
		while(cur!=NULL)
		{
			if(cur->left==NULL)
			{
				result.push_back(cur->val);
			//	prev=cur;
				cur=cur->right;
			}
			else{ 				
				TreeNode*node=cur->left;
				while(node->right!=NULL&&node->right!=cur)
					node=node->right;
				/*
				ǰ���������if�����cur  (�����������ҽ���ʱ��� ���ڵ��������)   
				���������else�����cur  (����������ʱ-��Ӹ��ڵ㣩)
				*/
				if(node->right==NULL)//û�������� �������� 
				{
					node->right=cur;
					cur=cur->left;
				}
				else{ //��߸�����  ������Ӹ��ڵ�  ��ָ��������
					//�Ѿ������� ����ʸ��ڵ� ��ɾ������					
					result.push_back(cur->val);
					node->right=NULL;
				   //prev=cur;
					cur=cur->right;
				}
			}
		}
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
 	vector<int>v = s.inorderTraversal(T);
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout<<(*it)<<" ";

	cout<<endl;


 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



