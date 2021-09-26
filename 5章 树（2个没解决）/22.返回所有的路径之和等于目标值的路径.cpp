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
	vector<vector<int> >pathSum(TreeNode*root,int sum)
	{
		vector<vector<int> >result;
		vector<int>cur;//中间结果
		pathSum(root, sum, cur, result);
		return result;
	}
private: void pathSum(TreeNode* root,int gap,vector<int>& cur, vector<vector<int> >&result)//cur必须是引用，不然返回的值没有进行修改
		 {
			 if(root==NULL)
				 return;
			 cur.push_back(root->val);
			 if(root->left==NULL && root->right==NULL && gap==root->val)//叶子节点 并且 符合要求
			 { 
				 result.push_back(cur);
			 }
			 //函数前面有判断空指针传入时的操作 此处不需判断左右子树是否为空
			 pathSum(root->left, gap-root->val, cur, result);// 递归中cur的值在变化
			 pathSum(root->right, gap-root->val, cur, result);
			 cur.pop_back();//一条路径到头时才会出栈 因此在最后
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
  



