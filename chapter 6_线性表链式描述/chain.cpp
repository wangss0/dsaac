

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

	// 链表 theChain 为非空时
	chainNode<T>* sourceNode = theChain.firstNode;		// 复制 theChain 的节点，记录 theChain 的节点
	firstNode = new chainNode<T>(sourceNode->element);	// 复制链表 theChain 的首元素
	sourceNode = sourceNode->next;
	chainNode<T>* targetNode = firstNode;				// 当前 *this 的最后一个节点
	while (sourceNode != NULL)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;	// 链表结束
}

// 析构函数
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

// 如果索引无效， 抛出异常
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

// 返回索引为 theIndex 的元素
template <class T>
T& chain<T> ::get(int theIndex) const
{
	checkIndex(theIndex);
	// 移向所需要的节点
	chainNode<T>* currrentNode = firstNode;
	for (int i = 0; i < theIndex; i++)
	{
		currrentNode = currrentNode->next;
	}
	return currrentNode->element;
}

// 返回元素 theElment 第一次出现的索引
template <class T>
int chain<T> ::indexOf(const T& theElement) const
{
	// 移向所需要的节点
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

// 删除元素为 theIndex 的元素
template <class T>
void chain<T> ::earse(int theIndex)
{
	checkIndex(theIndex);
	// 移向所需要的节点
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

// 把 theElement 插入线性表索引为 theIndex 的位置
template <class T>
void chain<T> ::insert(int theIndex, const T& theElement)
{
	//checkIndex(theIndex); 这里不用这个
	// 这个检测的 theIndex， theIndex = listSize,满足条件，表示插入到现有数组的后面
	if (theIndex < 0 || theIndex > listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << ", size = " << listSize;
		throw illegalIndex(s.str());
	}

	if (theIndex == 0)
	{
		// 在链表头插入
		// firstNode = new chainNode<T>(theElement, firstNode);
		chainNode<T>* insertP = new chainNode<T>(theElement, firstNode);
		firstNode = insertP;
	}
	else
	{
		// 寻找新的数据前驱
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
		{
			p = p->next;
		}
		// 在 p 后插入
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
