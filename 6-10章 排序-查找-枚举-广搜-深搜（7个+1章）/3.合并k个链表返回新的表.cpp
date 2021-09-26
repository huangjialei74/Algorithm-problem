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
			p=mergeTwoLists(p,lists[i]);//����������ϲ�����һ����  
		}
		return p;
	}
	 ListNode* mergeTwoLists(ListNode*l1, ListNode*l2)
	 {
		 ListNode* head =  new ListNode; head->data = -1;
		 for(ListNode*p= head; l1!=NULL||l2!=NULL; p=p->next)
		 {
			int val1= l1==NULL? INT_MAX: l1->data;//������||�������������   ��Ӧ��valΪINT_MAX���ᱻ��������
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
	 L=(ListNode*)malloc(sizeof(ListNode));  //���ٿռ�  
	  L->next=NULL;//��ָ����Ϊ��
	int a[4] = {3,3,3,6};

	 ListNode* p;//����һ���ڵ�p 
	for( int i=sizeof(a)/sizeof(a[0])-1;i>=0;i--)
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
	 

	return 0;
}

