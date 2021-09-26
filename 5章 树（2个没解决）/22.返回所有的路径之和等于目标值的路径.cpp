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
	vector<vector<int> >pathSum(TreeNode*root,int sum)
	{
		vector<vector<int> >result;
		vector<int>cur;//�м���
		pathSum(root, sum, cur, result);
		return result;
	}
private: void pathSum(TreeNode* root,int gap,vector<int>& cur, vector<vector<int> >&result)//cur���������ã���Ȼ���ص�ֵû�н����޸�
		 {
			 if(root==NULL)
				 return;
			 cur.push_back(root->val);
			 if(root->left==NULL && root->right==NULL && gap==root->val)//Ҷ�ӽڵ� ���� ����Ҫ��
			 { 
				 result.push_back(cur);
			 }
			 //����ǰ�����жϿ�ָ�봫��ʱ�Ĳ��� �˴������ж����������Ƿ�Ϊ��
			 pathSum(root->left, gap-root->val, cur, result);// �ݹ���cur��ֵ�ڱ仯
			 pathSum(root->right, gap-root->val, cur, result);
			 cur.pop_back();//һ��·����ͷʱ�Ż��ջ ��������
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
  



