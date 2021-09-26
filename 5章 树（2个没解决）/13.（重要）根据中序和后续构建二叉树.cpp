 
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
  
 
class Solution 
{
public:

//��������������ж�λ����λ��
int Locate(TElemType a[],TElemType ch,int n,int len)
{
	int i=n;
	while(i<n+len  && a[i]!= ch)
	{
		i++;
	}
	return i;
}
//��֪������򣬴���������
void  Create(TreeNode* &T,TElemType In[],TElemType Pos[],int m,int n,int len)//m�Ǹ��ڵ�������Pos�е�λ��  n�Ǹ��ڵ�������in�д����￪ʼ����
{
	TElemType ch;
	int i,j;
	
	if(len >= 1 ) 
	{//cout<<Pos[m]; 
		ch=Pos[m];	
		T=new TreeNode;
		T->val=ch;	
		i=Locate(In ,ch, n, len);//�ҵ� ���ڵ��� �������� �е�λ��  �� n�ǿ�ʼ���ҵ���ʼλ�� �� len�ǲ��ҵĳ���  �����������нڵ���
		j=i-n;      //j���������ĳ���

		//���ں�������� ���Ҹ� �˴��ȹ�������
		Create(T->right, In, Pos, m-1,      i+1, len-j-1); 
		Create(T->left,  In, Pos, m-len+j ,  n , j); //m�Ǹ��ڵ����� ��len�Ǹ������ĳ��ȣ� j�Ǹ���������������   m-(len-j-1) +1 �� mӦ�ü�ȥ�������ĳ���
	}
	else
	{
		T=NULL;
	}
}
};

//	int a[8] = {8,3,2,4,1,6,5,7};
//	int b[8] = {8,3,4,2,6,7,5,1};
 

//����������
void CreateBiTree(TreeNode* &T)
{
	T=NULL; 
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
 
//	TreeNode* T ; 	 
//	cout<<"���������������չ�������У�" ;				
//	CreateBiTree(T);//����   //1 2 3 -1 -1 4 -1 -1 5 -1 -1
//	DisplayTree( T,0);

 //����3 2 4 1 5
//����3 4 2 5 1
	 
	int a[5] = {3,2, 4 ,1, 5};
	int b[5] = {3, 4 ,2 ,5, 1};
	Solution s;
	TreeNode* T2 ;
	s.Create(T2,a,b,4,0,5);
 
	DisplayTree( T2,0);
 

 	DestroyBiTree(T2);//����
	
 
	return 0;
}
  



