

#ifndef __LINKED_QUEUE__H__
#define __LINKED_QUEUE__H__
#include "chainNode.h"
#include "queue.h"

template <class T>
class linkedQueue : public queue<T>
{
public :

	linkedQueue(int initialCapacity = 10) : queueFront(nullptr), queueBack(nullptr), queueSize(0) {}
	~linkedQueue();

	bool empty() const { return queueFront == nullptr; }
	
	int size() const { return queueSize; }
	
	// 返回头元素的引用
	T& front() const;
	
	// 返回尾元素的引用
	T& back() const;
	
	// 删除首元素
	void pop();	

	// 将元素 theElement 插入队尾
	void push(const T& theElement);

private:
	chainNode<T>* queueFront;		// 头指针， 队首元素前一个位置的下标
	chainNode<T>* queueBack;		// 尾指针， 队尾元素的下标
	int queueSize;
};


template <class T>
linkedQueue<T> :: ~linkedQueue()
{
	while (!empty())
	{
		chainNode<T>* nextNode = queueFront->next;
		delete queueFront;
		queueFront = nextNode;
	}
}

// 返回头元素的引用
template <class T>
T& linkedQueue<T> ::front() const
{
	if (empty())
	{
		throw std::out_of_range("Queue is empty");
	}
	return queueFront->element;
}

// 返回尾元素的引用
template <class T>
T& linkedQueue<T> ::back() const
{
	if (empty())
	{
		throw std::out_of_range("Queue is empty");
	}
	return queueBack->element;
}

// 删除首元素
template <class T>
void linkedQueue<T> ::pop()
{
	if (empty())
	{
		throw std::out_of_range("Queue is empty");
	}
	chainNode<T>* nextNode = queueFront->next;
	delete queueFront;
	queueFront = nextNode;
	queueSize--;
}

// 将元素 theElement 插入队尾
template <class T>
void linkedQueue<T> ::push(const T& theElement)
{

	chainNode<T>* newNode = new chainNode<T>(theElement, nullptr);

	// 如果队列为空，直接将新节点设为队首
	if (queueSize == 0)
	{
		queueFront = newNode;
		queueBack = newNode;
	}
		
	else
	{ 
		queueBack->next = newNode;
		queueBack = queueBack->next;
	}
	queueSize++;
}


#endif // !__LINKED_QUEUE__H__
