 
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
 



 /*
 Given
    1
    /\
   2  5
   /\  \
  3 4   6
 The flattened tree should look like:
  1
   \
    2
     \
      3
       \
        4
         \
          5
           \
            6
*/

// �ݹ��1 O(n)   O(logn)
class Solution1
{
public:
	void flatten(TreeNode* root)
	{
		if(root==NULL)
			return;
		flatten(root->left);
		flatten(root->right);

		if(root->left == NULL)//��������
			 return;
		TreeNode*p=root->left;
		while(p->right) 
			 p=p->right;//������������

		p->right = root->right;// ����������������Ҵ���Ȼ��������ֵ�������� ����Ϊ�գ�
		//����234  ��4����3�ұ�   Ȼ���34  ����2�ұ�  �γ�234  ��  ��56����4�ұ�  �ٰ�������߷�����������
		root->right = root->left;
		root->left = NULL;
	}
	 
};


//�㲻��-������
// �ݹ��2 O(n)   O(logn)
class Solution2
{
public:
	void flatten(TreeNode* root)
	{
		flatten(root, NULL);
	}
private:
	TreeNode* flatten(TreeNode*root, TreeNode*tail)	
	{
		if(root==NULL) 
			return tail;
		tail = flatten(root->right, tail);
		root->right = flatten(root->left, tail );
		root->left=NULL;
		return root;
	}
};

//������O(n)  O(logn)
class Solution3
{
public:
	void flatten(TreeNode* root)
	{
		if(root== NULL)
			return;
		stack<TreeNode*>s;
		s.push(root);

		while(!s.empty())
		{
			TreeNode* p=s.top();//��ջ���ڵ� ����ѭ������һ��   ��ʹ������ȫ�������� �������ſ�ʼ���� 
			s.pop();
			if(p->right)//�����ھͲ���ջ  ��Ϊѭ����ÿ��ֻ��ջһ��  
				s.push(p->right);
			if(p->left)
				s.push(p->left);
			p->left=NULL;//�����NULL
			if(!s.empty())
				p->right=s.top();   //������ջ  �������ջ  ----->  ���������ͷ������  �ұ��ڸ�����  
			                         
		}
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
  



