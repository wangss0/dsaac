

#ifndef __STACK__H__
#define __STACK__H__
#include <stdexcept>
#include <sstream>

template <class T>
class queue
{
public:
	virtual ~queue() {};
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	// ����ͷԪ�ص�����
	virtual T& front() const = 0;
	// ����βԪ�ص�����
	virtual T& back() const = 0;
	// ɾ����Ԫ��
	virtual void pop() = 0;		// �Ƚ��ȳ�
	// ��Ԫ�� theElement �����β
	virtual void push(const T& theElement) = 0;
};
#endif // !__STACK__H__
