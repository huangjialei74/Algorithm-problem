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
			弹出时的规律：如果下一个弹出的数字（pNextPop）刚好是栈顶数字（stackData.top()），则直接弹出
			如果不在栈顶， 就把入栈序列中没有进栈的数字入栈， 直到把下一个需要出栈的数字压入栈为止（此处是5）,
			所有数字都入栈后仍没找出下一个弹出的数字  就不匹配
			*/
			while(stackData.empty() || stackData.top() != *pNextPop) //把与*pNextPush不相等的都压入  
			{
				if(pNextPush-pPush==nLength)//满了就退出
					break;
				stackData.push(*pNextPush);//4入栈时 针已经指向5了
				pNextPush++;
			}
			if(stackData.top() != *pNextPop)//相等就出栈，  pNextPop后移
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

