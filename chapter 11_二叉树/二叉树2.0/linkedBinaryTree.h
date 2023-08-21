



#ifndef __LINKED_BINARY_TREE_H_
#define __LINKED_BINARY_TREE_H_

#include "binaryTreeNode.h"
#include <iostream>


template <class T>
class linkedBinaryTree 
{
private:
	binaryTreeNode<T>* root = nullptr;			// ָ��������ָ��

public:
	linkedBinaryTree() {};
	linkedBinaryTree(const linkedBinaryTree<T>& otherTree);
	void creatRoot(binaryTreeNode<T>* theRoot) { root = theRoot; }

	void preOrderTraversal() const;				// ǰ�����
	void inOrderTraversal() const;				// �������
	void postOrderTraversal() const;			// �������
	void levelOrderTraversal() const;			// ��α���

	void createTree();							// ����������
	
	// һЩ���ܽӿ�
	int depth() const;			// ���������
	int nodeCount() const;		// �������ڵ����
	int leadCount() const;		// Ҷ�ӽڵ����

private:
	static void visit(binaryTreeNode<T>*);			// ���ʽڵ㺯��
	static void (*visitPtr)(binaryTreeNode<T>*);	// ��̬����ָ��

	// ����ı���������ʵ��
	static void preOrder(binaryTreeNode<T>* t);
	static void inOrder(binaryTreeNode<T>* t);
	static void postOrder(binaryTreeNode<T>* t);
	static void levelOrder(binaryTreeNode<T>* t);

	// ����������ĸ�������
	static binaryTreeNode<T>* createTreeHelper();

	static void copyBinaryTree(binaryTreeNode<T>* tree, binaryTreeNode<T>*& newTree);

	// һЩ���ܽӿ�
	static int depthHelper(binaryTreeNode<T>* node);
	static int nodeCountHelper(binaryTreeNode<T>* node);
	static int leadCountHelper(binaryTreeNode<T>* node);

};


/*************************************************************************************************************/
// ������ֱ��ʹ�õı�������
// ���ｫ visit �� ����ı���ʵ�ַֿ�ʵ�֣� ʹ�ô������ģ�黯�����
template<class T>
void linkedBinaryTree<T>::preOrderTraversal() const
{
	visitPtr = visit; // ����̬����ָ�븳ֵΪ visit
	// ִ��ǰ�����
	// ���� root �������ڵ�ָ��
	preOrder(root);
}
template<class T>
void linkedBinaryTree<T>::inOrderTraversal() const
{
	visitPtr = visit;
	inOrder(root);
}
template<class T>
void linkedBinaryTree<T>::postOrderTraversal() const
{
	visitPtr = visit;
	postOrder(root);
}
template<class T>
void linkedBinaryTree<T>::levelOrderTraversal() const
{
	visitPtr = visit;
	levelOrder(root);
}

/*************************************************************************************************************/
// ����ı���������ʵ��
template <class T>
void linkedBinaryTree<T> ::preOrder(binaryTreeNode<T>* t)
{
	// ǰ������ľ��巽��
	if (t != nullptr)
	{
		linkedBinaryTree<T> ::visitPtr(t);
		preOrder(t->leftChild);          // �ݹ����������
		preOrder(t->rightChild);         // �ݹ����������
	}
}
template <class T>
void linkedBinaryTree<T> ::inOrder(binaryTreeNode<T>* t)
{
	// ��������ľ��巽��
	if (t != nullptr)
	{
		inOrder(t->leftChild);          // �ݹ����������
		linkedBinaryTree<T> ::visitPtr(t);
		inOrder(t->rightChild);         // �ݹ����������
	}
}
template <class T>
void linkedBinaryTree<T> ::postOrder(binaryTreeNode<T>* t)
{
	// ��������ľ��巽��
	if (t != nullptr)
	{
		postOrder(t->leftChild);          // �ݹ����������
		postOrder(t->rightChild);         // �ݹ����������
		linkedBinaryTree<T> ::visitPtr(t);
	}
}
// �ǵݹ��α��� �D�D�D�D ����
#include <deque>
template <class T>
void linkedBinaryTree<T> ::levelOrder(binaryTreeNode<T>* t)
{
	binaryTreeNode<T>* p = t;
	std::deque<binaryTreeNode<T>*> qu;
	qu.push_back(t);
	while (!qu.empty())
	{
		p = qu.front();
		linkedBinaryTree<T> ::visitPtr(p);
		qu.pop_front();
		if (p->leftChild != nullptr)
		{
			qu.push_back(p->leftChild);
		}
		if (p->rightChild != nullptr)
		{
			qu.push_back(p->rightChild);
		}
	}
}

