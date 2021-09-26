#include<iostream>
using namespace std;
#include<vector>



struct ListNode
	{
	int data;
	struct ListNode *next;
}; 



class Solution
{
public:
	ListNode*mergeKLists(vector<ListNode*>&lists)
	{
		if(lists.size()==0)
			return NULL;
		ListNode*p=lists[0];
		for(int i=1; i<lists.size(); i++)
		{
			p=mergeTwoLists(p,lists[i]);//把所有链表合并到第一条上  
		}
		return p;
	}
	 ListNode* mergeTwoLists(ListNode*l1, ListNode*l2)
	 {
		 ListNode* head =  new ListNode; head->data = -1;
		 for(ListNode*p= head; l1!=NULL||l2!=NULL; p=p->next)
		 {
			int val1= l1==NULL? INT_MAX: l1->data;//上面是||那条链表结束了   对应的val为INT_MAX不会被插入链表
			 int val2= l2==NULL? INT_MAX: l2->data;
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
		 return head->next;
	 }
};




void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[4] = {3,3,3,6};

	 ListNode* p;//定义一个节点p 
	for( int i=sizeof(a)/sizeof(a[0])-1;i>=0;i--)
	{ 
		p=(ListNode*)malloc(sizeof(ListNode));
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
	 

	return 0;
}

