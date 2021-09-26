#include<iostream>
using namespace std;



struct ListNode
	{
	int data;
	struct ListNode *next;
}; 

  
//�ݹ�
class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if(!head||!head->next)
			return head;

		 ListNode*p=head->next;//p��head��һ��
		 if(head->data==p->data)
		 {
			 while(p && head->data==p->data)//������whileѭ�� ��Ѻ�headֵ��ͬ�ĺ���Ľڵ�ȫ��ɾ��
			 { 
				 ListNode*tmp=p;
				 p=p->next; 
				 delete tmp; //��ɾhead�����
			 } 
			 delete head; // ��ɾ�� head 
			 return deleteDuplicates(p);
		 }
		 else
		 {
			 head->next = deleteDuplicates(head->next);
			 return head;
		 }
	}
 
};

//����
class Solution2
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if(head == NULL )
			return head;
		ListNode* dummy = new ListNode();
		dummy->next = head;
		ListNode*  prev = dummy, *cur = head; //prevָ��headǰһ��   curָ��head
		while(cur!= NULL)
		{
			bool duplicated=false;
			while( cur->next != NULL && cur->data==cur->next->data)//whileѭ�� ��Ѻ�headֵ��ͬ�ĺ���Ľڵ�ȫ��ɾ��
			{ 
				duplicated=true;
				ListNode*temp=cur;
				cur=cur->next;
				delete temp;
			}
			if(duplicated)//��ɾ����һ���ڵ�
			{
				ListNode*temp=cur;
				cur=cur->next;
				delete temp;
				continue; //��cur��cur->next���ʱ�� ɾ����Щ�ڵ�   cur����ӵ�prev���棬����Ϊ����Ľڵ㣬����ֵҲ��ȣ�
			}
			prev->next=cur;// ��cur��cur->next�����ʱ--------��ӽڵ�cur��prev����  
			prev=prev->next;//prev����----Ϊ��һ������ӽڵ�   
			cur=cur->next; //cur���� 
		}
		prev->next=cur;//β�ڵ�NULL
		return dummy->next;
	}

  
};



void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[4] = {3,3,3,6};

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
		p=p->next;
	}
	cout<<endl;
}







int main()
{
	ListNode* L;
	creat(L);
//	Print(L); 
	Solution2  s;
	ListNode* l = s.deleteDuplicates2(L);
	Print(l);




	 

	return 0;
}

