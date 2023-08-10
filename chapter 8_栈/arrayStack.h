


#ifndef __ARRAY_STACK__H__
#define __ARRAY_STACK__H__
#include "stack.h"
#include <iostream>

template <class T>
class arrayStack : public stack<T>
{
public:
	arrayStack(int initialCapacity = 5);
	~arrayStack() { delete[] stack; }

	bool empty() const { return  stackTop == -1; }
	int size() const { return stackTop + 1; }
	// 返回栈顶元素的引用
	T& top() const;
	// 删除栈顶元素
	void pop();
	// 将元素 theElement 压入栈顶
	void push(const T& theElement);

private:
	int stackTop;		// 当前栈顶
	int arrayLength;	// 栈容量
	T* stack;			// 元素数组

	void resize();		// 改变栈空间大小
};

template <class T>
arrayStack<T> ::arrayStack(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		std::ostringstream s;
		s << "Initial capacity = " << initialCapacity << ", Must be > 0";
		throw std::invalid_argument(s.str());
	}
	arrayLength = initialCapacity;
	stack = new T[arrayLength];
	stackTop = -1;
}


// 返回栈顶元素的引用
template <class T>
T& arrayStack<T> ::top() const
{
	if (empty())
	{
		throw std::out_of_range("Stack is empty");
	}
	return stack[stackTop];
}

// 删除栈顶元素
template <class T>
void arrayStack<T> ::pop()
{
	if (empty())
	{
		throw std::out_of_range("Stack is empty");
	}
	stackTop--;
}

// 将元素 theElement 压入栈顶
template <class T>
void arrayStack<T>::push(const T& theElement)
{
	if (stackTop + 1 == arrayLength)
	{
		resize();
	}
	stack[++stackTop] = theElement;
}

template <class T>
void arrayStack<T>::resize()
{
	int newArrayLength = arrayLength * 2;
	T* newStack = new T[newArrayLength];
	for (int i = 0; i < arrayLength; i++)
	{
		newStack[i] = stack[i];
	}
	arrayLength = newArrayLength;
	delete[] stack;
	stack = newStack;
	
	std :: cout << "扩容" << std :: endl;
}

#endif // !__ARRAY_STACK__H__