/*************************************************************************************************************/
// visit 
// ��̬����ָ�� visitPtr �����ʾ������Ҫ���ڴ洢һ��ָ���ض����͵ľ�̬��Ա�����ĵ�ַ��ͨ��ʹ�þ�̬����ָ�룬�����������ڲ��������ʵ���λ�ý��丳ֵΪ��Ӧ�ľ�̬��Ա������������Ҫ��ʱ��ͨ����ָ�������صĺ�����
// �����ʾ���У�visitPtr �����洢���ʽڵ�ĺ��� visit �ĵ�ַ��ͨ���� visitPtr ��ʼ��Ϊ nullptr������Լ�����Ƿ��Ѿ�ָ������Ч�ĺ�����ַ��Ȼ���� inorderTraversal() �����У����ǽ� visitPtr ��ֵΪ visit���Ա����������ʱʹ�� visitPtr ���÷��ʽڵ�Ĺ��ܡ�
// ��̬����ָ���һ��������;��ʵ�ֻص�������ͨ��ʹ�þ�̬����ָ�룬�����ڲ��޸��ඨ�������£����������������������н��ʵ�����ĺ����ص����ơ�
template<class T>
void linkedBinaryTree<T>::visit(binaryTreeNode<T>* x)
{
	// ���ʽڵ� x, ���element ��
	std::cout << x->element << " ";
}

template<class T>
void (*linkedBinaryTree<T>::visitPtr)(binaryTreeNode<T>*) = nullptr;




/*************************************************************************************************************/
// ����������
/* �������������Ĺ��̷�ΪcreateTree()��createTreeHelper()��������
* createTree()�Ƕ����ṩ�Ľӿں������û�����ͨ�����øú�����������������
* ����һ���ڵ���Ϊ�����ڵ㡱
* 
* createTreeHelper()��һ���ݹ麯�������ڵݹ鴴���������Ľڵ㡣
* �����Ҷ�ӽڵ㣬�򷵻ؿ�ָ�룻���򣬴���һ���µ�binaryTreeNode�ڵ㣬���ַ���Ϊ�ڵ�Ԫ�أ����ݹ�ص�����������������������������
*/
template <class T>
void linkedBinaryTree<T>::createTree()
{
	char ch;

	std::cout << "�����������������������У��սڵ���#��ʾ����" << std::endl;

	std::cin >> ch;
	if (ch == '#') {
		return;	
	}
	root = new binaryTreeNode<T>(ch);

	// �ݹ鴴��������
	root->leftChild = createTreeHelper();

	// �ݹ鴴��������
	root->rightChild = createTreeHelper();
}


template <class T>
binaryTreeNode<T>* linkedBinaryTree<T>::createTreeHelper()
{
	char ch;

	std::cin >> ch;
	if (ch == '#') {
		return nullptr;
	}

	binaryTreeNode<T>* node = new binaryTreeNode<T>(ch);

	// �ݹ�������������������
	node->leftChild = createTreeHelper();
	node->rightChild = createTreeHelper();

	return node;
}


/*************************************************************************************************************/
// ��������, �ֿ�ʵ��
template <class T>
linkedBinaryTree<T>::linkedBinaryTree(const linkedBinaryTree<T>& otherTree)
{
	copyBinaryTree(otherTree.root, root);
}

template <class T>
void linkedBinaryTree<T>::copyBinaryTree(binaryTreeNode<T>* tree, binaryTreeNode<T>*& newTree)
{
	if (tree == nullptr)
	{
		newTree = nullptr;
	}
	else
	{
		newTree = new binaryTreeNode<T>(tree->element);
		copyBinaryTree(tree->leftChild, newTree->leftChild);
		copyBinaryTree(tree->rightChild, newTree->rightChild);
	}
}

/*************************************************************************************************************/
// һЩ���ܽӿ�
// ��������� depth()��Ա������ depthBinaryTree()˽�еݹ鷽��
template <class T>
int linkedBinaryTree<T>::depth() const
{
	return depthHelper(root);
}

template <class T>
int linkedBinaryTree<T>::depthHelper(binaryTreeNode<T>* node)
{
	if (node == nullptr)
		return 0;
	else
	{
		int leftDepth = depthHelper(node->leftChild);
		int rightDepth = depthHelper(node->rightChild);
		if (leftDepth > rightDepth)
			return (leftDepth + 1);
		else
			return (rightDepth + 1);
	}
}

// �������ڵ����
template <class T>
int linkedBinaryTree<T> :: nodeCount() const
{
	return nodeCountHelper(root);
}

template <class T>
int linkedBinaryTree<T> ::nodeCountHelper(binaryTreeNode<T>* node)
{
	if (node == nullptr)
		return 0;
	else
	{
		return nodeCountHelper(node->leftChild) +
			nodeCountHelper(node->rightChild) + 1;
	}
}

// Ҷ�ӽڵ����
template <class T>
int linkedBinaryTree<T> ::leadCount() const
{
	return leadCountHelper(root);
}
template <class T>
int linkedBinaryTree<T> :: leadCountHelper(binaryTreeNode<T>* node)
{
	if (node == nullptr) return 0;  // ��������� �Ż�0
	else
	{
		if (node->leftChild == nullptr && node->rightChild == nullptr)
			return 1;   // �ҵ�һ��Ҷ�ӽ׶Σ� ���� 1
		else
			return leadCountHelper(node->leftChild) +
			leadCountHelper(node->rightChild);
	}
}
#endif // !__LINKED_BINARY_TREE_H_