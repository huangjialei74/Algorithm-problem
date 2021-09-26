 
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
 

bool Equal(double num1, double num2)
{
	if(num1-num2>-0.0000001 && num1-num2<0.0000001)//�ж�double��float�����Ƿ������ע��
		return true;
	else
		return false;
}

bool DoesTree1HaveTree2(TreeNode* T1,TreeNode* T2)
{
	if(T2==NULL) return true;//��������
	if(T1==NULL) return false;
//	if(!Equal(T1->val,T2->val)) return false;
	return DoesTree1HaveTree2(T1->left,T2->left) && DoesTree1HaveTree2(T1->right,T2->right);
}

bool hasSubTree(TreeNode* T1,TreeNode* T2)
{
	bool result=false;
	if(T1 != NULL && T2!=NULL)
	{
		if(Equal(T1->val,T2->val))//�ҵ����
			result=DoesTree1HaveTree2(T1,T2);
		if(!result)
			result=hasSubTree(T1->left,T2);
		if(!result)
			result=hasSubTree(T1->right,T2);
	}
	return result;
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

	TreeNode* T2 ; 	 
	cout<<"���������������չ�������У�" ;				
	CreateBiTree(T2);//����   //1 2 3 -1 -1 4 -1 -1 
 	DisplayTree( T2,0);

	if(hasSubTree(T1,T2))
		cout<<"��ð�"<<endl;
 

 	DestroyBiTree(T1);//����
	DestroyBiTree(T2);//����
 
	return 0;
}
  



