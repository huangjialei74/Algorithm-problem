 
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
 Given
    1
    /\
   2  5
   /\  \
  3 4   6
 The flattened tree should look like:
  1
   \
    2
     \
      3
       \
        4
         \
          5
           \
            6
*/

// 递归版1 O(n)   O(logn)
class Solution1
{
public:
	void flatten(TreeNode* root)
	{
		if(root==NULL)
			return;
		flatten(root->left);
		flatten(root->right);

		if(root->left == NULL)//结束条件
			 return;
		TreeNode*p=root->left;
		while(p->right) 
			 p=p->right;//左子树的最右

		p->right = root->right;// 把右树接在左的最右处，然后左树赋值给右树， 左树为空，
		//对于234  把4放在3右边   然后把34  放在2右边  形成234  ，  把56放在4右边  再把整个左边放在右子树处
		root->right = root->left;
		root->left = NULL;
	}
	 
};


//搞不懂-！！！
// 递归版2 O(n)   O(logn)
class Solution2
{
public:
	void flatten(TreeNode* root)
	{
		flatten(root, NULL);
	}
private:
	TreeNode* flatten(TreeNode*root, TreeNode*tail)	
	{
		if(root==NULL) 
			return tail;
		tail = flatten(root->right, tail);
		root->right = flatten(root->left, tail );
		root->left=NULL;
		return root;
	}
};

//迭代版O(n)  O(logn)
class Solution3
{
public:
	void flatten(TreeNode* root)
	{
		if(root== NULL)
			return;
		stack<TreeNode*>s;
		s.push(root);

		while(!s.empty())
		{
			TreeNode* p=s.top();//把栈顶节点 当作循环的下一次   致使左子树全部连接完 右子树才开始连接 
			s.pop();
			if(p->right)//不存在就不入栈  因为循环中每次只出栈一个  
				s.push(p->right);
			if(p->left)
				s.push(p->left);
			p->left=NULL;//左边置NULL
			if(!s.empty())
				p->right=s.top();   //先右入栈  再左边入栈  ----->  左边连接在头结点后面  右边在更后面  
			                         
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

 

 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  



