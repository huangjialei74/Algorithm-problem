#include<iostream>
using namespace std;



struct ListNode
	{
	int data;
	struct ListNode *next;
}; 

  //O(n)   O(1)
  //递归
class Solution
{
public:
	ListNode* reverseKGroup(ListNode*head, int k)
	{
		if(head==NULL||head->next==NULL||k<2)
			return head;
 
		ListNode* 	next_group  = head;
		for(int i=0; i<k; ++i)
		{
			if(next_group)
				next_group = next_group->next;
			else
				return head;// 链表节点数不足K个
		}  //next_group是下一个链表的头   new_next_group是反转之后的链表的头 
 
		ListNode* new_next_group = reverseKGroup(next_group, k);//递归  反转剩下部分
		ListNode*prev = NULL, *cur=head;

		while(cur != next_group)
		{
			/*
			cur遍历该部分的所有节点，每次将prev(最开始是new_next_group)放在cur后面，然后cur赋值给prev， 
			每次插入cur所指的节点到prev后面，（头插）  实现逆序
			*/
			ListNode *next = cur->next;//记录反转前cur后面的一个节点   cur->next  一会儿赋值给cur
			cur->next = prev ? prev: new_next_group; 
			prev=cur;
			cur=next;
		}
		return prev;// cur后面跟着一串节点   cur赋值给prev    cur好伟大
	}
 
};








 
 
void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[8] = {1,2,3,4,5,6,7,8};

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
		cout<<"无值"<<" ";
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
  	ListNode* l = s.reverseKGroup(L,4);
 	Print(l);




	 

	return 0;
}

