 
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
	vector< vector<int> >zigzagLevelOrder(TreeNode*root)
	{
		vector<vector<int> >result;
		traverse(root,1,result,true);
		return result;
	}
	void traverse(TreeNode* root, size_t level, vector< vector<int> >&result, bool left_to_right)//bool true代表从左往右， 结束时反转一下 
	{
		if(!root)
			return;
		if(level > result.size())
			result.push_back(vector<int>());

	 	if(left_to_right)//true代表从左往右   放到vector容器尾部
			result[level-1].push_back(root->val);
		else             //false代表从右往左//插入vector容器头部
			result[level-1].insert(result[level-1].begin(), root->val);
/*不知道这里为什么不能reverse
		result[level-1].push_back(root->val);
		if(!left_to_right)
			 reverse(result[level-1].begin(),result[level-1].end());
*/

		traverse(root->left,  level+1, result, !left_to_right);//此时左右子树  的left_to_right一样   都与根节点相反
		traverse(root->right, level+1, result, !left_to_right);
	}
};


#include<queue>

// O(n)  O(n)
class Solution2
{
public:
	vector< vector<int> >zigzagLevelOrder(TreeNode*root)
	{
		vector< vector<int> >result;
		queue<TreeNode*>current, next;	
		if(root==NULL){
			return result;	
		else
			current.push(root);

    	bool left_to_right=true;//是否反转
		while(!current.empty())
		{
			 vector<int>level;
			 while(!current.empty())
			 {
				 TreeNode*node=current.front();
				 current.pop();
				 level.push_back(node->val);
				 if(node->left!=NULL)
					 next.push(node->left);
				 if(node->right!=NULL)
					 next.push(node->right);			 
			 }
			 if(!left_to_right)//left_to_right是true 不反转  ；   left_to_right是false 就反转  doge
				 reverse(level.begin(),level.end());
			 result.push_back(level);//添加该行
			 left_to_right =! left_to_right;
			 swap(next, current);//交换
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
	vector< vector<int> >v = s.zigzagLevelOrder(T);
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
  



