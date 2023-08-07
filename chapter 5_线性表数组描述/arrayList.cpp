

#ifndef __ARRAY_LIST__CPP__
#define __ARRAY_LIST__CPP__

#include "arrayList.h"
#include "myException.h"
#include <sstream>		// ostringostream



template <class T>
arrayList<T> ::arrayList(int initialCapacity)
{
	// 构造函数
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << ", Must be  > 0";
		throw illegalParameter(s.str());
	}
	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;
}

template <class T>
arrayList<T> ::arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength; // 更新 arrayLength
	listSize = theList.listSize;
	element = new T[arrayLength];
	for (int i = 0; i < listSize; i++)
	{
		element[i] = theList.element[i];
	}
}


// 若索引 theIndex 无效， 则抛出异常
template <class T>
void arrayList<T> :: checkIndex(int theIndex) const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << ", size = " << listSize;
		throw illegalIndex(s.str());
	}
}

// 返回 true, 当前且当线性表为空
template <class T>
bool arrayList<T> ::empty() const
{
	return listSize == 0;
}

// 返回线性表的元素个数
template <class T>
int arrayList<T> ::size() const
{
	return listSize;
}

// 返回索引为 theIndex 的元素
template <class T>
T& arrayList<T> ::get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}

// 返回元素 theElment 第一次出现的索引
template <class T>
int arrayList<T> :: indexoO(const T& theElement) const
{
	for (int i = 0; i < listSize; i++)
	{
		if (element[i] == theElement)
		{
			return i;
		}
	}
	return -1;
}

// 删除元素为 theIndex 的元素
template <class T>
void arrayList<T> ::earse(int theIndex)
{
	for (int i = theIndex; i < listSize; i++)
	{
		element[i] = element[i + 1];
	}
	listSize--;
}

// 把 theElement 插入线性表索引为 theIndex 的位置
template <class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
	// 将元素后移
	for (int i = listSize - 1; i >= theIndex; i--) {
		element[i + 1] = element[i];
	}


	// 在指定索引位置插入新元素
	element[theIndex] = theElement;

	// 更新线性表大小
	listSize++;
}



template <class T>
ostream& operator << (ostream& out , const arrayList<T>& x)
{
	for (int i = 0; i < x.size(); i++)
	{
		out << x.element[i] << " ";
	}
	return out;
}
#endif // !__ARRAY_LIST__CPP__