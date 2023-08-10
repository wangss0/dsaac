

// 实现循环队列
// 本书和王老师讲的有点不一样，
// 本书，头指针设置为空

#ifndef __ARRAY_QUEUE__H__
#define __ARRAY_QUEUE__H__
#include "queue.h"
#include <iostream>
#include <algorithm>	// copy
#include <iostream>

template <class T>
class arrayQueue : public queue<T>
{
public:
	// 构造和析构函数
	arrayQueue(int initialCapacity = 5);
	~arrayQueue() { delete[] queue; }

	//判断队列是否为空
	bool empty() const { return (queueFront == queueBack); }

	//队列元素的个数
	int size() const { return (queueBack - queueFront + arrayLength) % arrayLength; }	// 循环队列

	//队首元素的引用
	T& front() const;

	//队尾元素的引用
	T& back() const;
	

	//删除队首元素
	void pop();
	
	// 将元素 theElement 插入队尾
	void push(const T & theElement);
private:
	int queueFront;		// 头指针， 队首元素前一个位置的下标
	int queueBack;		// 尾指针， 队尾元素的下标
	T* queue;			// 元素数组 
	int arrayLength;	// 队列长度
};


// 构造函数
template <class T>
arrayQueue<T>::arrayQueue(int initialCapacity) 
{
	if (initialCapacity < 1)
	{
		std::ostringstream s;
		s << "Initial capacity = " << initialCapacity << ", Must be > 0";
		throw std::invalid_argument(s.str());
	}
	arrayLength = initialCapacity;
	queue = new T[arrayLength];
	queueFront = queueBack = 0;
}


// 返回队首元素的引用
template <class T>
T& arrayQueue<T> :: front() const
{
	//队空，抛出异常
	if (empty())
		throw std::out_of_range("Queue is empty");
	return queue[(queueFront + 1) % arrayLength];	// % arrayLength 避免 queueFront 在顶部
}


// 返回队尾元素的引用
template <class T>
T& arrayQueue<T> :: back() const
{
	if (empty())
		throw std::out_of_range("Queue is empty");
	return queue[queueBack];
}


// 删除队首元素
template <class T>
void arrayQueue<T>:: pop()
{
	if (empty())
		throw std::out_of_range("Queue is empty");
	queueFront = (queueFront + 1) % arrayLength;	// 头指针往后移动，如果达到最大值，% 回到原点  
	queue[queueFront].~T();	// 队头置空
}


//插入元素
template <class T>
void arrayQueue<T>::push(const T& theElement)
{
	//队满，数组容量加倍
	if ((queueBack + 1) % arrayLength == queueFront)
	{
		//分配新的数组空间
		T* newQueue = new T[2 * arrayLength];

		//将原数组元素复制到新数组
		int start = (queueFront + 1) % arrayLength;	// start ,头指针（为空）的下一个位置	// start == 1，queueFront = 0,还没开始“循环”，没有形成环
		if (start == 1)
		{
			// 元素环不包含0位置
			// 将从 queue 数组中的位置 queue + start 开始（包含）的元素，复制到 newQueue 数组中。
			// 复制的结束位置是 queue + start + arrayLength - 1（不包含）。
			// 复制从 queue 数组的第 start 个位置开始，一直复制到第 start + arrayLength - 1 个位置为止的元素。
			std::copy(queue + start, queue + start + arrayLength - 1, newQueue);
		}
		else
		{
			//分成前后两部分复制
			std::copy(queue + start, queue + arrayLength, newQueue);						// 头到“顶”（不包含）
			std::copy(queue, queue + queueBack + 1, newQueue + arrayLength - start);		// “底”到尾（不包含）
		}

		//设置新数组的首和尾的元素位置
		queueFront = 2 * arrayLength - 1;		// 新队列的“顶”, 顶为空， (顶 + 1) % arrayLength = 0 (底部第一个元素)
		queueBack = arrayLength - 2;			// (0 到 arrayLength - 2) 恰好 原队列的元素个数（arrayLength - 1）（0不算）
		arrayLength *= 2;
		delete[] queue;
		queue = newQueue;
		std::cout << "扩容" << std::endl;
	}

	//插入到队列尾部
	queueBack = (queueBack + 1) % arrayLength;
	queue[queueBack] = theElement;
}


#endif // !__ARRAY_QUEUE__H__