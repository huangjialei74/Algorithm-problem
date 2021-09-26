 #include<iostream>
using namespace std; 
#include<vector>
#include<stack>



#define OK 1
#define ERROR  0
#define OVERFLOW -2
 
//���ݽṹ���� 
typedef  int TElemType;  

struct TreeNode
{
	TElemType val;
	struct TreeNode *left, *right;
}; 
 



// Symmetric Tree

//�ݹ�
// O(n) O(logn)
class Solution
{
public:
	bool isSymmetric(TreeNode* root)
	{
		if(root==NULL)
			return true;
		return isSymmetric(root->left, root->right);
	}
	bool isSymmetric(TreeNode* p, TreeNode* q)
	{
		if(p==NULL && q==NULL)//��ֹ����
			return true;
		 if(p==NULL || q==NULL)//���Գ�
			 return false;
		  return p->val==q->val //�����ϲ�
			  &&isSymmetric(p->left,q->right) 
			  &&isSymmetric(p->right,q->left);
	}
};




//����O(n)  O(logn)
class Solution2
{
public:
	bool isSymmetric(TreeNode* root)
	{
		if(!root)
			return true;
		stack<TreeNode*>s;
		s.push(root->left);
		s.push(root->right);
		while(!s.empty())
		{
			TreeNode*  p=s.top();
			s.pop();
			TreeNode*  q=s.top();
			s.pop();
			if(!p && !q)//ÿ��ֻ�Ƚ�ջ������Ԫ��
				continue;
			if(!p||!q)
				return false;
			if(p->val != q->val)
				return false;
			s.push(p->left);//������  ��һѭ���н��бȽ�  p q˳������ν
			s.push(q->right);
			s.push(p->right);
			s.push(q->left);
		}
		return true;
	}
	 
};

 

//����������
void CreateBiTree(TreeNode* &T)
{
	T=NULL;//ָ���ַΪ�� 
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



//��������ʾ
void DisplayTree(TreeNode* T,int i)//���������˳��������
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


// ��ʼ����: ������T���ڡ��������: ���ٶ�����T
void DestroyBiTree(TreeNode* &T)
{ 
	if(T) // �ǿ���
	{ 
		if(T->left) // ������
			DestroyBiTree(T->left); // ������������
		if(T->right) // ���Һ���
			DestroyBiTree(T->right); // �����Һ�������
		delete T; // �ͷŸ����
		T=NULL; // ��ָ�븳0
	} 
}//���ٶ������ĵݹ��㷨


//������
int main()
{
 
	TreeNode* T ; 	 
	cout<<"���������������չ�������У�" ;				
	CreateBiTree(T);//����   //1 2 3 -1 -1 4 -1 -1 5 -1 -1
	DisplayTree( T,0);
	Solution2 s;
	if(s.isSymmetric(T))
		cout<<"yes "<<endl;

 


 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



