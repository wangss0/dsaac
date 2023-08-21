

#ifndef __THREAD_BINARY_TREE_NODE__H__
#define __THREAD_BINARY_TREE_NODE__H__

// 线索二叉树
// 左孩子空着， 指向前驱； 右孩子空着， 指向后继
template <class T>
struct threadedBinaryTreeNode
{
	T element;
	int ltag, rtag;		// 标记 
	threadedBinaryTreeNode<T>* leftChild;	// 左孩子指针
	threadedBinaryTreeNode<T>* rightChild;	// 左孩子指针

	threadedBinaryTreeNode(const T& elem, int l = 0, int r = 0,
		threadedBinaryTreeNode<T>* left = nullptr,
		threadedBinaryTreeNode<T>* right = nullptr)
		: element(elem), ltag(l), rtag(r), leftChild(left), rightChild(right) {}
};

#endif // !__THREAD_BINARY_TREE_NODE__H__
