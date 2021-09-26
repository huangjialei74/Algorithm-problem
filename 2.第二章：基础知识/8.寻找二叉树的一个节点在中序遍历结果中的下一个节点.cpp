 
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
	struct TreeNode *left, *right , *parent;
}; 
  
  
 TreeNode *GetNext(TreeNode *pNode)
 {
	 if(pNode==NULL)
	 {
		 return NULL;
	 }
	 TreeNode *pNext = NULL;
	 if(pNode->right != NULL)//����������  ��һ���ڵ���������������󴦵Ľڵ�
	 {
		 TreeNode*pRight = pNode->right;
		 while(pRight->left != NULL)
		 {
			 pRight = pRight->left;
		 }
		 pNext = pRight;
	 }
	 else if(pNode->parent != NULL)//�����������ڣ� 
	 {
		 TreeNode* pCurrent = pNode;
		 TreeNode* pParent = pNode->parent;
		 while(pParent != NULL && pCurrent == pParent->right)//pCurrentһֱΪpParentd �Һ���  �����������˳�ѭ��ʱ, pParent�Ѿ������Һ��ӵĽڵ���
		 {
			 pCurrent = pParent;
			 pParent = pParent->parent;
		 }
		 pNext = pParent;
	 }
	 return pNext;
 }
 







//����������
void CreateBiTree(TreeNode* &T, TreeNode* Parent)
{
	T=NULL; 
	TElemType ch;
		 
	cin>>ch;
 	   
	if(ch == -1)
	{
		T=NULL;
	}
	else 
	{ 
		T= new TreeNode;
		if(!T)
			exit(OVERFLOW); 
		T->val = ch;
		T->parent = Parent;

		CreateBiTree(T->left,T);
		CreateBiTree(T->right,T); 
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
	if(T->parent != NULL) cout<<T->parent->val;
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
	CreateBiTree(T,NULL);//����   //1 2 3 -1 -1 4 -1 -1 5 -1 -1
	DisplayTree( T,0);
    TreeNode* p = GetNext(T->left);
    cout<<p->val<<endl;
 


 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



