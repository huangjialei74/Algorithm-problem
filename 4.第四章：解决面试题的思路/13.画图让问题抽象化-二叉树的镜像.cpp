 
 
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
 
 

//������
void MirrorRecursively(TreeNode* T)
{
	if(T==NULL)
		return ;
	if(T->left==NULL && T->right==NULL)
		return ;

	TreeNode* tmp=T->left;
	T->left=T->right;
	T->right=tmp;

	if(T->left)
		MirrorRecursively(T->left);
	if(T->right)
		MirrorRecursively(T->right);

}



//��֤�Գƶ�����
bool isSymmetrical(TreeNode* T1,TreeNode* T2)
{
	if(T1==NULL && T2==NULL) return true;
	if(T1==NULL || T2==NULL) return false;
	if(T1->val!=T2->val)
		return false;
	return isSymmetrical(T1->left,T2->right)&& isSymmetrical(T1->right,T2->left);
}

bool isSymmetrical(TreeNode* T)
{
	return isSymmetrical(T,T);
}







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
 
	TreeNode* T1 ; 	 
	cout<<"���������������չ�������У�" ;				
	CreateBiTree(T1);//����   //1 2 3 -1 -1 4 -1 -1 5 -1 -1
 	DisplayTree( T1,0);

 

 	DestroyBiTree(T1);//���� 
 
	return 0;
}
  



