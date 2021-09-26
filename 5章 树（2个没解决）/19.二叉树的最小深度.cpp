 
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
 

#define min(a, b) a<=b? a:b;

#define max(a, b) a>b? a:b;
 
//�ݹ�� 
class Solution
{
public: 
	int minDepth(  TreeNode*root)
	{	 
		return minDepth(root,false);
	}
private:
	 int minDepth( TreeNode*root, bool hasbrother)
	 {   
		if( root==NULL){			
			return  hasbrother ? INT_MAX:0;//���ڵ�Ϊ��  �����ֵ�ʱ �˽ڵ������巵��INT_MAX ������root==NULL ��ֱ�ӷ���0��
		} 
		return 1 + min(minDepth(root->left,root->right!=NULL), minDepth(root->right,root->left!=NULL));
	 }
	  
};




//������
// O(n)  O(logn)
class Solution2
{
public:
	int minDepth(TreeNode* root)
	{
		if(root==NULL)
			return 0;
		int result=INT_MAX; 
		stack< pair<TreeNode*,int> >s;	
		s.push(make_pair(root,1));

		while(!s.empty())//�е��������
		{
			TreeNode* node=s.top().first;
			int depth=s.top().second;
			s.pop();
			if(node->left==NULL && node->right==NULL)//ΪҶ�ӽڵ�ʱ  ������result    result��¼Ҷ�ӽڵ����С���
				result=min(result, depth); 

			if(node->left!=NULL && result>depth)// ��ǰ��С��ȴ��� �ýڵ�����ʱ �Ż��������������
				s.push(make_pair(node->left, depth+1));//�ýڵ��������

			if(node->right!=NULL && result>depth)
				s.push(make_pair(node->right, depth+1));//�ýڵ��������
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

	Solution s;
	
	int len = s.minDepth(T) ;
 cout<<"���"<<len<<endl; 

 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



