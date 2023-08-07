


#ifndef __CHAIN__H__
#define __CHAIN__H__
#include "chainNode.h"
#include "linearList.h"

template <class T>
class chain : public linearList<T>
{
public:
	// ���캯�����������캯������������
	chain(int initialCapacity = 10);
	chain(const chain<T>&);
	~chain();

	// ���� true, ��ǰ�ҵ����Ա�Ϊ��
	bool empty() const { return listSize == 0; }
	// �������Ա��Ԫ�ظ���
	int size() const { return listSize; }
	// ��������Ϊ theIndex ��Ԫ��
	T& get(int theIndex) const;
	// ����Ԫ�� theElment ��һ�γ��ֵ�����
	int indexOf(const T& theElement) const;
	// ɾ��Ԫ��Ϊ theIndex ��Ԫ��
	void earse(int theIndex);
	// �� theElement �������Ա�����Ϊ theIndex ��λ��
	void insert(int theIndex, const T& theElement);
protected:
	// ���������Ч�� �׳��쳣
	void checkIndex(int theIndex) const;
	chainNode<T>* firstNode;	// ָ������ĵ�һ���ڵ��ָ��
	int listSize;				// ���Ա��Ԫ�ظ���	
};



#include "chain.cpp"
#endif // !__CHAIN__H__
