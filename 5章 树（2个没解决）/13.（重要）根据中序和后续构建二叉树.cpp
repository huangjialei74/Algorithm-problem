 
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

//在中序遍历序列中定位根的位置
int Locate(TElemType a[],TElemType ch,int n,int len)
{
	int i=n;
	while(i<n+len  && a[i]!= ch)
	{
		i++;
	}
	return i;
}
//已知中序后序，创建二叉树
void  Create(TreeNode* &T,TElemType In[],TElemType Pos[],int m,int n,int len)//m是根节点在数组Pos中的位置  n是根节点在数组in中从那里开始查找
{
	TElemType ch;
	int i,j;
	
	if(len >= 1 ) 
	{//cout<<Pos[m]; 
		ch=Pos[m];	
		T=new TreeNode;
		T->val=ch;	
		i=Locate(In ,ch, n, len);//找到 根节点在 中序数组 中的位置  ， n是开始查找的起始位置 ， len是查找的长度  该子树的所有节点数
		j=i-n;      //j是左子树的长度

		//由于后序遍历是 左右根 此处先构造右树
		Create(T->right, In, Pos, m-1,      i+1, len-j-1); 
		Create(T->left,  In, Pos, m-len+j ,  n , j); //m是根节点坐标 ，len是该子树的长度， j是该树的左子树长度   m-(len-j-1) +1 ， m应该减去右子树的长度
	}
	else
	{
		T=NULL;
	}
}
};

//	int a[8] = {8,3,2,4,1,6,5,7};
//	int b[8] = {8,3,4,2,6,7,5,1};
 

//创建二叉树
void CreateBiTree(TreeNode* &T)
{
	T=NULL; 
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
 
//	TreeNode* T ; 	 
//	cout<<"请输入二叉树的扩展先序序列：" ;				
//	CreateBiTree(T);//创建   //1 2 3 -1 -1 4 -1 -1 5 -1 -1
//	DisplayTree( T,0);

 //中序3 2 4 1 5
//后续3 4 2 5 1
	 
	int a[5] = {3,2, 4 ,1, 5};
	int b[5] = {3, 4 ,2 ,5, 1};
	Solution s;
	TreeNode* T2 ;
	s.Create(T2,a,b,4,0,5);
 
	DisplayTree( T2,0);
 

 	DestroyBiTree(T2);//销毁
	
 
	return 0;
}
  



