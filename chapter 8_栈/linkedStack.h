


#ifndef __LINKED_STACK__H__
#define __LINKED_STACK__H__
#include "stack.h"
#include <iostream>
#include "chainNode.h"

template <class T>
class linkedStack : public stack<T>
{
public:
	linkedStack(int initialCapacity = 10) : stackTop(nullptr), stackSize(0) {}
	~linkedStack();
	bool empty() const { return stackSize == 0; }
	int size() const { return stackSize; }
	T& top() const;
	
	// 删除栈顶元素
	void pop();
	// 将元素 theElement 压入栈顶
	void push(const T& theElement);
private:
	chainNode<T>* stackTop;		// 栈顶指针
	int stackSize;				// 栈中元素个数
};

template <class T>
linkedStack<T> :: ~linkedStack()
{
	while (stackTop != nullptr)
	{
		chainNode<T>* nextNode = stackTop->next;
		delete stackTop;
		stackTop = nextNode;
	}
}
// 返回栈顶元素的引用
template <class T>
T& linkedStack<T> ::top() const
{
	if (empty())
	{
		throw std::out_of_range("Stack is empty");
	}
	return stackTop->element;
}
// 删除栈顶元素
template <class T>
void linkedStack<T> ::pop()
{
	if (empty())
	{
		throw std::out_of_range("Stack is empty");
	}
	chainNode<T>* nextNode = stackTop->next;
	delete stackTop;
	stackTop = nextNode;
	stackSize--;
}

// 将元素 theElement 压入栈顶
template <class T>
void linkedStack<T> ::push(const T& theElement)
{
	chainNode<T>* newNode = new chainNode<T>(theElement, stackTop);	// 新的节点，新的栈顶，next 指向以前的 stackTop
	stackTop = newNode;
	stackSize++;
}
#endif // !__LINKED_STACK__H__