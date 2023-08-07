

#ifndef __ARRAY_LIST__CPP__
#define __ARRAY_LIST__CPP__

#include "arrayList.h"
#include "myException.h"
#include <sstream>		// ostringostream



template <class T>
arrayList<T> ::arrayList(int initialCapacity)
{
	// ���캯��
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
	arrayLength = theList.arrayLength; // ���� arrayLength
	listSize = theList.listSize;
	element = new T[arrayLength];
	for (int i = 0; i < listSize; i++)
	{
		element[i] = theList.element[i];
	}
}


// ������ theIndex ��Ч�� ���׳��쳣
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

// ���� true, ��ǰ�ҵ����Ա�Ϊ��
template <class T>
bool arrayList<T> ::empty() const
{
	return listSize == 0;
}

// �������Ա��Ԫ�ظ���
template <class T>
int arrayList<T> ::size() const
{
	return listSize;
}

// ��������Ϊ theIndex ��Ԫ��
template <class T>
T& arrayList<T> ::get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}

// ����Ԫ�� theElment ��һ�γ��ֵ�����
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

// ɾ��Ԫ��Ϊ theIndex ��Ԫ��
template <class T>
void arrayList<T> ::earse(int theIndex)
{
	for (int i = theIndex; i < listSize; i++)
	{
		element[i] = element[i + 1];
	}
	listSize--;
}

// �� theElement �������Ա�����Ϊ theIndex ��λ��
template <class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
	// ��Ԫ�غ���
	for (int i = listSize - 1; i >= theIndex; i--) {
		element[i + 1] = element[i];
	}


	// ��ָ������λ�ò�����Ԫ��
	element[theIndex] = theElement;

	// �������Ա��С
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