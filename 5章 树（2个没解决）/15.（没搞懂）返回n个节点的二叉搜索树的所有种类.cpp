 
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
 




class Solution
{
public:
	vector<TreeNode*>generateTrees(int n)
	{
		if(n==0)
			return generate(1,0);
		return generate(1,n);
}
private:
	vector<TreeNode*>generate(int start,int end)
	{
		vector<TreeNode*>subTree;
		if(start>end)
		{
			 subTree.push_back(NULL);
			 return subTree;
		}
		for(int k=start; k<=end; k++)
		{
			vector<TreeNode*>leftSubs = generate(start, k-1);
			vector<TreeNode*>rightSubs = generate(k+1, end); 
			for(vector<TreeNode*>::iterator i  = leftSubs.begin(); i  != leftSubs.end();i ++)
			{
				for(vector<TreeNode*>::iterator j = rightSubs.begin(); j != rightSubs.end();j++)
				{
					TreeNode*node=new TreeNode; node->val = k;
					node->left=(*i);
					node->right=(*j);
					subTree.push_back(node);
				}
			}
		}
		return subTree;
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
 


 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



