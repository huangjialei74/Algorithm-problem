 
 
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
	struct TreeNode *left, *right;
}; 
 
 

//镜像树
void MirrorRecursively(TreeNode* T)
{
	if(T==NULL)
		return ;
	if(T->left==NULL && T->right==NULL)
		return ;

	TreeNode* tmp=T->left;
	T->left=T->right;
	T->right=tmp;

	if(T->left)
		MirrorRecursively(T->left);
	if(T->right)
		MirrorRecursively(T->right);

}



//验证对称二叉树
bool isSymmetrical(TreeNode* T1,TreeNode* T2)
{
	if(T1==NULL && T2==NULL) return true;
	if(T1==NULL || T2==NULL) return false;
	if(T1->val!=T2->val)
		return false;
	return isSymmetrical(T1->left,T2->right)&& isSymmetrical(T1->right,T2->left);
}

bool isSymmetrical(TreeNode* T)
{
	return isSymmetrical(T,T);
}







//创建二叉树
void CreateBiTree(TreeNode* &T)
{
	T=NULL;//指针地址为空 
	TElemType ch;
		
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
 
	TreeNode* T1 ; 	 
	cout<<"请输入二叉树的扩展先序序列：" ;				
	CreateBiTree(T1);//创建   //1 2 3 -1 -1 4 -1 -1 5 -1 -1
 	DisplayTree( T1,0);

 

 	DestroyBiTree(T1);//销毁 
 
	return 0;
}
  



