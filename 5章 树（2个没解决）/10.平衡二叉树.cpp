 
#include<iostream>
using namespace std; 
#include<vector>
#include<stack>

#define max(a,b) a>b?a:b;

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
 


//它是一 棵空树或它的左右两个子树的高度差的绝对值不超过1
// O(n) O(logn)
class Solution
{
public:
	bool isBalanced(TreeNode* root)
	{
		return balancedHeight(root) >=0;
	}
	 int balancedHeight(TreeNode* root)
	 {
		 if(root==NULL)
			 return 0; 
		 int left = balancedHeight(root->left);
		 int right = balancedHeight(root->right);
		 if(left<0 || right<0 || abs(left-right)>1)//剪枝   两子树都为平衡二叉树  且 两树高度差不大于1
			 return -1;   
		  return max(left,right)+1;//三方合并
	 }	  
};










//创建二叉树
void CreateBiTree(TreeNode* &T)
{
	T=NULL;//指针地址为空 
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
 
	TreeNode* T ; 	 
	cout<<"请输入二叉树的扩展先序序列：" ;				
	CreateBiTree(T);//创建   //1 2 3 -1 -1 4 -1 -1 5 -1 -1
	DisplayTree( T,0);

 


 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  



