#include<iostream>
using namespace std;



struct ListNode
	{
	int data;
	struct ListNode *next;
};    

//�ݹ� ����O(n)    O(1)
class Solution
{
public:ListNode* deleteDuplicates(ListNode* head)
	   {
		   if(head == NULL)
			   return head;
		   ListNode* dummy = (ListNode*)malloc(sizeof(ListNode)); 
		   dummy->data = head->data + 1 ;     dummy->next=head;
		   recur( dummy,head);//��ǰָ�� ����һ��ָ��
		   return dummy->next;
	   }
private:static void recur(ListNode* prev,ListNode* cur)
		{
			if(cur==NULL)
				return;
			if(prev->data == cur->data)
			{
				prev->next = cur->next;
				delete cur;
				recur(prev,prev->next);//prev��prev���µ���һ��
			}
			else{
				recur(prev->next,cur->next);//������Ųһ��
			}
		}
};


//����  
 
class Solution2
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
	      if(head == NULL)
			   return head;
		for(ListNode* prev=head,*cur=head->next;  cur != NULL;  )//һ��ָ��ͷ һ����ָ���һ��
		{
			if(prev->data==cur->data)
			{
				prev->next=cur->next;
				delete cur;
			}
			else{
				prev=cur;
			}
			cur=prev->next;
		}
		return head;
	}
};
 






void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[9] = {1,1,3,3,4,4,5,5,6};

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
	Solution2 s;
	ListNode* l = s.deleteDuplicates(L);
	Print(l);




	 

	return 0;
}

