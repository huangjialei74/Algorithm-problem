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
	 L=(ListNode*)malloc(sizeof(ListNode));  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[9] = {1,1,3,3,4,4,5,5,6};

	 ListNode* p;//����һ���ڵ�p 
	for( int i=sizeof(a)/sizeof(a[0])-1;i>=0;i--)
	{ 
		p=(ListNode*)malloc(sizeof(ListNode));
		p->data = a[i];
		p->next=L->next; 
		L->next=p; //ÿһ��ѭ������һ���ڵ�
	}
}

//���������
void Print (ListNode* L)
{
	ListNode* p;
	p=L;  //��P��ֵΪL 
	printf("�����е�Ԫ��:\n");
	while(p) 
	{
 	if(p->data > 0 )//ͷ�ڵ�
		cout<<p->data<<"  "; 
		p=p->next;
	}
	cout<<endl;
}

//���һ���ڵ�������ĩβ
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
//��ָɾ���ڵ�
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
		if(pNode->next != NULL && pNode->next->data == value)//������һ��whileѭ������ΪNULL������
		{
			pToBeDelete = pNode->next;//�õ�����ȥ�ͷ�
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

