 
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
����
  3
  /\
  9 20
    /\
   15 7
   return [[3],[9,20],[15,7]]
*/



//�ݹ� O(n) O(n)
class Solution
{
public:
	vector< vector<int> >levelOrder(TreeNode*root)
	{
		vector< vector<int> >result;
		traverse(root, 1, result);
		return result;
	}
	void traverse(TreeNode*root, size_t level, vector< vector<int> >&result)//levelΪ����
	{
		if(!root)  
			return;
		if(level > result.size())//ÿһ�����нڵ��level һ����
			result.push_back(vector<int>());  
		result[level-1].push_back(root->val);
	
		traverse(root->left, level+1, result);//ÿ������һ��ֵ   �������ҽڵ��ֵ  ���������������ȫ���ӽ�ȥ
	    traverse(root->right, level+1, result);
	}
	 
};



#include<queue>
#include<deque>
//����O(n)  O(1)
class Solution2
{
public:
	vector< vector<int> >levelOrder(TreeNode* root)
	{
		vector< vector<int> >result;
		queue<TreeNode*>current, next; //����
		if(root==NULL){
			return result;
		}
		else{
			current.push(root);//ֻ��Ӹ��ڵ�
		}
		while(!current.empty())
		{
			vector<int>level; 
			while(!current.empty())//ѭ��
			{
				TreeNode*node=current.front();//�����һ�ȡ
				current.pop();
				level.push_back(node->val);
				if(node->left != NULL)
					next.push(node->left);//��ڵ���next����
				if(node->right != NULL)
					next.push(node->right);	//�ҽڵ���next����
			}
			result.push_back(level);//��Ӹ���
			swap(next,current);//����  --1��2 2��4 4��8   doge
		}
		return result;
	}


	//��ָoffer�ϵĵ���  ������ 
	vector<int> levelOrder2(TreeNode* root)
	{
		vector<int>result;
		if(!root) return result;
		deque<TreeNode*>deq;
		deq.push_back(root);
		 
		while(!deq.empty())
		{
			TreeNode* p=deq.front();
			deq.pop_front();
			result.push_back(p->val );
			if(p->left) deq.push_back(p->left);
			if(p->right) deq.push_back(p->right);
		}
		return result;

	}
	//����
	vector< vector<int> >levelOrder3(TreeNode* root)
	{
		vector< vector<int> >result;
		queue<TreeNode*>que; //����
		if(root==NULL)
			return result;
		que.push(root); 
		
		int  nextLevel=0, toBeAdd=1;//��ǰ������ ��һ��Ҫ��ӵĽڵ���  ��ǰ�л��ж���û���
		vector<int>v;//����ÿһ�нڵ�ֵ
		while(!que.empty())
		{
			TreeNode* pNode=que.front();
			que.pop();
		 
			v.push_back(pNode->val);
			--toBeAdd;//û��ӵĽڵ�������һ��

			if(pNode->left!=NULL)
			{
				que.push(pNode->left);
				++nextLevel;				
			}
			if(pNode->right!=NULL)
			{
				que.push(pNode->right);
				++nextLevel;
			}
			if(toBeAdd==0) //��û����ӵ����� Ϊ0ʱ  ȥ��һ�����
			{
				result.push_back(v);
				v.clear(); //�����һ�㱣��Ľڵ�ֵ
				toBeAdd=nextLevel;//��ֵ��һ����Ҫ��ӵĽڵ�����
				nextLevel=0;//����
			}		 
		}
		return result;
	}


	//֮���ͱ���  ����������
	vector< vector<int> >levelOrder4(TreeNode* root)
	{
		vector< vector<int> >result;
		if(root==NULL) 
			return result;

		stack<TreeNode*>level[2];//һ���洢��ǰ  һ���洢��һ��
		int current=0,  next=1;
		level[current].push(root);
		while(!level[current].empty() || !level[current].empty())
		{
			TreeNode* pNode;
			vector<int>v;
			while(!level[current].empty())
			{			
				pNode=level[current].top();
				level[current].pop();
                v.push_back(pNode->val);//������ջ�Ľڵ�ʱ ���ӽڵ㱣������һ��ջ���� ������ʱ  ��������ջ
				if(current==0)//�������� ��������
				{
				    if(pNode->left!=NULL)  level[next].push(pNode->left);
				    if(pNode->right!=NULL) level[next].push(pNode->right);
				}
				if(current==1)//�������� ��������
				{
				    if(pNode->right!=NULL) level[next].push(pNode->right);
				    if(pNode->left!=NULL)  level[next].push(pNode->left);
				}
			}
			result.push_back(v);
			current=1-current;//��������ջ
			next=1-next;
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
	CreateBiTree(T);//����   //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
	DisplayTree( T,0);


	Solution2 s ;
	vector< vector<int> >v = s.levelOrder4(T);
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
  



