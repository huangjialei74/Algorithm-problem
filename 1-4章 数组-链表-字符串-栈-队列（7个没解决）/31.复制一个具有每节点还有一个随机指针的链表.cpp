#include<iostream>
using namespace std;



struct ListNode
	{
	int data;
	struct ListNode *next;
	struct ListNode *random;
}; 

  //O(n)   O(1) 
/*
在原链表的每两个节点之间插一个node节点 值和前面一个相同
新增节点的随即指针被赋值为上一个循环中新增的节点的random
拆成2 个链表
*/
 class Solution
 {
 public:
	 ListNode* copyRandomList(ListNode* head)
	 {
		 ListNode*cur=head;
		 for(; cur!=NULL; )
		 {
			 ListNode* node=new ListNode;   	 node->data =  cur->data;
			 node->next = cur->next;		 cur->next=node;//在每两个节点之间插一个node节点 值和前面一个相同
			 cur=node->next; //cur移动
		 } 
		
		 for( cur=head; cur!= NULL;  cur=cur->next->next )
		 {
			 if(cur->random != NULL){ 
				 cur->next->random = cur->random->next; //cur->random->next 赋值为上一个循环中新增的节点的random
			 } 			 
		 }
	       		 
		  ListNode *new_cur, *dummy = new ListNode;
		  for( cur=head, new_cur = dummy; cur!= NULL; cur = cur->next)
		  {
			  new_cur->next = cur->next;//cur的后面总是第二个链表的节点 让new_cur指向它
			  new_cur = new_cur->next; //new_cur不断移动  目的是指向下一个第二个链表的节点
			  cur->next = cur->next->next;  //截掉了中间的那个属于第二个链表的节点
		  } 
		  return dummy->next;
	 }
	  
 };

 

void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //开辟空间  
	  L->next=NULL;//其指针域为空
	  L->random = NULL;
	int a[6] = {1,2,3,4,5,6};

	 ListNode* p;//定义一个节点p 
	for( int i=sizeof(a)/sizeof(a[0])-1;i>=0;i--)
	{ 
		p=(ListNode*)malloc(sizeof(ListNode));
		p->data = a[i];
		 p->random = NULL;
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
 	Print(L);
	Solution   s;
	ListNode* l = s.copyRandomList(L);
 	Print(l);




	 

	return 0;
}

