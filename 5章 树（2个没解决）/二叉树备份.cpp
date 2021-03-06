//2.熟练掌握二叉链表的存储结构
//预编译命令
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR  0
#define OVERFLOW -2
 
//数据结构定义
typedef  int  Status;  
typedef  char TElemType;  

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;//让BiTnode拥有struct BiTnode *P中的“struct BiTnode* ”的功能


//函数声明
int menu_select();
Status InitBiTree(BiTree &T);//初始化函数定义
Status CreateBiTree(BiTree &T);//创建函数，先序输入时，先根结点，再左子树，再右子树

void PreOrderTraverse(BiTree T,Status(*Visit)(TElemType));//先序遍历输出
void InOrderTraverse(BiTree T,Status(*Visit)(TElemType));//中序遍历输出
void PostOrderTraverse(BiTree T,Status(*Visit)(TElemType));//后序遍历输出
Status PrintElem(TElemType e);//打印
void DisplayTree(BiTree T,int i);//中序凹入显示
int Leaf(BiTree T);//求叶子树
int Depth (BiTree T);//求深度
Status Preorder (BiTree T, TElemType x, BiTree &p);//查询
void DestroyBiTree(BiTree &T);//销毁

//主函数
int main()
{
	BiTree T,p;//定义两个指针T，P
	Status s;
	int n0,h;
	TElemType e;//元素e
	for(;;)
	{
		switch(menu_select())
		{
		case 1:
			s=InitBiTree(T);
			if(s)
				printf("初始化成功\n");
			else
				printf("初始化失败\n");
			break;
		case 2:
			getchar();
			printf("请输入二叉树的扩展先序序列：");			
			s=CreateBiTree(T);			
			if(s)
				printf("创建成功\n");
			else
				printf("创建失败\n");
			break;
		case 3:
			printf("先序遍历序列为：\n");
			PreOrderTraverse(T,PrintElem);			
			break;
		case 4:
			printf("中序遍历序列为：\n");
			InOrderTraverse(T,PrintElem);
			break;
		case 5:
			printf("后序遍历序列为：\n");
			PostOrderTraverse(T,PrintElem);
			break;
		case 6:printf("凹入显示\n");
			DisplayTree(T,0);
			break;
		case 7:
			n0=Leaf(T);
			printf("叶子结点个数为%d\n",n0);
			break;
		case 8:
			h=Depth(T);
			printf("二叉树深度为%d\n",h);
			break;
		case 9:
			printf("请输入要查找的元素的值：");
			getchar();
			scanf("%c",&e);
			s=Preorder (T, e, p) ;
			if(s)
				printf("查找到元素%c\n",p->data);
			else
				printf("未找到\n");			
			break;
		case 10:
			DestroyBiTree(T);
			printf("二叉树已销毁\n");	
			break;
		case 0:
			printf("程序结束，谢谢使用！\n\n"); 
			exit(0);
		}
	}
	return 0;
}
//菜单函数
int menu_select()
{
	int sn;
	printf("\n显示菜单\n");
	printf("1.初始化一个空树（空树）\n");
	printf("2.用扩展的先序序列的方式创建二叉树\n");
	printf("3.输出先序遍历序列\n");
	printf("4.输出中序遍历序列\n");	
	printf("5.输出后序遍历序列\n");
	printf("6.凹入显示二叉树（中序）\n");	
	printf("7.求二叉树的叶结点的个数查找\n");
	printf("8.求二叉树的深度查找\n");	
	printf("9.查找二叉树中的某个给定值\n");
	printf("10.销毁二叉树\n");
	printf("0.退出\n");
	printf("输入 0-10:");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>10)
			printf("\n输入错误，重选0－10：");
		else
			break;
	}
	return sn;
}
//初始化函数定义
Status InitBiTree(BiTree &T)
{
	T=NULL;//指针地址为空
	return OK;
}
//创建二叉树
Status CreateBiTree(BiTree &T)
{
	TElemType ch;
	scanf("%c",&ch);
	if(ch == ' ')	   
		T=NULL;
	else 
	{
		T=(BiTNode *)malloc(sizeof(BiTNode));//输入的不为空，指针T指向基地址
		if(!T)
			exit(OVERFLOW);//输入的为空，T指向空，动态内存申请失败，返回溢出
		T->data = ch;

		CreateBiTree(T->lchild);//第一次输入的数赋值给T->data，然后创建其左孩子，将第二个输入的数赋值给左孩子，再次利用创建函数		                         
		CreateBiTree(T->rchild);//再创建右孩子节点。。。。。，若输入的为空，那那个孩子节点就为空
	}
	return OK;
}
//先序遍历
void PreOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	if(T)
	{
		Visit(T->data);  
		PreOrderTraverse(T->lchild,Visit);     
		PreOrderTraverse(T->rchild,Visit); 
	} 
}
//中序遍历
void InOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	if(T)
	{		
		InOrderTraverse(T->lchild,Visit);
		Visit(T->data); // 中间访问根结点    
		InOrderTraverse(T->rchild,Visit); 
	} 
}
//后序遍历
void PostOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	if(T)
	{		
		PostOrderTraverse(T->lchild,Visit);     
		PostOrderTraverse(T->rchild,Visit); 
		Visit(T->data); // 后访问根结点
	} 
}
//打印一个数据元素函数
Status PrintElem(TElemType e)
{
	printf("%c\t",e);
	return OK;
}
//中序凹入显示
void DisplayTree(BiTree T,int i)//中序输出的顺序左中右
{
	int j;
	if (T == NULL) return;
	if(T->lchild!=NULL)
		DisplayTree(T->lchild,i+1); 	
	for(j=1;j<=i;j++) 	
		printf("\t");
	printf("       %c",T->data);
	for(j=i+1;j<=8;j++)		
		printf("--------");
	printf("\n");
	if(T->rchild!=NULL)
		DisplayTree(T->rchild,i+1);
}
//求叶子数
int Leaf(BiTree T)
{ 
	if(T)
	{
		if ((T->lchild==NULL)&&(T->rchild==NULL))
			return 1;
		else 
			return Leaf(T->lchild)+Leaf(T->rchild);//存在即为1，递归思想
	}
	else return 0;
}
//求二叉树的深度
int Depth (BiTree T)
{ 
	int depthval,depthLeft,depthRight;
	if ( !T )   depthval = 0;
	else   
	{
		depthLeft = Depth( T->lchild );
		depthRight= Depth( T->rchild );
		depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);//左边大就结果为左，递归思想
	} 
	return depthval;
}
// 若二叉树中存在和 x 相同的元素，则 p 指
// 向该结点并返回 OK,否则返回 FALSE  
Status Preorder (BiTree T, TElemType x, BiTree &p) 
{	
	if (T) 
	{
		if (T->data==x)
		{
			p = T; return OK;
		} 
		else 
		{
			if (Preorder(T->lchild, x, p)) return OK;
			else return(Preorder(T->rchild, x, p)) ;
		}//else
	}//if(T) 
    else return ERROR;
}
// 初始条件: 二叉树T存在。操作结果: 销毁二叉树T
void DestroyBiTree(BiTree &T)
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
