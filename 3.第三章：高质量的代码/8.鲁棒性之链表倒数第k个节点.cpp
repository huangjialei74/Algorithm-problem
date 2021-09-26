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

 
/*
k大于链表节点数 
k==0 
传入的是空指针
*/
ListNode* FindKthToTail(ListNode* pHead, unsigned int k)
{
	if(pHead==NULL || k==0)//k==0    传入的是空指针
		return NULL;
	ListNode*pAhead=pHead;
	ListNode*pBehind=NULL;
	for(unsigned int i=0; i<k-1; i++)
	{
		if(pAhead->next != NULL)
			pAhead=pAhead->next;
		else
			return NULL; //第一个指针走k-1步之前就到头了
	}
	pBehind = pHead;
	while(pAhead->next!=NULL)
	{
		pAhead=pAhead->next;
		pBehind=pBehind->next;
	}
	return pBehind;
}











int main()
{

 ListNode* L;
	 creat(L);
//	 Print(L);
	 ListNode *p=FindKthToTail(L,13);
	 if(p)
		 cout<<p->data<<endl;
	 else
		 cout<<"不存在"<<endl;

	 

	return 0;
}

