

#ifndef __CTBOX__H__
#define __CTBOX__H__

template <class T>
struct cTNODE	// 孩子节点
{
	T data;
	cTNODE<T>* next;

	cTNODE(const T& value) : data(value), next(nullptr) {}
};

template <class T>
struct cTBox	// 双亲节点
{
	T data;
	cTBox<T>* firstChild;	// 孩子链表头指针
	cTBox(const T& value) : data(value), firstChild(nullptr) {}
};

template <class T>
class cTree
{
private:
	cTBox<T>* nodes;	// 节点数组, 存放节点, 数组下标
	int rootIndex;		// 根节点位置
	int size;			// 节点个数
};
#endif // ! __CTBOX__H__
