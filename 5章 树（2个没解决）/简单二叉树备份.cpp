 
#include<iostream>
using namespace std;

#define OK 1
#define ERROR  0
#define OVERFLOW -2
 
//���ݽṹ���� 
typedef  char TElemType;  

struct TreeNode
{
	TElemType data;
	struct TreeNode *lchild, *rchild;
}; 
 



//����������
void CreateBiTree(TreeNode* &T)
{
	T=NULL;//ָ���ַΪ�� 
	TElemType ch;
		
	scanf("%c",&ch);
	if(ch == ' ')	   
		T=NULL;
	else 
	{
		T=(TreeNode *)malloc(sizeof(TreeNode));//����Ĳ�Ϊ�գ�ָ��Tָ�����ַ
		if(!T)
			exit(OVERFLOW);//�����Ϊ�գ�Tָ��գ���̬�ڴ�����ʧ�ܣ��������
		T->data = ch;

		CreateBiTree(T->lchild);//��һ�����������ֵ��T->data��Ȼ�󴴽������ӣ����ڶ������������ֵ�����ӣ��ٴ����ô�������		                         
		CreateBiTree(T->rchild);//�ٴ����Һ��ӽڵ㡣�����������������Ϊ�գ����Ǹ����ӽڵ��Ϊ��
	} 
} 



//��������ʾ
void DisplayTree(TreeNode* T,int i)//���������˳��������
{
	int j;
	if (T == NULL) return;
	if(T->lchild!=NULL)
		DisplayTree(T->lchild,i+1); 	
	for(j=1;j<=i;j++) 	
		cout<<"\t"; 
	cout<<"       "<<T->data;
	for(j=i+1;j<=8;j++)		
		cout<<"--------";
	cout<<endl;
	if(T->rchild!=NULL)
		DisplayTree(T->rchild,i+1);
} 


// ��ʼ����: ������T���ڡ��������: ���ٶ�����T
void DestroyBiTree(TreeNode* &T)
{ 
	if(T) // �ǿ���
	{ 
		if(T->lchild) // ������
			DestroyBiTree(T->lchild); // ������������
		if(T->rchild) // ���Һ���
			DestroyBiTree(T->rchild); // �����Һ�������
		free(T); // �ͷŸ����
		T=NULL; // ��ָ�븳0
	} 
}//���ٶ������ĵݹ��㷨


//������
int main()
{
	TreeNode* T ; 	 
	printf("���������������չ�������У�");				
	CreateBiTree(T);//����			
		 

	DisplayTree( T,0);


 	DestroyBiTree(T);//����
	return 0;
}
  



