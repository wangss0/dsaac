

#ifndef __CHAIN__CPP__
#define __CHAIN__CPP__
#include "chain.h"
#include <sstream>
#include "myException.h"

template <class T>
chain<T> ::chain(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << ", Must be  > 0";
		throw illegalParameter(s.str());
	}
	listSize = 0;
	firstNode = NULL;
}
template <class T>
chain<T> ::chain(const chain<T>& theChain)
{
	listSize = theChain.listSize;

	if (listSize == 0)
	{
		firstNode = NULL;
		return;
	}

	// ���� theChain Ϊ�ǿ�ʱ
	chainNode<T>* sourceNode = theChain.firstNode;		// ���� theChain �Ľڵ㣬��¼ theChain �Ľڵ�
	firstNode = new chainNode<T>(sourceNode->element);	// �������� theChain ����Ԫ��
	sourceNode = sourceNode->next;
	chainNode<T>* targetNode = firstNode;				// ��ǰ *this �����һ���ڵ�
	while (sourceNode != NULL)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;	// �������
}

// ��������
template <class T>
chain<T> :: ~chain()
{
	while (firstNode != NULL)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}

// ���������Ч�� �׳��쳣
template <class T>
void chain<T> :: checkIndex(int theIndex) const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << ", size = " << listSize;
		throw illegalIndex(s.str());
	}
}

// ��������Ϊ theIndex ��Ԫ��
template <class T>
T& chain<T> ::get(int theIndex) const
{
	checkIndex(theIndex);
	// ��������Ҫ�Ľڵ�
	chainNode<T>* currrentNode = firstNode;
	for (int i = 0; i < theIndex; i++)
	{
		currrentNode = currrentNode->next;
	}
	return currrentNode->element;
}

// ����Ԫ�� theElment ��һ�γ��ֵ�����
template <class T>
int chain<T> ::indexOf(const T& theElement) const
{
	// ��������Ҫ�Ľڵ�
	chainNode<T>* currrentNode = firstNode;
	for (int i = 0; i < listSize; i++)
	{
		if (currrentNode->element == theElement)
		{
			return i;
		}
		currrentNode = currrentNode->next;
	}
	return -1;
}

// ɾ��Ԫ��Ϊ theIndex ��Ԫ��
template <class T>
void chain<T> ::earse(int theIndex)
{
	checkIndex(theIndex);
	// ��������Ҫ�Ľڵ�
	if (theIndex == 0)
	{
		chainNode<T>* earseNode = firstNode;
		firstNode = firstNode->next;
		listSize--;
		delete earseNode;
	}
	else
	{
		chainNode<T>* currrentNode = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
		{
			currrentNode = currrentNode->next;
		}
		chainNode<T>* earseNode = currrentNode->next;
		currrentNode->next = currrentNode->next->next;
		listSize--;
		delete earseNode;
	}
	
}

// �� theElement �������Ա�����Ϊ theIndex ��λ��
template <class T>
void chain<T> ::insert(int theIndex, const T& theElement)
{
	//checkIndex(theIndex); ���ﲻ�����
	// ������� theIndex�� theIndex = listSize,������������ʾ���뵽��������ĺ���
	if (theIndex < 0 || theIndex > listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << ", size = " << listSize;
		throw illegalIndex(s.str());
	}

	if (theIndex == 0)
	{
		// ������ͷ����
		// firstNode = new chainNode<T>(theElement, firstNode);
		chainNode<T>* insertP = new chainNode<T>(theElement, firstNode);
		firstNode = insertP;
	}
	else
	{
		// Ѱ���µ�����ǰ��
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
		{
			p = p->next;
		}
		// �� p �����
		chainNode<T> *insertP = new chainNode<T>(theElement, p->next);
		p->next = insertP;
	}
	listSize++;
}

template <class T>
ostream& operator << (ostream& out, const chain<T>& x)
{
	for (int i = 0; i < x.size(); i++)
	{
		out << x.get(i) << " ";
	}
	return out;
}
#endif // !__CHAIN__CPP__
