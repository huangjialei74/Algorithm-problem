#include<iostream>
using namespace std;

/*
方法一：分两步， 复制原始链表上每个节点， 用m_pNext连接起来，  第二步设置每个节点的m_pSibling指针，定位s的时候从原始链表的头结点开始找。时间复杂度O(n2)
方法二：分两步， 第一步时把<N,N'>的配对信息存在哈希表里面  第二步时 可以在O(1)时间内找到O(n)
方法三：分三步，第一步把原链表每个节点复制并插入到其后面， 第二步设置复制出来的节点的s指针 ，第三步拆开两个链表
*/


struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;//指向链表中的任意节点 或者NULL
};

//复制每个节点插入到原节点后面
void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode=pHead;
	while(pNode!=NULL)
	{
		ComplexListNode* pCloned=new ComplexListNode;
		pCloned->m_nValue=pNode->m_nValue;
		pCloned->m_pNext=pNode->m_pNext;
		pCloned->m_pSibling=NULL;

		pNode->m_pNext=pCloned;
		pNode=pCloned->m_pNext; 
	}
}

//设置复制出来的节点的s指针
/*
假设原始链表的M的S指针 指向节点N, 复制出来的M'的S指针指向的节点N'在N的下一个   
*/
void ConnectSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode=pHead;
	while(pNode!=NULL)
	{
		ComplexListNode* pCloned=pNode->m_pNext;
		if(pNode->m_pSibling!=NULL)
		{
			pCloned->m_pSibling=pNode->m_pSibling->m_pNext;
		}
		pNode=pCloned->m_pNext;

	}
}

//第三步  拆下来
ComplexListNode*ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode*pNode=pHead;
	ComplexListNode*pClonedHead=NULL;
	ComplexListNode*pClonedNode=NULL;
	if(pNode!=NULL)
	{
		pClonedHead=pClonedNode=pNode->m_pNext;
		pNode->m_pNext=pClonedNode->m_pNext;
		pNode=pNode->m_pNext;
	}
	while(pNode!=NULL)
	{
		pClonedNode->m_pNext=pNode->m_pNext;
		pClonedNode=pClonedNode->m_pNext;
		pNode->m_pNext=pClonedNode->m_pNext;
		pNode=pNode->m_pNext;
	}
	return pClonedNode;
}



ComplexListNode* Colne(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}





int main()
{
	 

	return 0;
}

