 
#include<iostream>
using namespace std;

#define OK 1
#define ERROR  0
#define OVERFLOW -2
 
//数据结构定义 
typedef  char TElemType;  

struct TreeNode
{
	TElemType data;
	struct TreeNode *lchild, *rchild;
}; 
 



//创建二叉树
void CreateBiTree(TreeNode* &T)
{
	T=NULL;//指针地址为空 
	TElemType ch;
		
	scanf("%c",&ch);
	if(ch == ' ')	   
		T=NULL;
	else 
	{
		T=(TreeNode *)malloc(sizeof(TreeNode));//输入的不为空，指针T指向基地址
		if(!T)
			exit(OVERFLOW);//输入的为空，T指向空，动态内存申请失败，返回溢出
		T->data = ch;

		CreateBiTree(T->lchild);//第一次输入的数赋值给T->data，然后创建其左孩子，将第二个输入的数赋值给左孩子，再次利用创建函数		                         
		CreateBiTree(T->rchild);//再创建右孩子节点。。。。。，若输入的为空，那那个孩子节点就为空
	} 
} 



//中序凹入显示
void DisplayTree(TreeNode* T,int i)//中序输出的顺序左中右
{
	int j;
	if (T == NULL) return;
	if(T->lchild!=NULL)
		DisplayTree(T->lchild,i+1); 	
	for(j=1;j<=i;j++) 	
		cout<<"\t"; 
	cout<<"       "<<T->data;
	for(j=i+1;j<=8;j++)		
		cout<<"--------";
	cout<<endl;
	if(T->rchild!=NULL)
		DisplayTree(T->rchild,i+1);
} 


// 初始条件: 二叉树T存在。操作结果: 销毁二叉树T
void DestroyBiTree(TreeNode* &T)
{ 
	if(T) // 非空树
	{ 
		if(T->lchild) // 有左孩子
			DestroyBiTree(T->lchild); // 销毁左孩子子树
		if(T->rchild) // 有右孩子
			DestroyBiTree(T->rchild); // 销毁右孩子子树
		free(T); // 释放根结点
		T=NULL; // 空指针赋0
	} 
}//销毁二叉树的递归算法


//主函数
int main()
{
	TreeNode* T ; 	 
	printf("请输入二叉树的扩展先序序列：");				
	CreateBiTree(T);//创建			
		 

	DisplayTree( T,0);


 	DestroyBiTree(T);//销毁
	return 0;
}
  



