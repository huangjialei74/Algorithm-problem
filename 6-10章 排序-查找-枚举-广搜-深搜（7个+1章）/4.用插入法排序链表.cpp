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
		for(ListNode*cur=head->next; cur!=NULL; )//cur那条链表越来越短， dummy越来越长
		{
			ListNode*  pos=findInsertPos(dummy,cur->data);
			ListNode* tmp=cur->next;
			cur->next=pos->next;//把cur从原链表中断开
			pos->next=cur;
			cur=tmp;//后移
		}
		return dummy->next;
	}
	//无返回值 对原链表进行修改
	void insertionSortList2(ListNode* &head)//3,3,1,2,7,4,6,3,6,4
	{
		if(head==NULL||head->next==NULL)
	         return ;
		for(ListNode*prev=head->next, *cur=prev->next; cur!=NULL ; )//cur从第二个节点开始
		{
			if(prev->data<=cur->data)//递增时不需要插入
			{
				prev=prev->next;
				cur=prev->next;
				continue;
			}
			ListNode*  pos=findInsertPos(head,cur->data);
		//	cout<<cur->data<<"放在"<<pos->data<<"后面"<<endl;

            prev->next=cur->next;//在后面删掉cur
			cur->next=pos->next;//把cur插到前面去 
			pos->next=cur;    
			
			cur=prev->next;  //cur移动
		} 
	}

	ListNode* findInsertPos(ListNode*head, int x)//取 小于或等于x中  的最大值的节点
	{
		ListNode*pre=NULL;
		for(ListNode*cur=head;  cur!=NULL && cur->data<=x;  pre=cur,cur=cur->next);  
		   return pre;
	}
 
 
};


 

void creat(	ListNode* &L)
{	
	 L=new ListNode ;  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[10] = {3,3,1,2,7,4,6,3,6,4};

	 ListNode* p;//定义一个节点p 
	for( int i=sizeof(a)/sizeof(a[0])-1;i>=0;i--)
	{ 
		p=new ListNode ;
		p->data = a[i];
		p->next=L->next; 
		L->next=p; //每一次循环插入一个节点
	}
}

//输出单链表
void Print (ListNode* L)
{
	ListNode* p;
	p=L;  //让P赋值为L 
	printf("链表中的元素:\n");
	while(p) 
	{
 	if(p->data > 0 )//头节点
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

