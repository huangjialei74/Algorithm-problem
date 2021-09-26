#include<iostream>
using namespace std;



struct ListNode
	{
	int data;
	struct ListNode *next;
};    

//递归 都是O(n)    O(1)
class Solution
{
public:ListNode* deleteDuplicates(ListNode* head)
	   {
		   if(head == NULL)
			   return head;
		   ListNode* dummy = (ListNode*)malloc(sizeof(ListNode)); 
		   dummy->data = head->data + 1 ;     dummy->next=head;
		   recur( dummy,head);//当前指针 和下一个指针
		   return dummy->next;
	   }
private:static void recur(ListNode* prev,ListNode* cur)
		{
			if(cur==NULL)
				return;
			if(prev->data == cur->data)
			{
				prev->next = cur->next;
				delete cur;
				recur(prev,prev->next);//prev和prev的新的下一个
			}
			else{
				recur(prev->next,cur->next);//都往后挪一个
			}
		}
};


//迭代  
 
class Solution2
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
	      if(head == NULL)
			   return head;
		for(ListNode* prev=head,*cur=head->next;  cur != NULL;  )//一个指向头 一个字指向第一个
		{
			if(prev->data==cur->data)
			{
				prev->next=cur->next;
				delete cur;
			}
			else{
				prev=cur;
			}
			cur=prev->next;
		}
		return head;
	}
};
 






void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[9] = {1,1,3,3,4,4,5,5,6};

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
	Solution2 s;
	ListNode* l = s.deleteDuplicates(L);
	Print(l);




	 

	return 0;
}

