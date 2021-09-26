#include<iostream>
using namespace std;

struct ListNode
	{
	int data;
	struct ListNode *next;
}; 


  //O(n)   O(1)
 class Solution
 {
 public:
	 ListNode* swapPairs(ListNode* head) 
	 {
		 if(head==NULL ||head->next==NULL)//head�����뽻��  ����head�����һ��Ҫ����    ��ʹ��һ��������NULL
			 return head;

		 ListNode *dummy = new ListNode();   
		 dummy->next = head;
		 for(ListNode *prev= dummy->next, *cur=prev->next, *next=cur->next; //����ָ��   prev��ָ��head
		     next;//��β
		     prev=cur, cur=cur->next, next=cur?cur->next:NULL)//prev=cur �൱��prev�ƶ�������һ�Խڵ��ǰһ��  cur next����һ�Խڵ�
		 {
			 prev->next = next;//��������  ��ת prev����������ڵ�cur��next �����ڵ��˳�� 
			 cur->next = next->next;
			 next->next = cur;
		 }
		 return dummy->next;
	 }
	  
 };

 



//ֱ�ӽ���ֵ 
class Solution2
{
public:
	ListNode* swapPairs(ListNode*head)
	{
		ListNode*p=head;
		while(p && p->next)
		{
			swap(p->data,p->next->data);
			p=p->next->next;
		}
		return head;
	}
};


void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[6] = {1,2,3,4,5,6};

	 ListNode* p;//����һ���ڵ�p 
	for( int i=sizeof(a)/sizeof(a[0])-1;i>=0;i--)
	{ 
		p=(ListNode*)malloc(sizeof(ListNode));
		p->data = a[i];
		p->next=L->next; 
		L->next=p; //ÿһ��ѭ������һ���ڵ�
	}
}

//���������
void Print (ListNode* L)
{
	ListNode* p;
	p=L;  //��P��ֵΪL 
	printf("�����е�Ԫ��:\n");
	while(p) 
	{
 	if(p->data > 0 )//ͷ�ڵ�
		cout<<p->data<<"  "; 
	else
		cout<<"  "<<" ";
		p=p->next;
	}
	cout<<endl;
}







int main()
{
	ListNode* L;
	creat(L);
//	Print(L);
 	Solution   s;
 	ListNode* l = s.swapPairs(L);
 	Print(l);




	 

	return 0;
}

