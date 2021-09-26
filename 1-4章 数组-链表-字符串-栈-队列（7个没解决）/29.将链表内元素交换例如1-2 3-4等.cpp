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
		 if(head==NULL ||head->next==NULL)//head不参与交换  但是head后面第一个要交换    即使第一个后面是NULL
			 return head;

		 ListNode *dummy = new ListNode();   
		 dummy->next = head;
		 for(ListNode *prev= dummy->next, *cur=prev->next, *next=cur->next; //三个指针   prev得指向head
		     next;//到尾
		     prev=cur, cur=cur->next, next=cur?cur->next:NULL)//prev=cur 相当于prev移动到了下一对节点的前一个  cur next是下一对节点
		 {
			 prev->next = next;//在链表中  反转 prev后面的两个节点cur和next 两个节点的顺序 
			 cur->next = next->next;
			 next->next = cur;
		 }
		 return dummy->next;
	 }
	  
 };

 



//直接交换值 
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
	 L=(ListNode*)malloc(sizeof(ListNode));  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[6] = {1,2,3,4,5,6};

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

