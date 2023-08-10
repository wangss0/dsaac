
#ifndef __STACK__H__
#define __STACK__H__
#include <stdexcept>
#include <sstream>

template <class T>
class stack
{
public:
	// virtual ~stack() {};
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	// ����ջ��Ԫ�ص�����
	virtual T& top() const = 0;
	// ɾ��ջ��Ԫ��
	virtual void pop() = 0;
	// ��Ԫ�� theElement ѹ��ջ��
	virtual void push(const T& theElement) = 0;
};
#endif // !__STACK__H__
