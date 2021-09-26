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
	bool hasCycle(ListNode*head)//�ж��Ƿ��л�
	{
		if(!head) return false;

		ListNode*slow=head,*fast=head;
		while(fast&&fast->next)
		{
			slow=slow->next;
			fast=fast->next->next;
			if(slow==fast)
				return true;
	}
		return false;
	}

 
	ListNode* detectCycle2(ListNode* head)//���ػ������
	{
		if(!head) return NULL;
		ListNode*slow=head, *fast=head;
		while(fast&&fast->next)
		{
			slow=slow->next;
			fast=fast->next->next;
			if(slow==fast)
			{ 
				ListNode* slow2 = head;   
			  	while(1) {
		 		    slow2 = slow2->next; slow = slow->next;// cout<<slow->data<<endl;  cout<<slow2->data<<endl; 
			 		if(slow2 == slow)  return slow;
				}
			}
		}
		return NULL;
	}
};

void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));   
	  L->next=NULL; 
	int a[8] = {1,2,3,4,5,6,7,8 };

	 ListNode* p; 
	for( int i=sizeof(a)/sizeof(a[0])-1;i>=0;i--)
	{ 
		p=(ListNode*)malloc(sizeof(ListNode));
		p->data = a[i];
		p->next=L->next; 
		L->next=p; //ÿһ��ѭ������һ���ڵ�
	}
	/**/
	for(p = L ; p->next!= NULL ; p=p->next) {}//ʹpָ�����һ���ڵ�
	ListNode* q;  int j =0 ;
	for(q = L ; j <3 ; j++,  q = q->next ) { }//ʹqָ���3���ڵ�
//		cout<<p->data<<"  "<<q->data<<endl;
	p->next = q;
 
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
// Print(L);	
 	Solution   s;
	ListNode* l = s.detectCycle2(L);
	 cout<<l->data<<endl;
 
 	 




	 

	return 0;
}

