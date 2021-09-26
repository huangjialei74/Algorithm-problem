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
	for(int i=0; i<n; i++)//q后移n位
			q=q->next;
		while(q->next)//两个指针再后移动至   q到达末尾
		{
			p=p->next;
			q=q->next;
		}
	//	cout<<p->data<<endl;
		ListNode*tmp=p->next;
		p->next=p->next->next;//删掉p后面一个
		delete tmp;
		return dummy->next;
	}
};




void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[6] = {1,2,3,4,5,6};

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
	ListNode* L;
	creat(L);
//	Print(L);
 	Solution   s;
 	ListNode* l = s.removeNthFromEnd(L,3);
 	Print(l);




	 

	return 0;
}

