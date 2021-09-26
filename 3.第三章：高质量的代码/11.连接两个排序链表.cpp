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
		pMergedHead->next=Merge(pHead1->next, pHead2);//�ݹ�
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

