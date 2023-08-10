


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
	
	// ɾ��ջ��Ԫ��
	void pop();
	// ��Ԫ�� theElement ѹ��ջ��
	void push(const T& theElement);
private:
	chainNode<T>* stackTop;		// ջ��ָ��
	int stackSize;				// ջ��Ԫ�ظ���
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
// ����ջ��Ԫ�ص�����
template <class T>
T& linkedStack<T> ::top() const
{
	if (empty())
	{
		throw std::out_of_range("Stack is empty");
	}
	return stackTop->element;
}
// ɾ��ջ��Ԫ��
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

// ��Ԫ�� theElement ѹ��ջ��
template <class T>
void linkedStack<T> ::push(const T& theElement)
{
	chainNode<T>* newNode = new chainNode<T>(theElement, stackTop);	// �µĽڵ㣬�µ�ջ����next ָ����ǰ�� stackTop
	stackTop = newNode;
	stackSize++;
}
#endif // !__LINKED_STACK__H__