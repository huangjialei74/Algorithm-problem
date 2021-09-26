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
	TElemType data;
	struct TreeNode *lchild, *rchild;
}; 
 

//ǰ��  ������

//ջO(n) o(n)
class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int>result;
		stack<const TreeNode*>s;
		if(root!=NULL) 
			s.push(root);
		while(!s.empty())//ջ��Ϊ��  ����Ľڵ��ֵȫ����ӵ���result���� �Ϳ��Է�����
		{
			const TreeNode*p=s.top();
			s.pop();     
			result.push_back(p->data);//��Ӹ��ڵ� ��vector����
			if(p->rchild != NULL) 
				s.push(p->rchild);// ��������ջ
			if(p->lchild != NULL)
				s.push(p->lchild);// ��������ջ            ��ջ˳�� ���Һ��� �ڳ�ջʱ���Ա�֤ ����
		}
		return result;
	}
	
};



/*
Morris���� O(n) O(1)
*/
class Solution2
{
public:
	vector<int>preorderTraversal(TreeNode*root)
	{
		vector<int>result;
		TreeNode *cur=root;//, *prev=NULL; //����û�õ�prev ����ɾȥ
		while(cur!=NULL)
		{
			if(cur->lchild==NULL)
			{
				result.push_back(cur->data);
			//	prev=cur;
				cur=cur->rchild;
			}
			else
			{
				TreeNode *node=cur->lchild;//���Һ��
				while(node->rchild != NULL && node->rchild !=cur)
					node=node->rchild;//�ҵ������������ұ�
				/*
				ǰ���������if�����cur  (�����������ҽ���ʱ��� ���ڵ��������)   
				���������else�����cur  (����������ʱ-��Ӹ��ڵ㣩)
				*/
				if(node->rchild==NULL) 
				{
					 result.push_back(cur->data);					 
					 node->rchild=cur;//��cur������������ �γɻ�----cur���������ʱ �����������ڵ� ����������
					// prev=cur;   
					 cur=cur->lchild;//curָ����������-- ����ʼʱ��noede
				}
				else //�����������ڸ��ڵ�
				{
					node->rchild=NULL;//�ϵ�  ��Ϊ����Ѿ���������
					cur=cur->rchild ;//���ڵ������
				}
			}
		}
		return result;
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
		T->data = ch;

		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild); 
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
	cout<<"���������������չ�������У�"<<endl;				
	CreateBiTree(T);//����     1 2 3 -1 -1 4 -1 -1 5 -1 -1
	DisplayTree( T,0);


	Solution2 s ;
	vector<int>v = s.preorderTraversal(T);
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout<<(*it)<<" ";

	cout<<endl;


 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



