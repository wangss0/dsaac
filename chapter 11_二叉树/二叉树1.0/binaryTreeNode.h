


#ifndef __BINARY_TREE_NODE__H__
#define __BINARY_TREE_NODE__H__

// ����������Ľڵ�ṹ
template <class T>
struct binaryTreeNode
{
	T element;
	binaryTreeNode<T>* leftChild;	// ����ָ��
	binaryTreeNode<T>* rightChild;	// ����ָ��

	// ���췽��
	binaryTreeNode() : element(NULL), leftChild(nullptr), rightChild(nullptr){}
	binaryTreeNode(const T& theElement) : element(theElement), leftChild(nullptr), rightChild(nullptr) {}
	binaryTreeNode(const T& theElement, binaryTreeNode* theLeftChild, binaryTreeNode* theRightChild) :
		element(theElement), leftChild(theLeftChild), rightChild(theRightChild) {}
};

#endif // !__BINARY_TREE_NODE__H__
