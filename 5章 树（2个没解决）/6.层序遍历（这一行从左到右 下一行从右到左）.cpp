 
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
  

// O(n) O(n)
class Solution
{
public:
	vector< vector<int> >zigzagLevelOrder(TreeNode*root)
	{
		vector<vector<int> >result;
		traverse(root,1,result,true);
		return result;
	}
	void traverse(TreeNode* root, size_t level, vector< vector<int> >&result, bool left_to_right)//bool true����������ң� ����ʱ��תһ�� 
	{
		if(!root)
			return;
		if(level > result.size())
			result.push_back(vector<int>());

	 	if(left_to_right)//true�����������   �ŵ�vector����β��
			result[level-1].push_back(root->val);
		else             //false�����������//����vector����ͷ��
			result[level-1].insert(result[level-1].begin(), root->val);
/*��֪������Ϊʲô����reverse
		result[level-1].push_back(root->val);
		if(!left_to_right)
			 reverse(result[level-1].begin(),result[level-1].end());
*/

		traverse(root->left,  level+1, result, !left_to_right);//��ʱ��������  ��left_to_rightһ��   ������ڵ��෴
		traverse(root->right, level+1, result, !left_to_right);
	}
};


#include<queue>

// O(n)  O(n)
class Solution2
{
public:
	vector< vector<int> >zigzagLevelOrder(TreeNode*root)
	{
		vector< vector<int> >result;
		queue<TreeNode*>current, next;	
		if(root==NULL){
			return result;	
		else
			current.push(root);

    	bool left_to_right=true;//�Ƿ�ת
		while(!current.empty())
		{
			 vector<int>level;
			 while(!current.empty())
			 {
				 TreeNode*node=current.front();
				 current.pop();
				 level.push_back(node->val);
				 if(node->left!=NULL)
					 next.push(node->left);
				 if(node->right!=NULL)
					 next.push(node->right);			 
			 }
			 if(!left_to_right)//left_to_right��true ����ת  ��   left_to_right��false �ͷ�ת  doge
				 reverse(level.begin(),level.end());
			 result.push_back(level);//��Ӹ���
			 left_to_right =! left_to_right;
			 swap(next, current);//����
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


	Solution s ;
	vector< vector<int> >v = s.zigzagLevelOrder(T);
	for(vector< vector<int> >::iterator it = v.begin(); it != v.end(); it++)
	{
		for(vector<int>::iterator it2 =  it->begin(); it2 != it->end(); it2++)
		{
			cout<<(*it2)<<" ";
		}
		cout<<endl;  
	}

 	DestroyBiTree(T);//����
	
 
	return 0;
}
  



