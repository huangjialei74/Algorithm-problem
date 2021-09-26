 
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



// O(n) O(n)
class Solution
{
public:
	vector<int>inorderTraversal(TreeNode* root)
	{
		vector<int>result;
		stack<const TreeNode*>s;
		const TreeNode*p=root;
		while(!s.empty()||p!=NULL)
		{
			if(p!=NULL)
			{
				s.push(p);
				p=p->left;
			}
			else//p为空就取栈顶 
			{
				p=s.top();
				s.pop();
				result.push_back(p->val);
				p=p->right;//取右子树--因为if中已经把左子树遍历完了，   为空--下一步取栈顶元素（根节点），   不为空--下一步入栈观察
			}
		}
		return result;
	}
};



 /*
Morris遍历 O(n) O(1)
*/
class Solution2
{
public:
	vector<int>inorderTraversal(TreeNode* root)
	{
		vector<int>result;
		TreeNode*cur=root;//, *prev=NULL;
		while(cur!=NULL)
		{
			if(cur->left==NULL)
			{
				result.push_back(cur->val);
			//	prev=cur;
				cur=cur->right;
			}
			else{ 				
				TreeNode*node=cur->left;
				while(node->right!=NULL&&node->right!=cur)
					node=node->right;
				/*
				前序遍历的在if中添加cur  (左子树的最右结束时添加 根节点的右子树)   
				中序遍历在else中添加cur  (左子树结束时-添加根节点）)
				*/
				if(node->right==NULL)//没有线索化 建立线索 
				{
					node->right=cur;
					cur=cur->left;
				}
				else{ //左边搞完了  现在添加根节点  并指向右子树
					//已经线索化 则访问根节点 并删除线索					
					result.push_back(cur->val);
					node->right=NULL;
				   //prev=cur;
					cur=cur->right;
				}
			}
		}
		return result;
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


	Solution s ;
 	vector<int>v = s.inorderTraversal(T);
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout<<(*it)<<" ";

	cout<<endl;


 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  



