

// ʵ��ѭ������
// ���������ʦ�����е㲻һ����
// ���飬ͷָ������Ϊ��

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
	// �������������
	arrayQueue(int initialCapacity = 5);
	~arrayQueue() { delete[] queue; }

	//�ж϶����Ƿ�Ϊ��
	bool empty() const { return (queueFront == queueBack); }

	//����Ԫ�صĸ���
	int size() const { return (queueBack - queueFront + arrayLength) % arrayLength; }	// ѭ������

	//����Ԫ�ص�����
	T& front() const;

	//��βԪ�ص�����
	T& back() const;
	

	//ɾ������Ԫ��
	void pop();
	
	// ��Ԫ�� theElement �����β
	void push(const T & theElement);
private:
	int queueFront;		// ͷָ�룬 ����Ԫ��ǰһ��λ�õ��±�
	int queueBack;		// βָ�룬 ��βԪ�ص��±�
	T* queue;			// Ԫ������ 
	int arrayLength;	// ���г���
};


// ���캯��
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


// ���ض���Ԫ�ص�����
template <class T>
T& arrayQueue<T> :: front() const
{
	//�ӿգ��׳��쳣
	if (empty())
		throw std::out_of_range("Queue is empty");
	return queue[(queueFront + 1) % arrayLength];	// % arrayLength ���� queueFront �ڶ���
}


// ���ض�βԪ�ص�����
template <class T>
T& arrayQueue<T> :: back() const
{
	if (empty())
		throw std::out_of_range("Queue is empty");
	return queue[queueBack];
}


// ɾ������Ԫ��
template <class T>
void arrayQueue<T>:: pop()
{
	if (empty())
		throw std::out_of_range("Queue is empty");
	queueFront = (queueFront + 1) % arrayLength;	// ͷָ�������ƶ�������ﵽ���ֵ��% �ص�ԭ��  
	queue[queueFront].~T();	// ��ͷ�ÿ�
}


//����Ԫ��
template <class T>
void arrayQueue<T>::push(const T& theElement)
{
	//���������������ӱ�
	if ((queueBack + 1) % arrayLength == queueFront)
	{
		//�����µ�����ռ�
		T* newQueue = new T[2 * arrayLength];

		//��ԭ����Ԫ�ظ��Ƶ�������
		int start = (queueFront + 1) % arrayLength;	// start ,ͷָ�루Ϊ�գ�����һ��λ��	// start == 1��queueFront = 0,��û��ʼ��ѭ������û���γɻ�
		if (start == 1)
		{
			// Ԫ�ػ�������0λ��
			// ���� queue �����е�λ�� queue + start ��ʼ����������Ԫ�أ����Ƶ� newQueue �����С�
			// ���ƵĽ���λ���� queue + start + arrayLength - 1������������
			// ���ƴ� queue ����ĵ� start ��λ�ÿ�ʼ��һֱ���Ƶ��� start + arrayLength - 1 ��λ��Ϊֹ��Ԫ�ء�
			std::copy(queue + start, queue + start + arrayLength - 1, newQueue);
		}
		else
		{
			//�ֳ�ǰ�������ָ���
			std::copy(queue + start, queue + arrayLength, newQueue);						// ͷ������������������
			std::copy(queue, queue + queueBack + 1, newQueue + arrayLength - start);		// ���ס���β����������
		}

		//������������׺�β��Ԫ��λ��
		queueFront = 2 * arrayLength - 1;		// �¶��еġ�����, ��Ϊ�գ� (�� + 1) % arrayLength = 0 (�ײ���һ��Ԫ��)
		queueBack = arrayLength - 2;			// (0 �� arrayLength - 2) ǡ�� ԭ���е�Ԫ�ظ�����arrayLength - 1����0���㣩
		arrayLength *= 2;
		delete[] queue;
		queue = newQueue;
		std::cout << "����" << std::endl;
	}

	//���뵽����β��
	queueBack = (queueBack + 1) % arrayLength;
	queue[queueBack] = theElement;
}


#endif // !__ARRAY_QUEUE__H__