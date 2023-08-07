


#ifndef __LINEAR_LIST__H__
#define __LINEAR_LIST__H__
#include <iostream>
using namespace std;

template<class T>
class linearList
{
public:
	virtual ~linearList() {};

	// 返回 true, 当前且当线性表为空
	virtual bool empty() const = 0;
	// 返回线性表的元素个数
	virtual int size() const = 0;
	// 返回索引为 theIndex 的元素
	virtual T& get(int theIndex) const = 0;
	// 返回元素 theElment 第一次出现的索引
	virtual int indexOf(const T& theElement) const = 0;
	// 删除元素为 theIndex 的元素
	virtual void earse(int theIndex) = 0;
	// 把 theElement 插入线性表索引为 theIndex 的位置
	virtual void insert(int theIndex, const T& theElement) = 0;
};



// 注释 : 
// virtual 关键字用于声明虚函数。虚函数允许子类重写基类的函数，并且通过基类的指针或引用调用时可以动态绑定到正确的函数。

// = 0 则表示纯虚函数。纯虚函数是在基类中声明但没有提供具体实现的虚函数。
// 包含纯虚函数的类被称为抽象类，它只能被用作其他类的基类，不能直接实例化。派生类必须实现抽象类中的纯虚函数才能成为具体类。




#endif // !__ARRAY_LIST__H__
