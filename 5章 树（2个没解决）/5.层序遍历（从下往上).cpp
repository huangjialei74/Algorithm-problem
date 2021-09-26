 
#include<iostream>
using namespace std; 
#include<vector>
#include<stack>
#include <algorithm>


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
 
/*
例：
  3
  /\
  9 20
    /\
   15 7
   return [[15,7],[9,20],[3]]
*/

 
//递归 O(n) O(n)
class Solution
{
public:
	vector< vector<int> >levelOrderBottom(TreeNode*root)
	{
		vector< vector<int> >result;
		traverse(root, 1, result);
		reverse(result.begin(), result.end());//反转顺序
		return result;
	}
	void traverse(TreeNode* root, size_t level, vector< vector<int> >&result)
	{
		if(!root)
			return;
		if(level>result.size())
			result.push_back(vector<int>());
		result[level-1].push_back(root->val);
		traverse(root->left, level+1, result);
		traverse(root->right, level+1, result);
	}
};




#include<queue

//迭代O(n)  O(1)
class Solution2
{
public:
	vector< vector<int> >levelOrder(TreeNode* root)
	{
		vector< vector<int> >result;
		queue<TreeNode*>current, next; //队列
		if(root==NULL)
			return result;	
		else
			current.push(root);//只添加根节点
	
		while(!current.empty())
		{
			vector<int>level; 
			while(!current.empty())//循环
			{
				TreeNode*node=current.front();//从左到右获取
				current.pop();
				level.push_back(node->val);
				if(node->left != NULL)
					next.push(node->left);//左节点入next队列
				if(node->right != NULL)
					next.push(node->right);	//右节点入next队列
			}
			result.push_back(level);//添加该行
			swap(next,current);//    一生二  交换 ， 二生四 交换
		}

		reverse(result.begin(),result.end());//反转顺序
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
	vector< vector<int> >v = s.levelOrderBottom(T);
	for(vector< vector<int> >::iterator it = v.begin(); it != v.end(); it++)
	{
		for(vector<int>::iterator it2 =  it->begin(); it2 != it->end(); it2++)
		{
			cout<<(*it2)<<" ";
		}
		cout<<endl;  
	}


 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  



