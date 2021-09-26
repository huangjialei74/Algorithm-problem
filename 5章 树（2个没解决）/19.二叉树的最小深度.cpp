 
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
 

#define min(a, b) a<=b? a:b;

#define max(a, b) a>b? a:b;
 
//递归版 
class Solution
{
public: 
	int minDepth(  TreeNode*root)
	{	 
		return minDepth(root,false);
	}
private:
	 int minDepth( TreeNode*root, bool hasbrother)
	 {   
		if( root==NULL){			
			return  hasbrother ? INT_MAX:0;//根节点为空  且有兄弟时 此节点无意义返回INT_MAX ，不能root==NULL 就直接返回0，
		} 
		return 1 + min(minDepth(root->left,root->right!=NULL), minDepth(root->right,root->left!=NULL));
	 }
	  
};




//迭代版
// O(n)  O(logn)
class Solution2
{
public:
	int minDepth(TreeNode* root)
	{
		if(root==NULL)
			return 0;
		int result=INT_MAX; 
		stack< pair<TreeNode*,int> >s;	
		s.push(make_pair(root,1));

		while(!s.empty())//有点先序遍历
		{
			TreeNode* node=s.top().first;
			int depth=s.top().second;
			s.pop();
			if(node->left==NULL && node->right==NULL)//为叶子节点时  更新下result    result记录叶子节点的最小深度
				result=min(result, depth); 

			if(node->left!=NULL && result>depth)// 当前最小深度大于 该节点的深度时 才会继续遍历其子树
				s.push(make_pair(node->left, depth+1));//该节点与其深度

			if(node->right!=NULL && result>depth)
				s.push(make_pair(node->right, depth+1));//该节点与其深度
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

	Solution s;
	
	int len = s.minDepth(T) ;
 cout<<"结果"<<len<<endl; 

 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  



