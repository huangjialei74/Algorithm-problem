#include<iostream>
using namespace std;
#include<list>
  

struct ListNode
	{
	int data;
	struct ListNode *next;
};    
 
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


unsigned int GetListLength(ListNode* pHead)
{
	unsigned int nLength=0;
	ListNode* pNode=pHead;
	while(pNode!=NULL)
	{
		++nLength;
		pNode=pNode->next;
	}
	return nLength;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	//得到两个链表的长度
	unsigned int nLength1 = GetListLength(pHead1);
	unsigned int nLength2 = GetListLength(pHead2);

	ListNode* pListHeadLong = pHead1;
	ListNode* pListHeadShort = pHead2;
	if(nLength2 > nLength1)
	{
		pListHeadLong =  pHead2;
		pListHeadShort = pHead1;
		nLengthDif = nLength2-nLength1;
	}
	for(int i=0; i<nLengthDif; i++)
		pListHeadLong = pListHeadLong->next;
	while((pListHeadLong != NULL)&&(pListHeadShort != NULL)&&(pListHeadLong != pListHeadShort))
	{
		pListHeadLong = pListHeadLong->next;
		pListHeadShort = pListHeadShort->next;
	}
	ListNode * pFirstCommonNode=pListHeadShort;
	return pFirstCommonNode;
}


int main()
{ 

	return 0;
}

