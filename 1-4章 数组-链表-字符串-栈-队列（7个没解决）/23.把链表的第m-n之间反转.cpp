#include<iostream>
using namespace std;
#include<list>
 


class Solution1
{
public:
	list<int> reverseBetween(list<int>l, int m,int n)
	{
	    list<int>::iterator it1 =l.begin(), it2 = l.begin();
		for(int i = 0; i< n-1  ;i++)
		{ 
			if(i<m-1) it1++;  //让it1指向第m个,it2指向第n个
              it2++;		
		} //cout<<(*it1)<<(*it2)<<endl;
		for( ; it1 != it2; it1++,it2--)
		{ 
			int temp = (*it1);	 
			*it1 = *it2;
			*it2 = temp;		 
		}	 
		return l;
	}
};



struct ListNode
	{
	int data;
	struct ListNode *next;
};    

class Solution2
{
public:
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{ 
		ListNode* dummy = new ListNode();   dummy->data=-1;
		dummy->next=head;
 
		ListNode* prev = dummy; 
		for(int i=0; i<m-1; ++i)//移动m-1次到达目标位置的前1个
	     	prev=prev->next;  
		
		ListNode* const head2=prev;//head2后面一个永远是prev
		prev = head2->next;//prev到达目标位置
		ListNode* cur=prev->next;//目标位置下一个
		// head2, prev, cur
		for(int j=m; j<n; ++j)
		{
			prev->next=cur->next;//prev的下一个为cur的下一个
			cur->next=head2->next;//cur的下一个为head2的下一个
			head2->next=cur;// head2的下一个为 cur
		    cur=prev->next;// cur后移 
		}
		
		return dummy->next;
	}
 

 
};

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
		p=p->next;
	}
	cout<<endl;
}


int main()
{

	/*
	list<int>l;
	l.push_back(1);  l.push_back(2); l.push_back(3);l.push_back(4); l.push_back(5);
	Solution s;
	list<int>retu = s.reverseBetween(l,2,4); 

 	for( list<int>::iterator it =retu.begin(); it != retu.end();it++) cout<<(*it)<<" ";
*/
	
	
 ListNode*L ; 
 creat(L);
 Print(L);
 
 
    Solution2 s2;
	ListNode *l = s2.reverseBetween2(L,3,6);
	Print(l); 
	 

	return 0;
}

