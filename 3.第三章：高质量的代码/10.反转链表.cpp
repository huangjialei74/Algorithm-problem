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

 

//三指针
	ListNode* reverse1(ListNode* head)
	{ 
		ListNode* dummy = new ListNode();   dummy->data=head->data+1;
		dummy->next=head;
 
		ListNode* prev = dummy;  
		ListNode* const head2=prev;//head2后面一个永远是prev
		prev = head2->next;//prev到达目标位置
		ListNode* cur=prev->next;//目标位置下一个
		// head2, prev, cur
		for( ; cur; )
		{
			prev->next=cur->next;//prev的下一个为cur的下一个
			cur->next=head2->next;//cur的下一个为head2的下一个
			head2->next=cur;// head2的下一个为 cur
		    cur=prev->next;// cur后移 
		}		
		return dummy->next;
	}

	
//剑指上的三指针--类似于头插
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


//头插
	ListNode* reverse2(ListNode *head)
	{
		if(head==NULL || head->next==NULL)
			return head;
		ListNode*prev=head;
		/*
		cur遍历该部分的所有节点，每次将prev放在cur后面，然后cur赋值给prev， 
		每次插入cur所指的节点到prev后面，（头插）  实现逆序
		*/
		for(ListNode*cur=head->next, *next=cur->next;  
		cur;
		prev=cur, cur=next, next=next?next->next:NULL)//cur=next后移
		{
			cur->next=prev;
		}
		head->next=NULL;
		return prev;
	}

/*与头插很相似

	ListNode* reverse3(ListNode *head)
	{
		if(head==NULL || head->next==NULL)
			return head;
	    ListNode*prev = NULL, *cur=head;
		while(cur)
		{
			//在循环的里面每次定义一个节点 保存cur->next  上面则是在循环开始时定义一个cur后面的节点next			 
			ListNode *next = cur->next;//记录反转前cur后面的一个节点   cur->next  一会儿赋值给cur
			cur->next = prev; 
			prev=cur;
			cur=next;
		}
		return prev;// cur后面跟着一串节点   cur赋值给prev    cur好伟大
	}
*/




 
void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[5] = {1,2,3,4,5};

	 ListNode* p;//定义一个节点p 
	for( int i=5-1;i>=0;i--)
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
	else
		cout<<"无值"<<" ";
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

