 
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
 

/*O(n)的解法 开依次i一个指针数组 中序遍历 将节点指针存放到数组里，然后寻找两处逆向的位置
从前往后找第一个逆序的位置 从后往前找第二个逆序的位置  交换指针的值
 使用 Morris中序遍历
*/

class Solution
{
public:
	void recoverTree(TreeNode* root)
	{
		pair<TreeNode*, TreeNode*>broken;
		TreeNode* prev=NULL;
		TreeNode* cur=root;
		while(cur!=NULL)
		{
			if(cur->left==NULL)
			{
				detect(broken, prev, cur);
				//中序遍历  返回vector题中  result.push_back()换成了此处的detect() 能遍历到每一个节点  
				prev=cur;
				cur=cur->right;
			}
			else
			{
			   TreeNode* node=cur->left;
				while(node->right!= NULL && node->right !=cur)
					node=node->right;
				if(node->right==NULL)
				{
					node->right=cur; 
					cur=cur->left;
				}
				else
				{
					detect(broken,prev,cur);//到了右树
					node->right=NULL;
					prev=cur;
					cur=cur->right;
				}
			}
		}
		swap(broken.first->val, broken.second->val);
	}
	void detect(pair<TreeNode*,TreeNode*>&broken, TreeNode* prev, TreeNode*current)
		//遍历到了每一个节点，first获取第一个不满足顺序的节点 ，之后不发生改变， 
		//只要传入的prev大于current  second就改变   即第二个不满足顺序的点
	{
		if(prev!=NULL && prev->val > current->val)
		{
			if(broken.first==NULL)//之前为空就添加，   不为空就不更新
			{
				broken.first=prev;
			}
            broken.second=current;//第二位必更新
		}
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
	s.recoverTree(T);
	DisplayTree( T,0);


	cout<<endl;


 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  



