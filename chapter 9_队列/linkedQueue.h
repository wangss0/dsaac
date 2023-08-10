

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
	
	// ����ͷԪ�ص�����
	T& front() const;
	
	// ����βԪ�ص�����
	T& back() const;
	
	// ɾ����Ԫ��
	void pop();	

	// ��Ԫ�� theElement �����β
	void push(const T& theElement);

private:
	chainNode<T>* queueFront;		// ͷָ�룬 ����Ԫ��ǰһ��λ�õ��±�
	chainNode<T>* queueBack;		// βָ�룬 ��βԪ�ص��±�
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

// ����ͷԪ�ص�����
template <class T>
T& linkedQueue<T> ::front() const
{
	if (empty())
	{
		throw std::out_of_range("Queue is empty");
	}
	return queueFront->element;
}

// ����βԪ�ص�����
template <class T>
T& linkedQueue<T> ::back() const
{
	if (empty())
	{
		throw std::out_of_range("Queue is empty");
	}
	return queueBack->element;
}

// ɾ����Ԫ��
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

// ��Ԫ�� theElement �����β
template <class T>
void linkedQueue<T> ::push(const T& theElement)
{

	chainNode<T>* newNode = new chainNode<T>(theElement, nullptr);

	// �������Ϊ�գ�ֱ�ӽ��½ڵ���Ϊ����
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
