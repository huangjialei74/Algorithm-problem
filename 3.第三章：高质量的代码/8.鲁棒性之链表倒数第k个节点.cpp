#include<iostream>
using namespace std;


 



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

 
/*
k��������ڵ��� 
k==0 
������ǿ�ָ��
*/
ListNode* FindKthToTail(ListNode* pHead, unsigned int k)
{
	if(pHead==NULL || k==0)//k==0    ������ǿ�ָ��
		return NULL;
	ListNode*pAhead=pHead;
	ListNode*pBehind=NULL;
	for(unsigned int i=0; i<k-1; i++)
	{
		if(pAhead->next != NULL)
			pAhead=pAhead->next;
		else
			return NULL; //��һ��ָ����k-1��֮ǰ�͵�ͷ��
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
		 cout<<"������"<<endl;

	 

	return 0;
}

