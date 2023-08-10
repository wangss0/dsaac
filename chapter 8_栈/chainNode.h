

#ifndef __CHAIN_NODE__H__
#define __CHAIN_NODE__H__

template <class T>
struct chainNode
{
	// 数据成员
	T element;
	chainNode<T>* next;

	// 方法
	chainNode() {}
	chainNode(const T& theElement) : element(theElement) {}
	chainNode(const T& theElement, chainNode<T>* theNext) : element(theElement), next(theNext) {}
};

#endif // !__CHAIN_NODE__H__