


#ifndef __ARRAY_LIST__H__
#define __ARRAY_LIST__H__
#include "linearList.h"

template <class T>
class arrayList : public linearList<T>
{
public:
	// ���캯��, �������캯���� ��������
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() { delete[] element; };

	// ���� true, ��ǰ�ҵ����Ա�Ϊ��
	bool empty() const;
	// �������Ա��Ԫ�ظ���
	int size() const;
	// ��������Ϊ theIndex ��Ԫ��
	T& get(int theIndex) const;
	// ����Ԫ�� theElment ��һ�γ��ֵ�����
	int indexOf(const T& theElement) const;
	// ɾ��Ԫ��Ϊ theIndex ��Ԫ��
	void earse(int theIndex);
	// �� theElement �������Ա�����Ϊ theIndex ��λ��
	void insert(int theIndex, const T& theElement);

private:
	// ������ theIndex ��Ч�� ���׳��쳣
	void checkIndex(int theIndex) const;
	T* element;			// �洢���Ա�Ԫ�ص�һά���飬 �����׵�ַ
	int arrayLength;	// һά���������
	int listSize;		// ���Ա��Ԫ�ظ���
};

#include "arrayList.cpp"

#endif // !__ARRAY_LIST__H__
