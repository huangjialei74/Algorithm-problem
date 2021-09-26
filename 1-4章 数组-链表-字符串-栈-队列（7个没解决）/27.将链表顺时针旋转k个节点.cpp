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
	ListNode* rotateRight(ListNode* head,int k)//k������Ϊ����
	{
		if(head==NULL||k==0)
			return head;

		int len=1;
		ListNode*p = head;
		while(p->next)
		{
			len++;//��¼����
			p=p->next;
		}

		k=len-k%len;//���k=k%len�Ǿ�����ʱ����ת

		p->next=head;//��β�ͽӵ�ͷ��ȥ------�ɻ�    
		for(int step=0; step<k; step++)
		{ 
			p=p->next;
		}
		head=p->next;  //p-2   head-3    �ϵ�2����
		p->next=NULL;//head  3 4 5 1 2 NULL;
		return head;
	}
};


void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[10] = {1,2,3,4,5,6,7,8,9,0};

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
 	if(p->data >= 0 )//ͷ�ڵ�
		cout<<p->data<<"  "; 
		p=p->next;
	}
	cout<<endl;
}







int main()
{
	ListNode* L;
	creat(L);
 	Print(L);
 	Solution   s;
 	ListNode* l = s.rotateRight2(L,-3);
 	Print(l);




	 

	return 0;
}

