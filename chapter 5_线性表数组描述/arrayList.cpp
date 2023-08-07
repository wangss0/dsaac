

#ifndef __ARRAY_LIST__CPP__
#define __ARRAY_LIST__CPP__

#include "arrayList.h"
#include "myException.h"
#include <sstream>		// ostringostream


// ���캯��
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
	arrayLength = theList.arrayLength; // ���� arrayLength
	listSize = theList.listSize;
	element = new T[arrayLength]; 
	for (int i = 0; i < listSize; i++)
	{
		element[i] = theList.element[i];
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

// ������ theIndex ��Ч�� ���׳��쳣
// ���checkIndex ��� 0 ~ listSize - 1 ֮�䣬 ���� get(), indexOf(), earse()
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

// ��������Ϊ theIndex ��Ԫ��
template <class T>
T& arrayList<T> ::get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}

// ����Ԫ�� theElment ��һ�γ��ֵ�����
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
	//checkIndex(theIndex); ���ﲻ�����
	// ������� theIndex�� theIndex = listSize,������������ʾ���뵽��������ĺ���
	if (theIndex < 0 || theIndex > listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << ", size = " << listSize;
		throw illegalIndex(s.str());
	}

	// �����������ӳ���
	if (listSize == arrayLength)
	{
		int newLength = arrayLength * 2;
		T* tmp = new T[newLength];
		for (int i = 0; i < arrayLength; i++)
		{
			tmp[i] = element[i];
		}
		delete[] element; // �ͷ�ԭʼ������ڴ�ռ�
		element = tmp;
		arrayLength = newLength; // �������鳤��
		cout << "����" << endl;
	}

	
	// ��Ԫ�غ���
	// for ��ǰ������� �Ƚ����е�Ԫ�����յ�λ�ð���
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
		out << x.get(i) << " ";
	}
	return out;
}
#endif // !__ARRAY_LIST__CPP__