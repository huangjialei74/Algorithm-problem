#include<iostream>
using namespace std;




struct ListNode
	{
	int data;
	struct ListNode *next;
}; 




class Solution
{
public:
	ListNode*mergeTwoLists(ListNode* l1,ListNode* l2)
	{
		if(l1==NULL)
			return l2;
		if(l2==NULL)
			return l1;
		ListNode* dummy = new ListNode; dummy->data = -1;
		ListNode*p =  dummy;
		for( ; l1!=NULL && l2!=NULL ; p=p->next)
		{
			if(l1->data > l2->data)
			{
				p->next=l2;
				l2=l2->next;
			}
			else
			{
				p->next=l1;
				l1=l1->next;
			}
		}             //l1 和l2其中一个结束了才跳出循环
		p->next = l1!=NULL ? l1: l2;//谁结束了就直接让谁连上  
		return dummy->next;
	}
//自己写的玩
	ListNode*mergeTwoLists2(ListNode* l1,ListNode* l2)
	{
		if(l1==NULL) return l2;
		if(l2==NULL) return l1;
		ListNode* dummy=new ListNode;
		ListNode* pNode = dummy;
		for( ; l1!=NULL&&l2!=NULL;  )
		{
			if(l1->data<l2->data)
			{
				pNode->next=l1;
				l1=l1->next;				 
			}
			else
			{
				pNode->next=l2;
				l2=l2->next;			
			}
			pNode=pNode->next;
		}
		if(l1!=NULL)
			pNode->next=l1;
		else
			pNode->next=l2; 
		return dummy->next;
	}
};







void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[4] = {3,4,5,6};

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
void Print(ListNode* L)
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
	 ListNode*l1;
	 creat(l1);

	 ListNode*l2;
	 creat(l2);
	 Solution s;
	 ListNode* L=s.mergeTwoLists2(l1,l2);
Print(L);


	return 0;
}

