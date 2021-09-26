#include<iostream>
using namespace std;



struct ListNode
	{
	int data;
	struct ListNode *next;
}; 

  
 
//O(n)   O(1)

class Solution{
public:
	ListNode* removeNthFromEnd(ListNode*head,int n)
	{
		ListNode*dummy = head;
		ListNode*p = dummy, *q = dummy;
	for(int i=0; i<n; i++)//q����nλ
			q=q->next;
		while(q->next)//����ָ���ٺ��ƶ���   q����ĩβ
		{
			p=p->next;
			q=q->next;
		}
	//	cout<<p->data<<endl;
		ListNode*tmp=p->next;
		p->next=p->next->next;//ɾ��p����һ��
		delete tmp;
		return dummy->next;
	}
};




void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[6] = {1,2,3,4,5,6};

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







int main()
{
	ListNode* L;
	creat(L);
//	Print(L);
 	Solution   s;
 	ListNode* l = s.removeNthFromEnd(L,3);
 	Print(l);




	 

	return 0;
}

