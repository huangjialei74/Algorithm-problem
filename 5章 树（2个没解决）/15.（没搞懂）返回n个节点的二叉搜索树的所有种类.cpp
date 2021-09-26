 
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
  



