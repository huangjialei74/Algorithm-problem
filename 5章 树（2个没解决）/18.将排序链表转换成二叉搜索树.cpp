 
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
  

struct ListNode
	{
	int val;
	struct ListNode *next;
};    



//分治法 自顶向下

// O(n^2) O(logn)
class Solution
{
public:
	TreeNode*sortedListToBST(ListNode* head)
	{
		return sortedListToBST(head, listLength(head));
	}
	TreeNode*sortedListToBST(ListNode*head,int len)
	{
		if(len==0)
			return NULL;
		if(len==1)
		{
			TreeNode* retu; retu->val = head->val;
			return retu;
		} 
		TreeNode*root=new TreeNode ;    root->val = nth_node(head, len/2+1)->val;//链表中间节点的值 作根节点
		root->left = sortedListToBST(head, len/2);//左子树的最左下角是头结点
		root->right = sortedListToBST(nth_node(head, len/2+2), (len-1)/2);//右子树的最左下角是 链表中间节点的下一个
		return root;
	}
	int listLength(ListNode* node)//求链表长度
	{
		int n=0;
		while(node)
		{
			++n;
			node=node->next;
		}
		return n;
	}
	ListNode* nth_node(ListNode*node, int n)//返回链表第n 个节点 
	{
		while(--n)
			node=node->next;
		return node;
	}
};


 //自下而上O(n) O(logn)
class Solution2
{
public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		int len=0;
		ListNode*p=head;
		while(p)
		{
			len++;
			p=p->next;
		}//到达最后一个节点的NULL
		return sortedListToBST(head, 0, len-1);
	}
private:
	TreeNode* sortedListToBST(ListNode* &list, int start, int end)
	{
		if(start>end)
			return NULL;
		int mid = start+(end-start)/2;
		TreeNode* leftChild = sortedListToBST(list, start, mid-1);// 这棵左子树 会递归地把链表左边全部消耗掉

		TreeNode* parent = new TreeNode; //根节点
		parent->val = list->val ;  
		parent->left = leftChild;   

		list = list->next;//右子树
		parent->right = sortedListToBST(list, mid+1, end);
		return parent;
	}
};




void creat(	ListNode* &L)
{	
	 L=new ListNode;  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	 ListNode* p;//定义一个节点p 
	for( int i=10-1;i>=0;i--)
	{ 
		p=(ListNode*)malloc(sizeof(ListNode));
		p->val = a[i];
		p->next=L->next; 
		L->next=p; //每一次循环插入一个节点
	}
}



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
	ListNode* L;
	creat(L);

    Solution2 s;
	 TreeNode* T = s.sortedListToBST(L->next);  
 

	 DisplayTree( T,0);


 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  


 