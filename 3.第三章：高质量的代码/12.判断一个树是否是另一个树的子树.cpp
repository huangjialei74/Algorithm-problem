 
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
 

bool Equal(double num1, double num2)
{
	if(num1-num2>-0.0000001 && num1-num2<0.0000001)//判断double或float类型是否相等需注意
		return true;
	else
		return false;
}

bool DoesTree1HaveTree2(TreeNode* T1,TreeNode* T2)
{
	if(T2==NULL) return true;//结束条件
	if(T1==NULL) return false;
//	if(!Equal(T1->val,T2->val)) return false;
	return DoesTree1HaveTree2(T1->left,T2->left) && DoesTree1HaveTree2(T1->right,T2->right);
}

bool hasSubTree(TreeNode* T1,TreeNode* T2)
{
	bool result=false;
	if(T1 != NULL && T2!=NULL)
	{
		if(Equal(T1->val,T2->val))//找到入口
			result=DoesTree1HaveTree2(T1,T2);
		if(!result)
			result=hasSubTree(T1->left,T2);
		if(!result)
			result=hasSubTree(T1->right,T2);
	}
	return result;
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

	TreeNode* T2 ; 	 
	cout<<"请输入二叉树的扩展先序序列：" ;				
	CreateBiTree(T2);//创建   //1 2 3 -1 -1 4 -1 -1 
 	DisplayTree( T2,0);

	if(hasSubTree(T1,T2))
		cout<<"你好啊"<<endl;
 

 	DestroyBiTree(T1);//销毁
	DestroyBiTree(T2);//销毁
 
	return 0;
}
  



