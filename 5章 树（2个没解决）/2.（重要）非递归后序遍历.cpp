 
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

//ջO(n) o(n)
class Solution
{
public:
	vector<int>preorderTraversal(TreeNode* root)
	{
		vector<int>result;
		stack<const TreeNode*>s;
		
		const TreeNode*p=root, *prev=NULL;// p���ڷ���  ,prev��һ�η��� 
		do{ 
			while(p!=NULL)  
			{
				 s.push(p);
				 p=p->left;//�ߵ���  --��֤����
			}
			prev=NULL;
			while(!s.empty())
			{ 
				p=s.top();//ȡջ��   			 
				s.pop();
				if(p->right==prev)//�Һ��Ӳ����ڣ�Ҷ�ӽڵ㣩 ���� �Ѿ������ˣ������ھ��Ǹ��ڵ㣩 
				{ 
					result.push_back(p->val);//����  
					prev=p; 
				}
				else
				{
					s.push(p); //���ڲ��ܷ��ʵ�ǰ���ڵ�  ��Ҫ���ν�ջ 
					p=p->right;//����������
					break;//��������whileѭ��!!!
				}
			}
		}while(!s.empty());
		
		return result;
	}

};

/*
Morris���� O(n) O(1)
*/
/*
class Solution2
{
public:
	vector<int>postorderTraversal(TreeNode*root)
	{
		vector<int>result;
		TreeNode dummy(-1);
		TreeNode*cur, *prev=nullptr;
		std::function<void(const TreeNode*)>visit=[&result](const TreeNode* node)
		{
			result.push_back(node->val);
		};
		dummy.left=root;
		cur=&dummy;
		while(cur!=nullptr)
		{
			if(cur->left==nullptr)
			{
				prev=cur;			
				cur=cur->right;
			}
			else
			{
				TreeNode*node=cur->left;
				while(node->right!=nullptr&&node->right!=cur)
					node=node->right;
				if(node->right==nullptr)
				{					
					node->right=cur;
					prev=cur;
					cur=cur->left;
				}
				else
				{
				visit_reverse(cur->left,prev,visit);
				prev->right=nullptr;
				prev=cur;
				cur=cur->right;
				}
			}
			}
		return result;
	}
private:
	static void reverse(TreeNode* from,TreeNode* to)
	{
		TreeNode*x=from, *y=from->right, *z; 
		if(from==to)
			return;
		while(x!=to)
		{
			z=y->right;
			y->right=x;
			x=y;
			y=z;
	}
	}
	 static void visit_reverse(TreeNode* from,TreeNode* to,std::function<void(constTreeNode*)>&visit)
	 {
		 TreeNode*p=to;
		 reverse(from,to);
		 while(true)
		 {
			 visit(p);
			 if(p==from)
				 break;
			 p=p->right;
		 }
		 reverse(to,from);
	 }
};
 */

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


	Solution s ;
	vector<int>v = s.preorderTraversal(T);
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout<<(*it)<<" ";

	cout<<endl;


 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



