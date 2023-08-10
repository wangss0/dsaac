
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
	// 返回栈顶元素的引用
	virtual T& top() const = 0;
	// 删除栈顶元素
	virtual void pop() = 0;
	// 将元素 theElement 压入栈顶
	virtual void push(const T& theElement) = 0;
};
#endif // !__STACK__H__
