#include<iostream>
using namespace std;


struct ListNode
	{
	int data;
	struct ListNode *next;
}; 

  //L0→L1→···→Ln-1→Ln,  to: L0→Ln→L1→Ln-1→L2→Ln-2→···

//找到中间节点  断开后半段  反序  交错
class Solution
{
public:
	void reorderList(ListNode*head)
	{
		if(head== NULL||head->next==NULL)
			return;
		ListNode *slow=head, *fast=head, *prev=NULL;
		while(fast && fast->next)
		{
			prev=slow;
			slow=slow->next;
			fast=fast->next->next;
		}
		prev->next=NULL;//cut at middle
		
		slow=reverse(slow);

		//merge two lists 
		ListNode*curr=head;
		while(curr->next)
		{
			ListNode*tmp=curr->next;//保存一下前半段链表中的某个节点
			curr->next=slow;//插入slow链表中的节点
			slow=slow->next;
			curr->next->next=tmp;
			curr=tmp;
		}
		curr->next=slow;

	}


	ListNode* reverse(ListNode *head)
	{
		if(head==NULL || head->next==NULL)
			return head;
		ListNode*prev=head;
		for(ListNode*curr=head->next, *next=curr->next;  
		curr;
		prev=curr, curr=next, next=next?next->next:NULL)//头插实现逆序
		{
			curr->next=prev;
		}
		head->next=NULL;
		return prev;
	}
};

void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	 ListNode* p;//定义一个节点p 
	for( int i=sizeof(a)/sizeof(a[0])-1;i>=0;i--)
	{ 
		p=(ListNode*)malloc(sizeof(ListNode));
		p->data = a[i];
		p->next=L->next; 
		L->next=p; //每一次循环插入一个节点
	}
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
//	Print(L);
 	Solution   s;
	  s.reorderList(L);
	Print(L);
 



	 

	return 0;
}

