

#ifndef __THREAD_BINARY_TREE_NODE__H__
#define __THREAD_BINARY_TREE_NODE__H__

// ����������
// ���ӿ��ţ� ָ��ǰ���� �Һ��ӿ��ţ� ָ����
template <class T>
struct threadedBinaryTreeNode
{
	T element;
	int ltag, rtag;		// ��� 
	threadedBinaryTreeNode<T>* leftChild;	// ����ָ��
	threadedBinaryTreeNode<T>* rightChild;	// ����ָ��

	threadedBinaryTreeNode(const T& elem, int l = 0, int r = 0,
		threadedBinaryTreeNode<T>* left = nullptr,
		threadedBinaryTreeNode<T>* right = nullptr)
		: element(elem), ltag(l), rtag(r), leftChild(left), rightChild(right) {}
};

#endif // !__THREAD_BINARY_TREE_NODE__H__
