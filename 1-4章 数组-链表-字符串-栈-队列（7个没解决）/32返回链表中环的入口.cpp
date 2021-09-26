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
	bool hasCycle(ListNode*head)//判断是否有环
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

 
	ListNode* detectCycle2(ListNode* head)//返回环的入口
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
		L->next=p; //每一次循环插入一个节点
	}
	/**/
	for(p = L ; p->next!= NULL ; p=p->next) {}//使p指向最后一个节点
	ListNode* q;  int j =0 ;
	for(q = L ; j <3 ; j++,  q = q->next ) { }//使q指向第3个节点
//		cout<<p->data<<"  "<<q->data<<endl;
	p->next = q;
 
}

//输出单链表
void Print (ListNode* L)
{
	ListNode* p;
	p=L;  //让P赋值为L 
	printf("链表中的元素:\n");
	while(p) 
	{
 	if(p->data > 0 )//头节点
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

