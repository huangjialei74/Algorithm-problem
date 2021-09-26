 
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
	struct TreeNode *left, *right ,*next;
}; 
 
/*
      1
	  /\
	 2  3
	/\   \
   4  5   7

      1->NULL
      /\
	 2->3->NULL
	/\   \
   4->5->7->NULL
*/


 //类似层序遍历
 // O(n) O(1)
class Solution
{
public:
	void connect(TreeNode*  &root)
	{
		if(root==NULL) 	return; 
	 	TreeNode* dummy = new TreeNode();    dummy->val = -1;//下一层的头结点

		TreeNode* curr=root, *prev=  dummy;
		for(  ; curr ; curr = curr->next)
		{	
			if(curr->left!=NULL)
			{  
				prev->next=curr->left;  //有子树就赋值给它的prev的next   
				prev=prev->next; 
			}
			if(curr->right!=NULL) 
			{  
				 prev->next=curr->right;
				 prev=prev->next;
			}
		} 
	 	prev->next=NULL;//该层最后一个节点的next为NULL
	 	connect(dummy->next);
	}
};

 
// O(n) O(1)
class Solution2
{
public:
	void connect(TreeNode* root)
	{
		while(root)
		{
			 
			TreeNode* next=NULL; 
			TreeNode*prev=NULL;
			for( ; root; root=root->next)
			{
				if(!next)
					next = root->left? root->left: root->right; //下一行 或许仍为NULL
				if(root->left)
				{
					if(prev)//有前驱就连在前驱后面
						prev->next=root->left;
					prev=root->left;  //有或者没有 都赋值为前驱
				}
			if(root->right)
				{
					if(prev)
						prev->next=root->right;  
					prev=root->right;
				}
			}
			root=next; //root会遍历每一行  只不过最后一行时if(root->left)  if(root->left)都不进行操作
		}
	}
};


// O(n) O(logn) 来自5.4.6  传入了sibling 如果存在就设为该节点的next
class Solution3
{
public:
	void connect(TreeNode* root)
	{
		connect(root,NULL);
	}
private:
	void connect(TreeNode* root,TreeNode* sibling)
	{
		if(root==NULL)
			return;
		else
			root->next=sibling;
		connect(root->left,root->right);
		if(sibling) //深入地 把sibling设为右子树的next
			connect(root->right, sibling->left);
		else
			connect(root->right,NULL);
	}
};


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
		T->next = NULL;
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

  if(T->next!= NULL)  
  	cout<<T->next->val ; 

    if(T->next== NULL)  
  	cout<<"哈哈" ; 


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
	CreateBiTree(T);//创建   //1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
 //	DisplayTree( T,0);

	Solution s;
	s.connect(T);
	cout<<"-----------------------------"<<endl;
	DisplayTree( T,0);

 

 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  



