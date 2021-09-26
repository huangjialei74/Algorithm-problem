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
	ListNode* rotateRight(ListNode* head,int k)//k还可以为负数
	{
		if(head==NULL||k==0)
			return head;

		int len=1;
		ListNode*p = head;
		while(p->next)
		{
			len++;//记录长度
			p=p->next;
		}

		k=len-k%len;//如果k=k%len那就是逆时针旋转

		p->next=head;//把尾巴接到头上去------成环    
		for(int step=0; step<k; step++)
		{ 
			p=p->next;
		}
		head=p->next;  //p-2   head-3    断掉2后面
		p->next=NULL;//head  3 4 5 1 2 NULL;
		return head;
	}
};


void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[10] = {1,2,3,4,5,6,7,8,9,0};

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
 	if(p->data >= 0 )//头节点
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

