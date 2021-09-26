#include<iostream>
using namespace std;





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



//ʵ����������  �ֱ��������л��������ͷ����л�������


void Serialize(TreeNode* pRoot, ostream& stream)
{
	if(pRoot==NULL)
	{
		stream<<"$";
		return ;
	}
	stream<<pRoot->val<<',';
	Serialize(pRoot->left,stream);
	Serialize(pRoot->right,stream);
}
void Deserialize(TreeNode** pRoot, istream& stream)
{
	int number;
	if(ReadStream(stream, &number))//ReadStream���ù�
	{
		*pRoot=new TreeNode();
		(*pRoot)->val=number;
		(*pRoot)->left=NULL;
		(*pRoot)->right=NULL;
		Deserialize(&(*pRoot)->left, stream);
		Deserialize(&(*pRoot)->right, stream);
	}
}











int main()
{
	 

	return 0;
}

