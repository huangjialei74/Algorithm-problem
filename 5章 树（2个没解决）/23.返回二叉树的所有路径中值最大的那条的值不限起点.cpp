 
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
 

int max(int a,int b)
{
	return a>b?a:b;
} 
/*
    1
   /\
  2  3
 Return 6
*/
 // O(n)   O(logn)
class Solution
{
public: 
	int maxPathSum(TreeNode* root)
	{
		max_sum=INT_MIN;
		dfs(root);
		return max_sum;
	}
private:
	int max_sum;
	int dfs(const TreeNode*root)
	{
		if(root==NULL)
			return 0;
		int l=dfs(root->left);
		int r=dfs(root->right);

		 int sum=root->val;
		 if(l>0)
			 sum+=l;
		 if(r>0)
			 sum+=r;
		 max_sum = max(max_sum, sum);//用一个完整路径去更新max_sum 

	 	 return max(r,l)>0 ? max(r,l)+root->val:  root->val;//某根节点到其叶子节点的最大路径 (但不是完整路径)
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
  



