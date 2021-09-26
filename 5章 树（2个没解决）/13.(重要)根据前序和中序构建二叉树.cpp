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
//��֪�������򣬴���������
void  Create(TreeNode* &T,TElemType pre[],TElemType in[],int m,int n,int len)//m�Ǹ��ڵ�������pre�е�λ��  n�Ǹ��ڵ�������in�д����￪ʼ����
{
	TElemType ch;
	int i,j;
	if(!len)
	{
		T=NULL; 	 	
	}
	else
	{
		ch=pre[m];	
		T=new TreeNode;
		T->val=ch;	
		i=Locate(in,ch, n, len);//�ҵ���ch��in�е�λ��   
		j=i-n;  //��ʾһ���������ĳ���
		//( ���������������  ͨ�����ڵ� �ָ���)
		Create(T->left, pre, in, m+1, n, j);//���ڵ�ȡpre[m+1] ,��n��ʼ��   ���ҳ���Ϊj  
		
		Create(T->right, pre, in, m+j+1, i+1, len-j-1);//���ڵ�ȡpre[m+j+1] ,��i+1��ʼ��    ���ҳ���Ϊlen -j-1  
	}
 
}




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
 
	TreeNode* T ; 	 
	cout<<"���������������չ�������У�" ;				
	CreateBiTree(T);//����   //1 2 3 -1 -1 4 -1 -1 5 -1 -1
	DisplayTree( T,0);

 


 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



