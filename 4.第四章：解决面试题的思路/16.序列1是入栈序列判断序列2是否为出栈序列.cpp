#include<iostream>
using namespace std;

#include<stack>

bool IsPopOrder(const int * pPush, const int *pPop, int nLength)
{
	bool bPossible=false;
	if(pPush !=NULL && pPop!=NULL && nLength>0)
	{
		const int* pNextPush=pPush;
		const int* pNextPop=pPop;
		stack<int>stackData;
		while(pNextPop-pPop<nLength)//12345 45321
		{
			/*
			����ʱ�Ĺ��ɣ������һ�����������֣�pNextPop���պ���ջ�����֣�stackData.top()������ֱ�ӵ���
			�������ջ���� �Ͱ���ջ������û�н�ջ��������ջ�� ֱ������һ����Ҫ��ջ������ѹ��ջΪֹ���˴���5��,
			�������ֶ���ջ����û�ҳ���һ������������  �Ͳ�ƥ��
			*/
			while(stackData.empty() || stackData.top() != *pNextPop) //����*pNextPush����ȵĶ�ѹ��  
			{
				if(pNextPush-pPush==nLength)//���˾��˳�
					break;
				stackData.push(*pNextPush);//4��ջʱ ���Ѿ�ָ��5��
				pNextPush++;
			}
			if(stackData.top() != *pNextPop)//��Ⱦͳ�ջ��  pNextPop����
				break;
			stackData.pop(); 
			pNextPop++;        
		}
		if(stackData.empty() && pNextPop-pPop==nLength)
			bPossible=true;
	}
	return bPossible;
}


 




int main()
{
	int a[] = {1,2,3,4,5};
	if(IsPopOrder(a,a,5))
		cout<<"Yes"<<endl;
	 

	return 0;
}

