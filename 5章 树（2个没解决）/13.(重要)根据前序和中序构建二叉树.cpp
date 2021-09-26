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
//已知先序中序，创建二叉树
void  Create(TreeNode* &T,TElemType pre[],TElemType in[],int m,int n,int len)//m是根节点在数组pre中的位置  n是根节点在数组in中从那里开始查找
{
	TElemType ch;
	int i,j;
	if(!len)
	{
		T=NULL; 	 	
	}
	else
	{
		ch=pre[m];	
		T=new TreeNode;
		T->val=ch;	
		i=Locate(in,ch, n, len);//找到根ch在in中的位置   
		j=i-n;  //表示一棵左子树的长度
		//( 把中序遍历的数组  通过根节点 分割了)
		Create(T->left, pre, in, m+1, n, j);//根节点取pre[m+1] ,从n开始找   查找长度为j  
		
		Create(T->right, pre, in, m+j+1, i+1, len-j-1);//根节点取pre[m+j+1] ,从i+1开始找    查找长度为len -j-1  
	}
 
}




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
 
	TreeNode* T ; 	 
	cout<<"请输入二叉树的扩展先序序列：" ;				
	CreateBiTree(T);//创建   //1 2 3 -1 -1 4 -1 -1 5 -1 -1
	DisplayTree( T,0);

 


 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  



