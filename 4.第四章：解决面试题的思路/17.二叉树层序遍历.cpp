 
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
 


/*
例：
  3
  /\
  9 20
    /\
   15 7
   return [[3],[9,20],[15,7]]
*/



//递归 O(n) O(n)
class Solution
{
public:
	vector< vector<int> >levelOrder(TreeNode*root)
	{
		vector< vector<int> >result;
		traverse(root, 1, result);
		return result;
	}
	void traverse(TreeNode*root, size_t level, vector< vector<int> >&result)//level为层数
	{
		if(!root)  
			return;
		if(level > result.size())//每一层所有节点的level 一样大
			result.push_back(vector<int>());  
		result[level-1].push_back(root->val);
	
		traverse(root->left, level+1, result);//每次增加一个值   再增加右节点的值  这样不会把左子树全部加进去
	    traverse(root->right, level+1, result);
	}
	 
};



#include<queue>
#include<deque>
//迭代O(n)  O(1)
class Solution2
{
public:
	vector< vector<int> >levelOrder(TreeNode* root)
	{
		vector< vector<int> >result;
		queue<TreeNode*>current, next; //队列
		if(root==NULL){
			return result;
		}
		else{
			current.push(root);//只添加根节点
		}
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
			swap(next,current);//交换  --1变2 2变4 4变8   doge
		}
		return result;
	}


	//剑指offer上的迭代  不换行 
	vector<int> levelOrder2(TreeNode* root)
	{
		vector<int>result;
		if(!root) return result;
		deque<TreeNode*>deq;
		deq.push_back(root);
		 
		while(!deq.empty())
		{
			TreeNode* p=deq.front();
			deq.pop_front();
			result.push_back(p->val );
			if(p->left) deq.push_back(p->left);
			if(p->right) deq.push_back(p->right);
		}
		return result;

	}
	//换行
	vector< vector<int> >levelOrder3(TreeNode* root)
	{
		vector< vector<int> >result;
		queue<TreeNode*>que; //队列
		if(root==NULL)
			return result;
		que.push(root); 
		
		int  nextLevel=0, toBeAdd=1;//当前行数， 下一行要添加的节点数  当前行还有多少没添加
		vector<int>v;//保存每一行节点值
		while(!que.empty())
		{
			TreeNode* pNode=que.front();
			que.pop();
		 
			v.push_back(pNode->val);
			--toBeAdd;//没添加的节点数减少一个

			if(pNode->left!=NULL)
			{
				que.push(pNode->left);
				++nextLevel;				
			}
			if(pNode->right!=NULL)
			{
				que.push(pNode->right);
				++nextLevel;
			}
			if(toBeAdd==0) //还没有添加的数量 为0时  去下一行添加
			{
				result.push_back(v);
				v.clear(); //清空上一层保存的节点值
				toBeAdd=nextLevel;//赋值下一层需要添加的节点数量
				nextLevel=0;//清零
			}		 
		}
		return result;
	}


	//之字型遍历  不用逆序函数
	vector< vector<int> >levelOrder4(TreeNode* root)
	{
		vector< vector<int> >result;
		if(root==NULL) 
			return result;

		stack<TreeNode*>level[2];//一个存储当前  一个存储下一行
		int current=0,  next=1;
		level[current].push(root);
		while(!level[current].empty() || !level[current].empty())
		{
			TreeNode* pNode;
			vector<int>v;
			while(!level[current].empty())
			{			
				pNode=level[current].top();
				level[current].pop();
                v.push_back(pNode->val);//添加这个栈的节点时 把子节点保存在另一个栈里面 添加完毕时  交换两个栈
				if(current==0)//从左至右 则先左树
				{
				    if(pNode->left!=NULL)  level[next].push(pNode->left);
				    if(pNode->right!=NULL) level[next].push(pNode->right);
				}
				if(current==1)//从右至左 则先右树
				{
				    if(pNode->right!=NULL) level[next].push(pNode->right);
				    if(pNode->left!=NULL)  level[next].push(pNode->left);
				}
			}
			result.push_back(v);
			current=1-current;//交换两个栈
			next=1-next;
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
	CreateBiTree(T);//创建   //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
	DisplayTree( T,0);


	Solution2 s ;
	vector< vector<int> >v = s.levelOrder4(T);
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
  



