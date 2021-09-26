#include<iostream>
using namespace std;


struct ListNode
	{
	int data;
	struct ListNode *next;
}; 
 

// O(nlogn) O(1)
class Solution
{
public:
	ListNode* sortList(ListNode* head)
	{
		if(head==NULL||head->next==NULL)
			return head;
		//快慢指针找到中间节点
		ListNode*fast=head, *slow=head;
		while(fast->next!=NULL && fast->next->next!=NULL)//不能只fast!=NULL为条件  
		{
			fast=fast->next->next;
			slow=slow->next;
		}
		//断开
		fast=slow;
		slow=slow->next;
		fast->next=NULL;
		ListNode*l1=sortList(head);//前半段排序  递归至把该链表拆成一对对（长度为1时直接返回） 各含一个节点的链表 再进行合并  递归回来
		ListNode*l2=sortList(slow);//后半段排序
		return mergeTwoLists(l1,l2);
	}
	 
     //合并两个排序链表的函数 
	//Merge Two Sorted Lists
	ListNode* mergeTwoLists(ListNode*l1, ListNode*l2)
	{
		ListNode *dummy = new ListNode; dummy->data =-1;
		for(ListNode*p= dummy; l1!=NULL||l2!=NULL; p=p->next)
		{
			int val1=  l1==NULL ? INT_MAX: l1->data;
			int val2=  l2==NULL ? INT_MAX: l2->data;
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
		return dummy->next;
	}
	 
};

 

void creat(	ListNode* &L)
{	
	 L=new ListNode ;  //开辟空间  
	  L->next=NULL;//其指针域为空
	int a[6] = {3,3,3,6,4,7};

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
	 ListNode* L2 = s.sortList(L);
	 cout<<"排序后："<<endl;
	 Print(L2);

	 

	return 0;
}

