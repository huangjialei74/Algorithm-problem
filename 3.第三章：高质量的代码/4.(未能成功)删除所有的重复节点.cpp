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
		 if(!needDelete)//����Ҫɾ
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
cout<<"ɾ����"<<endl;
 Print(*p); 
 //delete *p;
 //delete p;
	return 0;
}

