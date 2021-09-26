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
			if(i<m-1) it1++;  //��it1ָ���m��,it2ָ���n��
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
		for(int i=0; i<m-1; ++i)//�ƶ�m-1�ε���Ŀ��λ�õ�ǰ1��
	     	prev=prev->next;  
		
		ListNode* const head2=prev;//head2����һ����Զ��prev
		prev = head2->next;//prev����Ŀ��λ��
		ListNode* cur=prev->next;//Ŀ��λ����һ��
		// head2, prev, cur
		for(int j=m; j<n; ++j)
		{
			prev->next=cur->next;//prev����һ��Ϊcur����һ��
			cur->next=head2->next;//cur����һ��Ϊhead2����һ��
			head2->next=cur;// head2����һ��Ϊ cur
		    cur=prev->next;// cur���� 
		}
		
		return dummy->next;
	}
 

 
};

void creat(	ListNode* &L)
{	
	 L=(ListNode*)malloc(sizeof(ListNode));  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[5] = {1,2,3,4,5};

	 ListNode* p;//����һ���ڵ�p 
	for( int i=5-1;i>=0;i--)
	{ 
		p=(ListNode*)malloc(sizeof(ListNode));
		p->data = a[i];
		p->next=L->next; 
		L->next=p; //ÿһ��ѭ������һ���ڵ�
	}
}

//���������
void Print (ListNode* L)
{
	ListNode* p;
	p=L;  //��P��ֵΪL 
	printf("�����е�Ԫ��:\n");
	while(p) 
	{
 	if(p->data > 0 )//ͷ�ڵ�
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

