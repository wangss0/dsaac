


#ifndef __CHAIN__H__
#define __CHAIN__H__
#include "chainNode.h"
#include "linearList.h"

template <class T>
class chain : public linearList<T>
{
public:
	// 构造函数、拷贝构造函数、析构函数
	chain(int initialCapacity = 10);
	chain(const chain<T>&);
	~chain();

	// 返回 true, 当前且当线性表为空
	bool empty() const { return listSize == 0; }
	// 返回线性表的元素个数
	int size() const { return listSize; }
	// 返回索引为 theIndex 的元素
	T& get(int theIndex) const;
	// 返回元素 theElment 第一次出现的索引
	int indexOf(const T& theElement) const;
	// 删除元素为 theIndex 的元素
	void earse(int theIndex);
	// 把 theElement 插入线性表索引为 theIndex 的位置
	void insert(int theIndex, const T& theElement);
protected:
	// 如果索引无效， 抛出异常
	void checkIndex(int theIndex) const;
	chainNode<T>* firstNode;	// 指向链表的第一个节点的指针
	int listSize;				// 线性表的元素个数	
};



#include "chain.cpp"
#endif // !__CHAIN__H__
