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
	TElemType data;
	struct TreeNode *lchild, *rchild;
}; 
 

//前序  根左右

//栈O(n) o(n)
class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int>result;
		stack<const TreeNode*>s;
		if(root!=NULL) 
			s.push(root);
		while(!s.empty())//栈不为空  里面的节点的值全部添加到了result里面 就可以返回了
		{
			const TreeNode*p=s.top();
			s.pop();     
			result.push_back(p->data);//添加根节点 进vector容器
			if(p->rchild != NULL) 
				s.push(p->rchild);// 右子树入栈
			if(p->lchild != NULL)
				s.push(p->lchild);// 左子树入栈            入栈顺序 先右后左 在出栈时可以保证 先序
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
	vector<int>preorderTraversal(TreeNode*root)
	{
		vector<int>result;
		TreeNode *cur=root;//, *prev=NULL; //好像没用到prev 可以删去
		while(cur!=NULL)
		{
			if(cur->lchild==NULL)
			{
				result.push_back(cur->data);
			//	prev=cur;
				cur=cur->rchild;
			}
			else
			{
				TreeNode *node=cur->lchild;//查找后继
				while(node->rchild != NULL && node->rchild !=cur)
					node=node->rchild;//找到左子树的最右边
				/*
				前序遍历的在if中添加cur  (左子树的最右结束时添加 根节点的右子树)   
				中序遍历在else中添加cur  (左子树结束时-添加根节点）)
				*/
				if(node->rchild==NULL) 
				{
					 result.push_back(cur->data);					 
					 node->rchild=cur;//把cur连接在右子树 形成环----cur遍历完左边时 可以跳到根节点 到达右子树
					// prev=cur;   
					 cur=cur->lchild;//cur指向其左子树-- 即开始时的noede
				}
				else //最右子树等于根节点
				{
					node->rchild=NULL;//断掉  因为左边已经遍历完了
					cur=cur->rchild ;//根节点的右树
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
		T->data = ch;

		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild); 
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
	cout<<"请输入二叉树的扩展先序序列："<<endl;				
	CreateBiTree(T);//创建     1 2 3 -1 -1 4 -1 -1 5 -1 -1
	DisplayTree( T,0);


	Solution2 s ;
	vector<int>v = s.preorderTraversal(T);
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout<<(*it)<<" ";

	cout<<endl;


 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  



