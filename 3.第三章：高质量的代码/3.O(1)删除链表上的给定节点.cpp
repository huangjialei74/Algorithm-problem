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




//����ͷָ�� �� һ���ڵ�ָ�� O(1) ɾ����ָ�� 


 void DeleteNode(ListNode* &L, ListNode* p)
 {
	 if(L== NULL || p==NULL)
	     return ;
	 if(p->next!=NULL)
	 {
		 ListNode* tmp = p->next;//��p�ĺ���һ���ڵ��ֵ��ֵ��p�ڵ���ȥ  Ȼ��ɾ��p����Ľڵ�
		 p->data = tmp->data;
		 p->next = tmp->next;
		  delete tmp;
		  tmp=NULL;
	 }
	 else if(L->next == NULL)//ֻһ��ͷ���    ͷ������Ҫɾ���Ľڵ�
	 {
		 delete p;
		 p=NULL;
		 L=NULL;
	 }
	 else//����ڵ�   Ҫɾ���Ľڵ���β�ڵ�
	 {
		 ListNode* prev = L->next;
		 while(prev->next->next!=NULL)
		 {
			prev = prev->next;
		 }
		 prev->next=NULL;
		 delete p;
		 p = NULL;
	 }
 }



int main()
{
	 ListNode* L;
	 creat(L);
	 Print(L);
 	 ListNode *p = L->next->next->next->next->next->next->next->next->next  ;

DeleteNode(L,p);
cout<<"ɾ����"<<endl;
 Print(L);
	return 0;
}

