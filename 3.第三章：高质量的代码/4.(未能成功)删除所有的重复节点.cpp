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

 



 void DeleteNode(ListNode **L )
 {
	 if(L== NULL || *L==NULL)
	     return ;
	 ListNode *prev = NULL;
	 ListNode *pNode = *L;
	 
	 while(pNode != NULL)
	 {
		 ListNode *pNext =pNode->next;
		 bool needDelete =false;
		 if(pNext != NULL && pNode->data==pNext->data)
		 {
			 needDelete =true;
		 }
		 if(!needDelete)//不需要删
		 {
			 prev = pNode;
			 pNode = pNode->next;
		 }
		 else
		 {
			 int value = pNode->data;
			 ListNode *pToBeDel = pNode;
			 while(pToBeDel != NULL && pToBeDel->data==value )
			 {
				 pNext = pToBeDel->next;
				 delete pToBeDel ;
				 pToBeDel  = NULL;
				 pToBeDel  = pNext;
			 }
			 if(prev == NULL)
		    	 *L = pNext;
			 else
				 prev->next = pNext;
			 pNode = pNext;
		 }
	 }
 }



int main()
{
	 ListNode* L;
	 creat(L);
	 Print(L);
	 ListNode **p ;
	 *p =  L->next;
 
DeleteNode(p);
cout<<"删除后："<<endl;
 Print(*p); 
 //delete *p;
 //delete p;
	return 0;
}

