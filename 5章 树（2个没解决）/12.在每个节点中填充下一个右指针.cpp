 
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
	struct TreeNode *left, *right ,*next;
}; 
 
/*
      1
	  /\
	 2  3
	/\   \
   4  5   7

      1->NULL
      /\
	 2->3->NULL
	/\   \
   4->5->7->NULL
*/


 //���Ʋ������
 // O(n) O(1)
class Solution
{
public:
	void connect(TreeNode*  &root)
	{
		if(root==NULL) 	return; 
	 	TreeNode* dummy = new TreeNode();    dummy->val = -1;//��һ���ͷ���

		TreeNode* curr=root, *prev=  dummy;
		for(  ; curr ; curr = curr->next)
		{	
			if(curr->left!=NULL)
			{  
				prev->next=curr->left;  //�������͸�ֵ������prev��next   
				prev=prev->next; 
			}
			if(curr->right!=NULL) 
			{  
				 prev->next=curr->right;
				 prev=prev->next;
			}
		} 
	 	prev->next=NULL;//�ò����һ���ڵ��nextΪNULL
	 	connect(dummy->next);
	}
};

 
// O(n) O(1)
class Solution2
{
public:
	void connect(TreeNode* root)
	{
		while(root)
		{
			 
			TreeNode* next=NULL; 
			TreeNode*prev=NULL;
			for( ; root; root=root->next)
			{
				if(!next)
					next = root->left? root->left: root->right; //��һ�� ������ΪNULL
				if(root->left)
				{
					if(prev)//��ǰ��������ǰ������
						prev->next=root->left;
					prev=root->left;  //�л���û�� ����ֵΪǰ��
				}
			if(root->right)
				{
					if(prev)
						prev->next=root->right;  
					prev=root->right;
				}
			}
			root=next; //root�����ÿһ��  ֻ�������һ��ʱif(root->left)  if(root->left)�������в���
		}
	}
};


// O(n) O(logn) ����5.4.6  ������sibling ������ھ���Ϊ�ýڵ��next
class Solution3
{
public:
	void connect(TreeNode* root)
	{
		connect(root,NULL);
	}
private:
	void connect(TreeNode* root,TreeNode* sibling)
	{
		if(root==NULL)
			return;
		else
			root->next=sibling;
		connect(root->left,root->right);
		if(sibling) //����� ��sibling��Ϊ��������next
			connect(root->right, sibling->left);
		else
			connect(root->right,NULL);
	}
};


//����������
void CreateBiTree(TreeNode* &T)
{
	T=NULL;//ָ���ַΪ�� 
	TElemType ch;
		 
	cin>>ch;
 	   
	if(ch == -1)
		T=NULL;
	else 
	{ 
		T= new TreeNode;
		if(!T)
			exit(OVERFLOW); 
		T->val = ch;
		T->next = NULL;
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

  if(T->next!= NULL)  
  	cout<<T->next->val ; 

    if(T->next== NULL)  
  	cout<<"����" ; 


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
	CreateBiTree(T);//����   //1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
 //	DisplayTree( T,0);

	Solution s;
	s.connect(T);
	cout<<"-----------------------------"<<endl;
	DisplayTree( T,0);

 

 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



