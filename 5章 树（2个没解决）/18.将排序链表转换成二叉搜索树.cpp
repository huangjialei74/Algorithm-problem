 
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
  

struct ListNode
	{
	int val;
	struct ListNode *next;
};    



//���η� �Զ�����

// O(n^2) O(logn)
class Solution
{
public:
	TreeNode*sortedListToBST(ListNode* head)
	{
		return sortedListToBST(head, listLength(head));
	}
	TreeNode*sortedListToBST(ListNode*head,int len)
	{
		if(len==0)
			return NULL;
		if(len==1)
		{
			TreeNode* retu; retu->val = head->val;
			return retu;
		} 
		TreeNode*root=new TreeNode ;    root->val = nth_node(head, len/2+1)->val;//�����м�ڵ��ֵ �����ڵ�
		root->left = sortedListToBST(head, len/2);//�������������½���ͷ���
		root->right = sortedListToBST(nth_node(head, len/2+2), (len-1)/2);//�������������½��� �����м�ڵ����һ��
		return root;
	}
	int listLength(ListNode* node)//��������
	{
		int n=0;
		while(node)
		{
			++n;
			node=node->next;
		}
		return n;
	}
	ListNode* nth_node(ListNode*node, int n)//���������n ���ڵ� 
	{
		while(--n)
			node=node->next;
		return node;
	}
};


 //���¶���O(n) O(logn)
class Solution2
{
public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		int len=0;
		ListNode*p=head;
		while(p)
		{
			len++;
			p=p->next;
		}//�������һ���ڵ��NULL
		return sortedListToBST(head, 0, len-1);
	}
private:
	TreeNode* sortedListToBST(ListNode* &list, int start, int end)
	{
		if(start>end)
			return NULL;
		int mid = start+(end-start)/2;
		TreeNode* leftChild = sortedListToBST(list, start, mid-1);// ��������� ��ݹ�ذ��������ȫ�����ĵ�

		TreeNode* parent = new TreeNode; //���ڵ�
		parent->val = list->val ;  
		parent->left = leftChild;   

		list = list->next;//������
		parent->right = sortedListToBST(list, mid+1, end);
		return parent;
	}
};




void creat(	ListNode* &L)
{	
	 L=new ListNode;  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	 ListNode* p;//����һ���ڵ�p 
	for( int i=10-1;i>=0;i--)
	{ 
		p=(ListNode*)malloc(sizeof(ListNode));
		p->val = a[i];
		p->next=L->next; 
		L->next=p; //ÿһ��ѭ������һ���ڵ�
	}
}



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
	ListNode* L;
	creat(L);

    Solution2 s;
	 TreeNode* T = s.sortedListToBST(L->next);  
 

	 DisplayTree( T,0);


 	DestroyBiTree(T);//����
	
 
	return 0;
}
  


 