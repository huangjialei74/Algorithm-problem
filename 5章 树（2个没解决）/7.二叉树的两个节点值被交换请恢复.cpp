 
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
 

/*O(n)�Ľⷨ ������iһ��ָ������ ������� ���ڵ�ָ���ŵ������Ȼ��Ѱ�����������λ��
��ǰ�����ҵ�һ�������λ�� �Ӻ���ǰ�ҵڶ��������λ��  ����ָ���ֵ
 ʹ�� Morris�������
*/

class Solution
{
public:
	void recoverTree(TreeNode* root)
	{
		pair<TreeNode*, TreeNode*>broken;
		TreeNode* prev=NULL;
		TreeNode* cur=root;
		while(cur!=NULL)
		{
			if(cur->left==NULL)
			{
				detect(broken, prev, cur);
				//�������  ����vector����  result.push_back()�����˴˴���detect() �ܱ�����ÿһ���ڵ�  
				prev=cur;
				cur=cur->right;
			}
			else
			{
			   TreeNode* node=cur->left;
				while(node->right!= NULL && node->right !=cur)
					node=node->right;
				if(node->right==NULL)
				{
					node->right=cur; 
					cur=cur->left;
				}
				else
				{
					detect(broken,prev,cur);//��������
					node->right=NULL;
					prev=cur;
					cur=cur->right;
				}
			}
		}
		swap(broken.first->val, broken.second->val);
	}
	void detect(pair<TreeNode*,TreeNode*>&broken, TreeNode* prev, TreeNode*current)
		//��������ÿһ���ڵ㣬first��ȡ��һ��������˳��Ľڵ� ��֮�󲻷����ı䣬 
		//ֻҪ�����prev����current  second�͸ı�   ���ڶ���������˳��ĵ�
	{
		if(prev!=NULL && prev->val > current->val)
		{
			if(broken.first==NULL)//֮ǰΪ�վ���ӣ�   ��Ϊ�վͲ�����
			{
				broken.first=prev;
			}
            broken.second=current;//�ڶ�λ�ظ���
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


	Solution s ;
	s.recoverTree(T);
	DisplayTree( T,0);


	cout<<endl;


 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



