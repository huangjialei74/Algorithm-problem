#include<iostream>
using namespace std;



struct ListNode
	{
	int data;
	struct ListNode *next;
	struct ListNode *random;
}; 

  //O(n)   O(1) 
/*
��ԭ�����ÿ�����ڵ�֮���һ��node�ڵ� ֵ��ǰ��һ����ͬ
�����ڵ���漴ָ�뱻��ֵΪ��һ��ѭ���������Ľڵ��random
���2 ������
*/
 class Solution
 {
 public:
	 ListNode* copyRandomList(ListNode* head)
	 {
		 ListNode*cur=head;
		 for(; cur!=NULL; )
		 {
			 ListNode* node=new ListNode;   	 node->data =  cur->data;
			 node->next = cur->next;		 cur->next=node;//��ÿ�����ڵ�֮���һ��node�ڵ� ֵ��ǰ��һ����ͬ
			 cur=node->next; //cur�ƶ�
		 } 
		
		 for( cur=head; cur!= NULL;  cur=cur->next->next )
		 {
			 if(cur->random != NULL){ 
				 cur->next->random = cur->random->next; //cur->random->next ��ֵΪ��һ��ѭ���������Ľڵ��random
			 } 			 
		 }
	       		 
		  ListNode *new_cur, *dummy = new ListNode;
		  for( cur=head, new_cur = dummy; cur!= NULL; cur = cur->next)
		  {
			  new_cur->next = cur->next;//cur�ĺ������ǵڶ�������Ľڵ� ��new_curָ����
			  new_cur = new_cur->next; //new_cur�����ƶ�  Ŀ����ָ����һ���ڶ�������Ľڵ�
			  cur->next = cur->next->next;  //�ص����м���Ǹ����ڵڶ�������Ľڵ�
		  } 
		  return dummy->next;
	 }
	  
 };

 

void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	  L->random = NULL;
	int a[6] = {1,2,3,4,5,6};

	 ListNode* p;//����һ���ڵ�p 
	for( int i=sizeof(a)/sizeof(a[0])-1;i>=0;i--)
	{ 
		p=(ListNode*)malloc(sizeof(ListNode));
		p->data = a[i];
		 p->random = NULL;
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
 	Print(L);
	Solution   s;
	ListNode* l = s.copyRandomList(L);
 	Print(l);




	 

	return 0;
}

