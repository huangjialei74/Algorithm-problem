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
	 L=(ListNode*)malloc(sizeof(ListNode));  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[5] = {1,2,3,4,5};

	 ListNode* p;//����һ���ڵ�p 
	for( int i=5-1;i>=0;i--)
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
	else
		cout<<"��ֵ"<<" ";
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
	//�õ���������ĳ���
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

