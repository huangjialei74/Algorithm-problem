#include<iostream>
using namespace std;
 
#include<stack>

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

//添加一个节点至链表末尾
void AddToTailListNode(ListNode* &pHead, int value)
{
	ListNode *pNew = new ListNode();
	pNew->data = value;
	pNew->next = NULL;

	if( pHead == NULL)
	{
		  pHead = pNew;
	}
	else
	{
		ListNode *pNode =  pHead;
		while(pNode->next != NULL)		 
			pNode = pNode->next;
		 
		pNode->next = pNew;
	}
}
//按指删除节点
void Remove(ListNode * &pHead, int value)
{
	if(pHead == NULL)
		return ;
	ListNode *pToBeDelete = NULL;
	if(pHead->data == value)
	{
         pToBeDelete = pHead;
		 pHead = pHead->next;
	}
	else
	{
		ListNode *pNode = pHead;
		while(pNode->next != NULL && pNode->next->data != value)
		{
			pNode = pNode->next;
		}
		if(pNode->next != NULL && pNode->next->data == value)//可能上一个while循环是因为NULL结束的
		{
			pToBeDelete = pNode->next;//拿到外面去释放
			pNode->next = pNode->next->next;
		}
	}
	if(pToBeDelete != NULL)
	{
		delete pToBeDelete;
		pToBeDelete = NULL;
	}


}
void PrintListReversingly(ListNode * pHead )
{
	stack<ListNode *>nodes;
	ListNode*pNode = pHead;
	while(pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->next;
	}
	while(!nodes.empty())
	{
		pNode=nodes.top();
		cout<<pNode->data<<"  ";
		nodes.pop();
	}
	cout<<endl;
}
void PrintListReversingly2(ListNode * pHead )
{
	if(pHead != NULL)
	{
		if(pHead->next != NULL)
		{
			PrintListReversingly2(pHead->next);
		}
		cout<<pHead->data<<"  ";
	}
}
 

int main()
{
	 	
	ListNode* L;
	L = NULL;
 	creat(L); 
  /*
 	AddToTailListNode(L,100);
    Print(L); 

	Remove(L,6);
	 Print(L); 
*/


	 PrintListReversingly2(L);



free(L);  
 

	return 0;
}

