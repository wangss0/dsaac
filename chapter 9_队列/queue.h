

#ifndef __STACK__H__
#define __STACK__H__
#include <stdexcept>
#include <sstream>

template <class T>
class queue
{
public:
	virtual ~queue() {};
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	// 返回头元素的引用
	virtual T& front() const = 0;
	// 返回尾元素的引用
	virtual T& back() const = 0;
	// 删除首元素
	virtual void pop() = 0;		// 先进先出
	// 将元素 theElement 插入队尾
	virtual void push(const T& theElement) = 0;
};
#endif // !__STACK__H__
