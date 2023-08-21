


#ifndef __PTREE__H__
#define __PTREE__H__

template <class T>
struct pTNode
{
	T element;
	int parent;	// 双亲位置域

	pTNode(const T& elem, int p = -1)
		: element(elem), parent(p) {}
};

template <class T>
class pTree
{
private:
	pTNode<T>* nodes;	// 节点数组, 存放节点, 数组下标
	int rootIndex;		// 根节点位置
	int size;			// 节点个数
};

#endif // ! __PTREE__H__
