#include<iostream>
using namespace std;


struct ListNode
	{
	int data;
	struct ListNode *next;
}; 
 


// O(n^2)  O(1)
class Solution
{
public:
	ListNode*insertionSortList(ListNode* head)//123321
	{
		ListNode*  dummy = new ListNode; 
		dummy->data = INT_MIN;
		for(ListNode*cur=head->next; cur!=NULL; )//cur��������Խ��Խ�̣� dummyԽ��Խ��
		{
			ListNode*  pos=findInsertPos(dummy,cur->data);
			ListNode* tmp=cur->next;
			cur->next=pos->next;//��cur��ԭ�����жϿ�
			pos->next=cur;
			cur=tmp;//����
		}
		return dummy->next;
	}
	//�޷���ֵ ��ԭ��������޸�
	void insertionSortList2(ListNode* &head)//3,3,1,2,7,4,6,3,6,4
	{
		if(head==NULL||head->next==NULL)
	         return ;
		for(ListNode*prev=head->next, *cur=prev->next; cur!=NULL ; )//cur�ӵڶ����ڵ㿪ʼ
		{
			if(prev->data<=cur->data)//����ʱ����Ҫ����
			{
				prev=prev->next;
				cur=prev->next;
				continue;
			}
			ListNode*  pos=findInsertPos(head,cur->data);
		//	cout<<cur->data<<"����"<<pos->data<<"����"<<endl;

            prev->next=cur->next;//�ں���ɾ��cur
			cur->next=pos->next;//��cur�嵽ǰ��ȥ 
			pos->next=cur;    
			
			cur=prev->next;  //cur�ƶ�
		} 
	}

	ListNode* findInsertPos(ListNode*head, int x)//ȡ С�ڻ����x��  �����ֵ�Ľڵ�
	{
		ListNode*pre=NULL;
		for(ListNode*cur=head;  cur!=NULL && cur->data<=x;  pre=cur,cur=cur->next);  
		   return pre;
	}
 
 
};


 

void creat(	ListNode* &L)
{	
	 L=new ListNode ;  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[10] = {3,3,1,2,7,4,6,3,6,4};

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
	    s.insertionSortList2(L);
  Print(L);

	 

	return 0;
}

