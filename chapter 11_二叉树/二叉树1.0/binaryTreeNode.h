


#ifndef __BINARY_TREE_NODE__H__
#define __BINARY_TREE_NODE__H__

// 链表二叉树的节点结构
template <class T>
struct binaryTreeNode
{
	T element;
	binaryTreeNode<T>* leftChild;	// 左孩子指针
	binaryTreeNode<T>* rightChild;	// 左孩子指针

	// 构造方法
	binaryTreeNode() : element(NULL), leftChild(nullptr), rightChild(nullptr){}
	binaryTreeNode(const T& theElement) : element(theElement), leftChild(nullptr), rightChild(nullptr) {}
	binaryTreeNode(const T& theElement, binaryTreeNode* theLeftChild, binaryTreeNode* theRightChild) :
		element(theElement), leftChild(theLeftChild), rightChild(theRightChild) {}
};

#endif // !__BINARY_TREE_NODE__H__
