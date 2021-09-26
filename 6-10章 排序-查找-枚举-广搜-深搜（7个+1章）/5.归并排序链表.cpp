#include<iostream>
using namespace std;


struct ListNode
	{
	int data;
	struct ListNode *next;
}; 
 

// O(nlogn) O(1)
class Solution
{
public:
	ListNode* sortList(ListNode* head)
	{
		if(head==NULL||head->next==NULL)
			return head;
		//����ָ���ҵ��м�ڵ�
		ListNode*fast=head, *slow=head;
		while(fast->next!=NULL && fast->next->next!=NULL)//����ֻfast!=NULLΪ����  
		{
			fast=fast->next->next;
			slow=slow->next;
		}
		//�Ͽ�
		fast=slow;
		slow=slow->next;
		fast->next=NULL;
		ListNode*l1=sortList(head);//ǰ�������  �ݹ����Ѹ�������һ�Զԣ�����Ϊ1ʱֱ�ӷ��أ� ����һ���ڵ������ �ٽ��кϲ�  �ݹ����
		ListNode*l2=sortList(slow);//��������
		return mergeTwoLists(l1,l2);
	}
	 
     //�ϲ�������������ĺ��� 
	//Merge Two Sorted Lists
	ListNode* mergeTwoLists(ListNode*l1, ListNode*l2)
	{
		ListNode *dummy = new ListNode; dummy->data =-1;
		for(ListNode*p= dummy; l1!=NULL||l2!=NULL; p=p->next)
		{
			int val1=  l1==NULL ? INT_MAX: l1->data;
			int val2=  l2==NULL ? INT_MAX: l2->data;
			if(val1<=val2)
			{
				p->next=l1;
				l1=l1->next;			
			}
			else
			{
				p->next=l2;
				l2=l2->next;
			}
		}
		return dummy->next;
	}
	 
};

 

void creat(	ListNode* &L)
{	
	 L=new ListNode ;  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[6] = {3,3,3,6,4,7};

	 ListNode* p;//����һ���ڵ�p 
	for( int i=sizeof(a)/sizeof(a[0])-1;i>=0;i--)
	{ 
		p=new ListNode ;
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

	 Solution s;
	 ListNode* L2 = s.sortList(L);
	 cout<<"�����"<<endl;
	 Print(L2);

	 

	return 0;
}

