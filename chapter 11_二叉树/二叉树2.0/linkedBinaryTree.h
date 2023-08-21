



#ifndef __LINKED_BINARY_TREE_H_
#define __LINKED_BINARY_TREE_H_

#include "binaryTreeNode.h"
#include <iostream>


template <class T>
class linkedBinaryTree 
{
private:
	binaryTreeNode<T>* root = nullptr;			// 指向树根的指针

public:
	linkedBinaryTree() {};
	linkedBinaryTree(const linkedBinaryTree<T>& otherTree);
	void creatRoot(binaryTreeNode<T>* theRoot) { root = theRoot; }

	void preOrderTraversal() const;				// 前序遍历
	void inOrderTraversal() const;				// 中序遍历
	void postOrderTraversal() const;			// 后序遍历
	void levelOrderTraversal() const;			// 层次遍历

	void createTree();							// 建立二叉树
	
	// 一些功能接口
	int depth() const;			// 二叉树深度
	int nodeCount() const;		// 二叉树节点个数
	int leadCount() const;		// 叶子节点个数

private:
	static void visit(binaryTreeNode<T>*);			// 访问节点函数
	static void (*visitPtr)(binaryTreeNode<T>*);	// 静态函数指针

	// 具体的遍历方法的实现
	static void preOrder(binaryTreeNode<T>* t);
	static void inOrder(binaryTreeNode<T>* t);
	static void postOrder(binaryTreeNode<T>* t);
	static void levelOrder(binaryTreeNode<T>* t);

	// 构造二叉树的辅助方法
	static binaryTreeNode<T>* createTreeHelper();

	static void copyBinaryTree(binaryTreeNode<T>* tree, binaryTreeNode<T>*& newTree);

	// 一些功能接口
	static int depthHelper(binaryTreeNode<T>* node);
	static int nodeCountHelper(binaryTreeNode<T>* node);
	static int leadCountHelper(binaryTreeNode<T>* node);

};


/*************************************************************************************************************/
// 函数可直接使用的遍历方法
// 这里将 visit 和 具体的遍历实现分开实现， 使得代码更加模块化和灵活
template<class T>
void linkedBinaryTree<T>::preOrderTraversal() const
{
	visitPtr = visit; // 将静态函数指针赋值为 visit
	// 执行前序遍历
	// 假设 root 是树根节点指针
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
// 具体的遍历方法的实现
template <class T>
void linkedBinaryTree<T> ::preOrder(binaryTreeNode<T>* t)
{
	// 前序遍历的具体方法
	if (t != nullptr)
	{
		linkedBinaryTree<T> ::visitPtr(t);
		preOrder(t->leftChild);          // 递归遍历左子树
		preOrder(t->rightChild);         // 递归遍历右子树
	}
}
template <class T>
void linkedBinaryTree<T> ::inOrder(binaryTreeNode<T>* t)
{
	// 中序遍历的具体方法
	if (t != nullptr)
	{
		inOrder(t->leftChild);          // 递归遍历左子树
		linkedBinaryTree<T> ::visitPtr(t);
		inOrder(t->rightChild);         // 递归遍历右子树
	}
}
template <class T>
void linkedBinaryTree<T> ::postOrder(binaryTreeNode<T>* t)
{
	// 后序遍历的具体方法
	if (t != nullptr)
	{
		postOrder(t->leftChild);          // 递归遍历左子树
		postOrder(t->rightChild);         // 递归遍历右子树
		linkedBinaryTree<T> ::visitPtr(t);
	}
}
// 非递归层次遍历 ―――― 队列
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
// 静态函数指针 visitPtr 在这个示例中主要用于存储一个指向特定类型的静态成员函数的地址。通过使用静态函数指针，你可以在类的内部或其他适当的位置将其赋值为对应的静态成员函数，并在需要的时候通过该指针调用相关的函数。
// 在这个示例中，visitPtr 用来存储访问节点的函数 visit 的地址。通过将 visitPtr 初始化为 nullptr，你可以检查它是否已经指向了有效的函数地址。然后，在 inorderTraversal() 函数中，我们将 visitPtr 赋值为 visit，以便在中序遍历时使用 visitPtr 调用访问节点的功能。
// 静态函数指针的一个常见用途是实现回调函数。通过使用静态函数指针，可以在不修改类定义的情况下，将类与其他函数或对象进行解耦，实现灵活的函数回调机制。
template<class T>
void linkedBinaryTree<T>::visit(binaryTreeNode<T>* x)
{
	// 访问节点 x, 输出element 域
	std::cout << x->element << " ";
}

template<class T>
void (*linkedBinaryTree<T>::visitPtr)(binaryTreeNode<T>*) = nullptr;




/*************************************************************************************************************/
// 创建二叉树
/* 将创建二叉树的过程分为createTree()和createTreeHelper()两个函数
* createTree()是对外提供的接口函数，用户可以通过调用该函数来创建二叉树。
* 将第一个节点作为“根节点”
* 
* createTreeHelper()是一个递归函数，用于递归创建二叉树的节点。
* 如果是叶子节点，则返回空指针；否则，创建一个新的binaryTreeNode节点，将字符作为节点元素，并递归地调用自身来创建左子树和右子树。
*/
template <class T>
void linkedBinaryTree<T>::createTree()
{
	char ch;

	std::cout << "请输入二叉树的先序遍历序列（空节点用#表示）：" << std::endl;

	std::cin >> ch;
	if (ch == '#') {
		return;	
	}
	root = new binaryTreeNode<T>(ch);

	// 递归创建左子树
	root->leftChild = createTreeHelper();

	// 递归创建右子树
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

	// 递归连接左子树和右子树
	node->leftChild = createTreeHelper();
	node->rightChild = createTreeHelper();

	return node;
}


/*************************************************************************************************************/
// 拷贝构造, 分块实现
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
// 一些功能接口
// 二叉树深度 depth()成员函数， depthBinaryTree()私有递归方法
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

// 二叉树节点个数
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

// 叶子节点个数
template <class T>
int linkedBinaryTree<T> ::leadCount() const
{
	return leadCountHelper(root);
}
template <class T>
int linkedBinaryTree<T> :: leadCountHelper(binaryTreeNode<T>* node)
{
	if (node == nullptr) return 0;  // 如果空树， 放回0
	else
	{
		if (node->leftChild == nullptr && node->rightChild == nullptr)
			return 1;   // 找到一个叶子阶段， 返回 1
		else
			return leadCountHelper(node->leftChild) +
			leadCountHelper(node->rightChild);
	}
}
#endif // !__LINKED_BINARY_TREE_H_