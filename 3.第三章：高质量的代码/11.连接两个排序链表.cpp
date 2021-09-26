#include<iostream>
using namespace std;
#include<list>
  

struct ListNode
	{
	int data;
	struct ListNode *next;
};    

 
  
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if(!pHead1)
		return pHead2;
	else if(!pHead2)
		return pHead1;
	ListNode* pMergedHead=NULL;
	if(pHead1->data < pHead2->data)
	{
		pMergedHead=pHead1;
		pMergedHead->next=Merge(pHead1->next, pHead2);//递归
	}
	else
	{
		pMergedHead=pHead2;
		pMergedHead->next=Merge(pHead1, pHead2->next);
	}
	return pMergedHead;

}



 
void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[5] = {1,2,3,4,5};

	 ListNode* p;//定义一个节点p 
	for( int i=5-1;i>=0;i--)
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
 ListNode*L ; 
 creat(L);
 ListNode*L2 ; 
 creat(L2);

ListNode* l=Merge(L,L2);
 Print(l);
 
  
	 

	return 0;
}

