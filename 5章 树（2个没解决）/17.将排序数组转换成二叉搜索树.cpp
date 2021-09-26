 
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
 
//���ַ�
//O(n) O(logn)

class Solution
{
public:
	TreeNode* sortedArrayToBST(vector<int>&num)
	{
		return sortedArrayToBST(num.begin(), num.end());
	}

	template<typename RandomAccessIterator>
	TreeNode* sortedArrayToBST(RandomAccessIterator first,  RandomAccessIterator last)
	{
		const auto length=distance(first,last);
		if(length<=0)
			return NULL;
		 RandomAccessIterator mid=first+length/2;//ȡ�м��ֵ �������ڵ�
		 TreeNode*root=new TreeNode; root->val = (*mid);

		 root->left=sortedArrayToBST(first, mid);
		 root->right=sortedArrayToBST(mid+1, last);
		 return root;
	}
	//�����
	TreeNode* sortedArrayToBST(int *arr,int length)
	{
		TreeNode*T;
		sortedArrayToBST(T,arr,length);
		return T;		  
	}
	void sortedArrayToBST(TreeNode*&T, int *arr,int length)
	{
		if(length<=0||arr==NULL)
		{
			T=NULL;
			return ;
		}
		else
		{
			T=new TreeNode;
			T->val=*(arr+length/2);
			sortedArrayToBST(T->left,arr,length/2); 
			sortedArrayToBST(T->right, arr+length/2+1,  (length-1)/2 ); 		 
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
	Solution s;
//	vector<int>v; 
//	for(int i = 0;i<10;i++)  v.push_back(i+1);
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	TreeNode* T = s.sortedArrayToBST(arr,10) ; 	  

	DisplayTree( T,0);

 


 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



