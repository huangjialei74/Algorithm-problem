#include<iostream>
using namespace std;





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



//实现两个函数  分别用来序列化二叉树和反序列化二叉树


void Serialize(TreeNode* pRoot, ostream& stream)
{
	if(pRoot==NULL)
	{
		stream<<"$";
		return ;
	}
	stream<<pRoot->val<<',';
	Serialize(pRoot->left,stream);
	Serialize(pRoot->right,stream);
}
void Deserialize(TreeNode** pRoot, istream& stream)
{
	int number;
	if(ReadStream(stream, &number))//ReadStream懒得管
	{
		*pRoot=new TreeNode();
		(*pRoot)->val=number;
		(*pRoot)->left=NULL;
		(*pRoot)->right=NULL;
		Deserialize(&(*pRoot)->left, stream);
		Deserialize(&(*pRoot)->right, stream);
	}
}











int main()
{
	 

	return 0;
}

