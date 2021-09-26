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
 



// Symmetric Tree

//递归
// O(n) O(logn)
class Solution
{
public:
	bool isSymmetric(TreeNode* root)
	{
		if(root==NULL)
			return true;
		return isSymmetric(root->left, root->right);
	}
	bool isSymmetric(TreeNode* p, TreeNode* q)
	{
		if(p==NULL && q==NULL)//终止条件
			return true;
		 if(p==NULL || q==NULL)//不对称
			 return false;
		  return p->val==q->val //三方合并
			  &&isSymmetric(p->left,q->right) 
			  &&isSymmetric(p->right,q->left);
	}
};




//迭代O(n)  O(logn)
class Solution2
{
public:
	bool isSymmetric(TreeNode* root)
	{
		if(!root)
			return true;
		stack<TreeNode*>s;
		s.push(root->left);
		s.push(root->right);
		while(!s.empty())
		{
			TreeNode*  p=s.top();
			s.pop();
			TreeNode*  q=s.top();
			s.pop();
			if(!p && !q)//每次只比较栈顶两个元素
				continue;
			if(!p||!q)
				return false;
			if(p->val != q->val)
				return false;
			s.push(p->left);//左与右  下一循环中进行比较  p q顺序无所谓
			s.push(q->right);
			s.push(p->right);
			s.push(q->left);
		}
		return true;
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
	Solution2 s;
	if(s.isSymmetric(T))
		cout<<"yes "<<endl;

 


 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  



