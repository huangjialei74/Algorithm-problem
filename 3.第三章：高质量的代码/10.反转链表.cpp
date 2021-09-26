#include<iostream>
using namespace std;
#include<list>
 

 /*
	list<int> reverse0(list<int>l)
	{
	    list<int>::iterator it1 =l.begin(), it2 = l.begin();
	
		for( ; it1 != it2; it1++,it2--)
		{ 
			int temp = (*it1);	 
			*it1 = *it2;
			*it2 = temp;		 
		}	 
		return l;
	}
*/


struct ListNode
	{
	int data;
	struct ListNode *next;
};    

 

//��ָ��
	ListNode* reverse1(ListNode* head)
	{ 
		ListNode* dummy = new ListNode();   dummy->data=head->data+1;
		dummy->next=head;
 
		ListNode* prev = dummy;  
		ListNode* const head2=prev;//head2����һ����Զ��prev
		prev = head2->next;//prev����Ŀ��λ��
		ListNode* cur=prev->next;//Ŀ��λ����һ��
		// head2, prev, cur
		for( ; cur; )
		{
			prev->next=cur->next;//prev����һ��Ϊcur����һ��
			cur->next=head2->next;//cur����һ��Ϊhead2����һ��
			head2->next=cur;// head2����һ��Ϊ cur
		    cur=prev->next;// cur���� 
		}		
		return dummy->next;
	}

	
//��ָ�ϵ���ָ��--������ͷ��
ListNode* reverse0(ListNode* pHead)
{
	ListNode* pReversedHead=NULL;
	ListNode* pNode=pHead;
	ListNode* pPrev=NULL;
	while(pNode)
	{
		ListNode* pNext=pNode->next;
		if(!pNext)
			pReversedHead=pNode;
		pNode->next=pPrev;

		pPrev=pNode;
		pNode=pNext;
	}
	return pReversedHead;
}


//ͷ��
	ListNode* reverse2(ListNode *head)
	{
		if(head==NULL || head->next==NULL)
			return head;
		ListNode*prev=head;
		/*
		cur�����ò��ֵ����нڵ㣬ÿ�ν�prev����cur���棬Ȼ��cur��ֵ��prev�� 
		ÿ�β���cur��ָ�Ľڵ㵽prev���棬��ͷ�壩  ʵ������
		*/
		for(ListNode*cur=head->next, *next=cur->next;  
		cur;
		prev=cur, cur=next, next=next?next->next:NULL)//cur=next����
		{
			cur->next=prev;
		}
		head->next=NULL;
		return prev;
	}

/*��ͷ�������

	ListNode* reverse3(ListNode *head)
	{
		if(head==NULL || head->next==NULL)
			return head;
	    ListNode*prev = NULL, *cur=head;
		while(cur)
		{
			//��ѭ��������ÿ�ζ���һ���ڵ� ����cur->next  ����������ѭ����ʼʱ����һ��cur����Ľڵ�next			 
			ListNode *next = cur->next;//��¼��תǰcur�����һ���ڵ�   cur->next  һ�����ֵ��cur
			cur->next = prev; 
			prev=cur;
			cur=next;
		}
		return prev;// cur�������һ���ڵ�   cur��ֵ��prev    cur��ΰ��
	}
*/




 
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
 Print(L);
 
 
	ListNode *l = reverse2(L);
	Print(l); 

	 

	return 0;
}

