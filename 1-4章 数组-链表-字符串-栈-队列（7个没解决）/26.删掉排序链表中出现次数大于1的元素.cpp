#include<iostream>
using namespace std;



struct ListNode
	{
	int data;
	struct ListNode *next;
}; 

  
//递归
class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if(!head||!head->next)
			return head;

		 ListNode*p=head->next;//p在head下一个
		 if(head->data==p->data)
		 {
			 while(p && head->data==p->data)//这里是while循环 会把和head值相同的后面的节点全部删掉
			 { 
				 ListNode*tmp=p;
				 p=p->next; 
				 delete tmp; //先删head后面的
			 } 
			 delete head; // 再删掉 head 
			 return deleteDuplicates(p);
		 }
		 else
		 {
			 head->next = deleteDuplicates(head->next);
			 return head;
		 }
	}
 
};

//迭代
class Solution2
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if(head == NULL )
			return head;
		ListNode* dummy = new ListNode();
		dummy->next = head;
		ListNode*  prev = dummy, *cur = head; //prev指向head前一个   cur指向head
		while(cur!= NULL)
		{
			bool duplicated=false;
			while( cur->next != NULL && cur->data==cur->next->data)//while循环 会把和head值相同的后面的节点全部删掉
			{ 
				duplicated=true;
				ListNode*temp=cur;
				cur=cur->next;
				delete temp;
			}
			if(duplicated)//再删掉第一个节点
			{
				ListNode*temp=cur;
				cur=cur->next;
				delete temp;
				continue; //当cur与cur->next相等时， 删掉这些节点   cur不添加到prev后面，（因为后面的节点，可能值也相等）
			}
			prev->next=cur;// 当cur与cur->next不相等时--------添加节点cur在prev后面  
			prev=prev->next;//prev后移----为下一次再添加节点   
			cur=cur->next; //cur后移 
		}
		prev->next=cur;//尾节点NULL
		return dummy->next;
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
	ListNode* L;
	creat(L);
//	Print(L); 
	Solution2  s;
	ListNode* l = s.deleteDuplicates2(L);
	Print(l);




	 

	return 0;
}

