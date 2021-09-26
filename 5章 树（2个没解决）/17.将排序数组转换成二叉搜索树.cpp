 
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
 
//二分法
//O(n) O(logn)

class Solution
{
public:
	TreeNode* sortedArrayToBST(vector<int>&num)
	{
		return sortedArrayToBST(num.begin(), num.end());
	}

	template<typename RandomAccessIterator>
	TreeNode* sortedArrayToBST(RandomAccessIterator first,  RandomAccessIterator last)
	{
		const auto length=distance(first,last);
		if(length<=0)
			return NULL;
		 RandomAccessIterator mid=first+length/2;//取中间的值 当作根节点
		 TreeNode*root=new TreeNode; root->val = (*mid);

		 root->left=sortedArrayToBST(first, mid);
		 root->right=sortedArrayToBST(mid+1, last);
		 return root;
	}
	//数组版
	TreeNode* sortedArrayToBST(int *arr,int length)
	{
		TreeNode*T;
		sortedArrayToBST(T,arr,length);
		return T;		  
	}
	void sortedArrayToBST(TreeNode*&T, int *arr,int length)
	{
		if(length<=0||arr==NULL)
		{
			T=NULL;
			return ;
		}
		else
		{
			T=new TreeNode;
			T->val=*(arr+length/2);
			sortedArrayToBST(T->left,arr,length/2); 
			sortedArrayToBST(T->right, arr+length/2+1,  (length-1)/2 ); 		 
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
	Solution s;
//	vector<int>v; 
//	for(int i = 0;i<10;i++)  v.push_back(i+1);
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	TreeNode* T = s.sortedArrayToBST(arr,10) ; 	  

	DisplayTree( T,0);

 


 	DestroyBiTree(T);//销毁
	
 
	return 0;
}
  



