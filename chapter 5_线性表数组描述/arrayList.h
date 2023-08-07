


#ifndef __ARRAY_LIST__H__
#define __ARRAY_LIST__H__
#include "linearList.h"

template <class T>
class arrayList : public linearList<T>
{
public:
	// 构造函数, 拷贝构造函数， 析构函数
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() { delete[] element; };

	// 返回 true, 当前且当线性表为空
	bool empty() const;
	// 返回线性表的元素个数
	int size() const;
	// 返回索引为 theIndex 的元素
	T& get(int theIndex) const;
	// 返回元素 theElment 第一次出现的索引
	int indexOf(const T& theElement) const;
	// 删除元素为 theIndex 的元素
	void earse(int theIndex);
	// 把 theElement 插入线性表索引为 theIndex 的位置
	void insert(int theIndex, const T& theElement);

private:
	// 若索引 theIndex 无效， 则抛出异常
	void checkIndex(int theIndex) const;
	T* element;			// 存储线性表元素的一维数组， 数组首地址
	int arrayLength;	// 一维数组的容量
	int listSize;		// 线性表的元素个数
};

#include "arrayList.cpp"

#endif // !__ARRAY_LIST__H__
