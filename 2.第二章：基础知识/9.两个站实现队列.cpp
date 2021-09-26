#include<iostream>
using namespace std;

#include<stack>


template <typename T>class CQueue
{
	public:
		CQueue(void );
		~CQueue(void );
		void appendTail(const T& element);
		T deleteHead();
private:
	stack<T>stack1;
	 stack<T>stack2;
};

template <typename T> 
void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}

template <typename T> 
T CQueue<T>::deleteHead()
{
	if(stack2.size()<=0)//stack1中的元素逐个弹出并压入stack2中
	{
		while(stack1.size() >0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if(stack2.size() == 0)
	{
		throw new exception("queue is empty");//为空
	}
	T head = stack2.top();
	stack2.pop();
	return head;
}













int main()
{
	 

	return 0;
}

