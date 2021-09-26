#include<iostream>
using namespace std;






struct ListNode
	{
	int data;
	struct ListNode *next;
};    



void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[9] = {1,1,3,3,4,4,5,5,6};

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




//给定头指针 和 一个节点指针 O(1) 删除该指针 


 void DeleteNode(ListNode* &L, ListNode* p)
 {
	 if(L== NULL || p==NULL)
	     return ;
	 if(p->next!=NULL)
	 {
		 ListNode* tmp = p->next;//将p的后面一个节点的值赋值到p节点上去  然后删掉p后面的节点
		 p->data = tmp->data;
		 p->next = tmp->next;
		  delete tmp;
		  tmp=NULL;
	 }
	 else if(L->next == NULL)//只一个头结点    头结点就是要删除的节点
	 {
		 delete p;
		 p=NULL;
		 L=NULL;
	 }
	 else//多个节点   要删除的节点是尾节点
	 {
		 ListNode* prev = L->next;
		 while(prev->next->next!=NULL)
		 {
			prev = prev->next;
		 }
		 prev->next=NULL;
		 delete p;
		 p = NULL;
	 }
 }



int main()
{
	 ListNode* L;
	 creat(L);
	 Print(L);
 	 ListNode *p = L->next->next->next->next->next->next->next->next->next  ;

DeleteNode(L,p);
cout<<"删除后："<<endl;
 Print(L);
	return 0;
}

