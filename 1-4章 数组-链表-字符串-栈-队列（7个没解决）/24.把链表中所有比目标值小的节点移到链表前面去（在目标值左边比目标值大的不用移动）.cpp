#include<iostream>
using namespace std;


struct ListNode
	{
	int data;
	struct ListNode *next;
};    


class Solution
{
public:ListNode* partition(ListNode* head,int x)
	   {
		   ListNode* left_dummy  = new ListNode();  //���ٿռ�
		   ListNode* right_dummy = new ListNode();  //���ٿռ�  
		   ListNode* left_cur=  left_dummy;  //����ͷ�ڵ�
		   ListNode* right_cur=  right_dummy;//����β�ڵ�
		   ListNode* cur=head;
		   while( cur != NULL) 
		   { //cout<<"FUCK YOU!"<<endl;
			   if(cur->data < x){	   
				   left_cur->next=cur;
				   left_cur=cur;
			   }
			   else{		   
				   right_cur->next=cur;
				   right_cur=cur;
			   }
			   cur=cur->next;
		   }	
		   left_cur->next=right_dummy->next; //���������Ӵ�
		   right_cur->next=NULL;
		   return left_dummy->next;
	   }

};

 


void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[9] = {1,2,3,4,5,4,3,2,1};

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
	creat(L);	Print(L);
	Solution s;
	ListNode* l = s.partition(L,4);
	Print(l);
	 

	return 0;
}

