#include<iostream>
using namespace std;



struct ListNode
	{
	int data;
	struct ListNode *next;
}; 

  //O(n)   O(1)
  //�ݹ�
class Solution
{
public:
	ListNode* reverseKGroup(ListNode*head, int k)
	{
		if(head==NULL||head->next==NULL||k<2)
			return head;
 
		ListNode* 	next_group  = head;
		for(int i=0; i<k; ++i)
		{
			if(next_group)
				next_group = next_group->next;
			else
				return head;// ����ڵ�������K��
		}  //next_group����һ�������ͷ   new_next_group�Ƿ�ת֮��������ͷ 
 
		ListNode* new_next_group = reverseKGroup(next_group, k);//�ݹ�  ��תʣ�²���
		ListNode*prev = NULL, *cur=head;

		while(cur != next_group)
		{
			/*
			cur�����ò��ֵ����нڵ㣬ÿ�ν�prev(�ʼ��new_next_group)����cur���棬Ȼ��cur��ֵ��prev�� 
			ÿ�β���cur��ָ�Ľڵ㵽prev���棬��ͷ�壩  ʵ������
			*/
			ListNode *next = cur->next;//��¼��תǰcur�����һ���ڵ�   cur->next  һ�����ֵ��cur
			cur->next = prev ? prev: new_next_group; 
			prev=cur;
			cur=next;
		}
		return prev;// cur�������һ���ڵ�   cur��ֵ��prev    cur��ΰ��
	}
 
};








 
 
void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[8] = {1,2,3,4,5,6,7,8};

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
	else
		cout<<"��ֵ"<<" ";
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
  	ListNode* l = s.reverseKGroup(L,4);
 	Print(l);




	 

	return 0;
}

