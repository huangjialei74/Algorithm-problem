 
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
 

//左右中

//栈O(n) o(n)
class Solution
{
public:
	vector<int>preorderTraversal(TreeNode* root)
	{
		vector<int>result;
		stack<const TreeNode*>s;
		
		const TreeNode*p=root, *prev=NULL;// p正在访问  ,prev上一次访问 
		do{ 
			while(p!=NULL)  
			{
				 s.push(p);
				 p=p->left;//走到底  --保证先左
			}
			prev=NULL;
			while(!s.empty())
			{ 
				p=s.top();//取栈顶   			 
				s.pop();
				if(p->right==prev)//右孩子不存在（叶子节点） 或者 已经访问了（那现在就是根节点） 
				{ 
					result.push_back(p->val);//访问  
					prev=p; 
				}
				else
				{
					s.push(p); //现在不能访问当前根节点  需要二次进栈 
					p=p->right;//到达右子树
					break;//跳出本次while循环!!!
				}
			}
		}while(!s.empty());
		
		return result;
	}

};

/*
Morris遍历 O(n) O(1)
*/
/*
class Solution2
{
public:
	vector<int>postorderTraversal(TreeNode*root)
	{
		vector<int>result;
		TreeNode dummy(-1);
		TreeNode*cur, *prev=nullptr;
		std::function<void(const TreeNode*)>visit=[&result](const TreeNode* node)
		{
			result.push_back(node->val);
		};
		dummy.left=root;
		cur=&dummy;
		while(cur!=nullptr)
		{
			if(cur->left==nullptr)
			{
				prev=cur;			
				cur=cur->right;
			}
			else
			{
				TreeNode*node=cur->left;
				while(node->right!=nullptr&&node->right!=cur)
					node=node->right;
				if(node->right==nullptr)
				{					
					node->right=cur;
					prev=cur;
					cur=cur->left;
				}
				else
				{
				visit_reverse(cur->left,prev,visit);
				prev->right=nullptr;
				prev=cur;
				cur=cur->right;
				}
			}
			}
		return result;
	}
private:
	static void reverse(TreeNode* from,TreeNode* to)
	{
		TreeNode*x=from, *y=from->right, *z; 
		if(from==to)
			return;
		while(x!=to)
		{
			z=y->right;
			y->right=x;
			x=y;
			y=z;
	}
	}
	 static void visit_reverse(TreeNode* from,TreeNode* to,std::function<void(constTreeNode*)>&visit)
	 {
		 TreeNode*p=to;
		 reverse(from,to);
		 while(true)
		 {
			 visit(p);
			 if(p==from)
				 break;
			 p=p->right;
		 }
		 reverse(to,from);
	 }
};
 */

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
	vector<int>v = s.preorderTraversal(T);
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout<<(*it)<<" ";

	cout<<endl;


 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  



