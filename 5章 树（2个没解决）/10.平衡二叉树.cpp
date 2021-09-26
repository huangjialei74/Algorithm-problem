 
#include<iostream>
using namespace std; 
#include<vector>
#include<stack>

#define max(a,b) a>b?a:b;

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
 


//����һ �ÿ����������������������ĸ߶Ȳ�ľ���ֵ������1
// O(n) O(logn)
class Solution
{
public:
	bool isBalanced(TreeNode* root)
	{
		return balancedHeight(root) >=0;
	}
	 int balancedHeight(TreeNode* root)
	 {
		 if(root==NULL)
			 return 0; 
		 int left = balancedHeight(root->left);
		 int right = balancedHeight(root->right);
		 if(left<0 || right<0 || abs(left-right)>1)//��֦   ��������Ϊƽ�������  �� �����߶Ȳ����1
			 return -1;   
		  return max(left,right)+1;//�����ϲ�
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

 


 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



