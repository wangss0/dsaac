

#ifndef __ARRAY_LIST__CPP__
#define __ARRAY_LIST__CPP__

#include "arrayList.h"
#include "myException.h"
#include <sstream>		// ostringostream


// 构造函数
template <class T>
arrayList<T> ::arrayList(int initialCapacity)
{

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

// 若索引 theIndex 无效， 则抛出异常
// 这个checkIndex 检测 0 ~ listSize - 1 之间， 用于 get(), indexOf(), earse()
template <class T>
void arrayList<T> ::checkIndex(int theIndex) const
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
T& arrayList<T> ::get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}

// 返回元素 theElment 第一次出现的索引
template <class T>
int arrayList<T> :: indexOf(const T& theElement) const
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
	//checkIndex(theIndex); 这里不用这个
	// 这个检测的 theIndex， theIndex = listSize,满足条件，表示插入到现有数组的后面
	if (theIndex < 0 || theIndex > listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << ", size = " << listSize;
		throw illegalIndex(s.str());
	}

	// 数组满了增加长度
	if (listSize == arrayLength)
	{
		int newLength = arrayLength * 2;
		T* tmp = new T[newLength];
		for (int i = 0; i < arrayLength; i++)
		{
			tmp[i] = element[i];
		}
		delete[] element; // 释放原始数组的内存空间
		element = tmp;
		arrayLength = newLength; // 更新数组长度
		cout << "扩容" << endl;
	}

	
	// 将元素后移
	// for 从前往后错误， 先将现有的元素往空的位置搬运
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
		out << x.get(i) << " ";
	}
	return out;
}
#endif // !__ARRAY_LIST__CPP__