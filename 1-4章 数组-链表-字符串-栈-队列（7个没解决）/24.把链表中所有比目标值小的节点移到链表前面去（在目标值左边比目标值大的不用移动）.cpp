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
		   ListNode* left_dummy  = new ListNode();  //开辟空间
		   ListNode* right_dummy = new ListNode();  //开辟空间  
		   ListNode* left_cur=  left_dummy;  //复制头节点
		   ListNode* right_cur=  right_dummy;//复制尾节点
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
		   left_cur->next=right_dummy->next; //连接两个子串
		   right_cur->next=NULL;
		   return left_dummy->next;
	   }

};

 


void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[9] = {1,2,3,4,5,4,3,2,1};

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
	creat(L);	Print(L);
	Solution s;
	ListNode* l = s.partition(L,4);
	Print(l);
	 

	return 0;
}

