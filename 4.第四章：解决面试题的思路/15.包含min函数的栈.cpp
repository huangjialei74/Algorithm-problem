#include<iostream>
using namespace std;

//�ؼ����� push pop min
template<typename T>void StackWithMin<T>::push(const T &value)
{
	m_data.push(value);
	if(m_min.size()==0||value<m_min.top())//С��ջ����ѹ���Ԫ��
		m_min.push(value);
	else
		m_min.push(m_min.top());//������ѹ��һ��ջ��Ԫ��
}
template<typename T>void StackWithMin<T>::pop()
{
	assert(m_data.size()>0 && m_min.size()>0)
	m_data.pop();
	m_min.pop();
}
template<typename T> const T& StackWithMin<T>::min() const
{
	assert(m_data.size()>0 && m_min.size()>0);
	return m_min.top();
}
















int main()
{
	 

	return 0;
}

