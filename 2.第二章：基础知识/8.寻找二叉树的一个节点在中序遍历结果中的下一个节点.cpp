 
#include<iostream>
using namespace std; 
#include<vector>
#include<stack>



#define OK 1
#define ERROR  0
#define OVERFLOW -2
 
//数据结构定义 
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
	 if(pNode->right != NULL)//右子树存在  下一个节点就是右子树的最左处的节点
	 {
		 TreeNode*pRight = pNode->right;
		 while(pRight->left != NULL)
		 {
			 pRight = pRight->left;
		 }
		 pNext = pRight;
	 }
	 else if(pNode->parent != NULL)//右子树不存在， 
	 {
		 TreeNode* pCurrent = pNode;
		 TreeNode* pParent = pNode->parent;
		 while(pParent != NULL && pCurrent == pParent->right)//pCurrent一直为pParentd 右孩子  不满足条件退出循环时, pParent已经是有右孩子的节点了
		 {
			 pCurrent = pParent;
			 pParent = pParent->parent;
		 }
		 pNext = pParent;
	 }
	 return pNext;
 }
 







//创建二叉树
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



//中序凹入显示
void DisplayTree(TreeNode* T,int i)//中序输出的顺序左中右
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


// 初始条件: 二叉树T存在。操作结果: 销毁二叉树T
void DestroyBiTree(TreeNode* &T)
{ 
	if(T) // 非空树
	{ 
		if(T->left) // 有左孩子
			DestroyBiTree(T->left); // 销毁左孩子子树
		if(T->right) // 有右孩子
			DestroyBiTree(T->right); // 销毁右孩子子树
		delete T; // 释放根结点
		T=NULL; // 空指针赋0
	} 
}//销毁二叉树的递归算法


//主函数
int main()
{
 
	TreeNode* T ; 	 
	cout<<"请输入二叉树的扩展先序序列：" ;				
	CreateBiTree(T,NULL);//创建   //1 2 3 -1 -1 4 -1 -1 5 -1 -1
	DisplayTree( T,0);
    TreeNode* p = GetNext(T->left);
    cout<<p->val<<endl;
 


 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  



