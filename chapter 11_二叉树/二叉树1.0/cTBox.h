

#ifndef __CTBOX__H__
#define __CTBOX__H__

template <class T>
struct cTNODE	// ���ӽڵ�
{
	T data;
	cTNODE<T>* next;

	cTNODE(const T& value) : data(value), next(nullptr) {}
};

template <class T>
struct cTBox	// ˫�׽ڵ�
{
	T data;
	cTBox<T>* firstChild;	// ��������ͷָ��
	cTBox(const T& value) : data(value), firstChild(nullptr) {}
};

template <class T>
class cTree
{
private:
	cTBox<T>* nodes;	// �ڵ�����, ��Žڵ�, �����±�
	int rootIndex;		// ���ڵ�λ��
	int size;			// �ڵ����
};
#endif // ! __CTBOX__H__
