


#include <iostream>
#include "binaryTreeNode.h"

// 创建二叉树
binaryTreeNode<char>* createBinaryTree()
{
    // 构造节点
    binaryTreeNode<char>* root = new binaryTreeNode<char>('A');
    binaryTreeNode<char>* node2 = new binaryTreeNode<char>('B');
    binaryTreeNode<char>* node3 = new binaryTreeNode<char>('C');
    binaryTreeNode<char>* node4 = new binaryTreeNode<char>('D');
    binaryTreeNode<char>* node5 = new binaryTreeNode<char>('E');
    binaryTreeNode<char>* node10 = new binaryTreeNode<char>('F');
    binaryTreeNode<char>* node11 = new binaryTreeNode<char>('G');

    // 构建二叉树结构
    root->leftChild = node2;
    root->rightChild = node3;
    node2->leftChild = node4;
    node2->rightChild = node5;
    node5->leftChild = node10;
    node5->rightChild = node11;
    return root;
}

// 先序遍历
// 若二叉树为空， 则空操作
// 若二叉树非空， 根、左、右
// P88, 89; page 278
template <class T>
void preOrder(binaryTreeNode<T>* node)
{
    if (node != nullptr)
    {
        // visit(node);
        std::cout << node->element << " ";  // 访问根节点
        preOrder(node->leftChild);          // 递归遍历左子树
        preOrder(node->rightChild);         // 递归遍历右子树
    }
}

// 中序遍历
// 若二叉树为空， 则空操作
// 若二叉树非空， 左、根、右
template <class T>
void inOrder(binaryTreeNode<T>* node)
{
    if (node != nullptr)
    {
        inOrder(node->leftChild);           // 递归遍历左子树
        // visit(node);
        std::cout << node->element << " ";  // 访问根节点
        inOrder(node->rightChild);          // 递归遍历右子树
    }
} 

// 后序遍历
// 若二叉树为空， 则空操作
// 若二叉树非空， 左、右、根
template <class T>
void postOrder(binaryTreeNode<T>* node)
{
    if (node != nullptr)
    {
        postOrder(node->leftChild);         // 递归遍历左子树
        postOrder(node->rightChild);        // 递归遍历右子树
        // visit(node);
        std::cout << node->element << " ";  // 访问根节点
    }
}

// 非递归实现中序遍历 ————栈
#include <stack>
template <class T>
void inOrderTraverse(binaryTreeNode<T>* node)
{
    std::stack<binaryTreeNode<T>*> s;
    binaryTreeNode<T>* p = node;

    while (p != nullptr || !s.empty())
    {
        // 将左子树节点依次入栈
        while (p != nullptr)
        {
            s.push(p);
            p = p->leftChild;
        }

        // 弹出栈顶节点并访问
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            std::cout << p->element << " ";

            // 切换到右子树
            p = p->rightChild;
        }
    }
}

// 非递归层次遍历 ———— 队列
#include <deque>
template <class T>
void levelOrder(binaryTreeNode<T>* node)
{
    binaryTreeNode<T>* p = node;
    std::deque<binaryTreeNode<T>*> qu;
    qu.push_back(node);
    while (!qu.empty())
    {
        p = qu.front();
        std::cout << p->element << " ";
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



// 二叉树的建立
// ABC##DE#G##F###, 先序遍历， #代表空
template <class T>
binaryTreeNode<T>* createBinaryTree2()
{
    char ch = ' ';
    std::cin >> ch;
    if (ch == '#') { return nullptr; }
    else
    {
        binaryTreeNode<T>* node = new binaryTreeNode<T>(ch);
        node->leftChild = createBinaryTree2<T>();
        node->rightChild = createBinaryTree2<T>();
        return node;
    }
}


// 复制二叉树
// 新的树作为引用指针传递（binaryTreeNode<T>*& newTree），是因为需要修改传入的指针，使其指向复制后的新树。
// 使用普通指针（binaryTreeNode<T>* newTree），那么在函数内部对指针的修改将不会影响函数外部的指针。
template <class T>
void copyBinaryTree(binaryTreeNode<T>* tree, binaryTreeNode<T>*& newTree)
{
    if (tree == nullptr)
    {
        newTree = nullptr;
    }
    else
    {
        newTree = new binaryTreeNode<T>();
        newTree->element = tree->element;
        copyBinaryTree(tree->leftChild, newTree->leftChild);
        copyBinaryTree(tree->rightChild, newTree->rightChild);
    }
}

// 计算二叉树深度
template<class T>
int depthBinartTree(binaryTreeNode<T>* node)
{
    if (node == nullptr) return 0;
    else
    {
        int m = depthBinartTree(node->leftChild);
        int n = depthBinartTree(node->rightChild);
        if (m > n) return (m + 1);
        else return (n + 1);
    }
}

// 二叉树节点个数
template <class T>
int nodeCountBinaryTree(binaryTreeNode<T>* node)
{
    if (node == nullptr)
        return 0;
    else
    {
        return nodeCountBinaryTree(node->leftChild) +
            nodeCountBinaryTree(node->rightChild) + 1;
    }
}

// 叶子节点个数
template <class T>
int leadCountBinaryTree(binaryTreeNode<T>* node)
{
    if (node == nullptr) return 0;  // 如果空树， 放回0
    else
    {
        if (node->leftChild == nullptr && node->rightChild == nullptr)
            return 1;   // 找到一个叶子阶段， 返回 1
        else
            return leadCountBinaryTree(node->leftChild) +
            leadCountBinaryTree(node->rightChild);
    }
}

void testBinaryTree()
{
    binaryTreeNode<char>* theTreeRoot = createBinaryTree();
    std::cout << "先序遍历 : ";
    preOrder<char>(theTreeRoot);    // ABDEFGC

    std::cout << std::endl;
    std::cout << "中序遍历 : ";
    inOrder<char>(theTreeRoot);

    std::cout << std::endl;
    std::cout << "后序遍历 : ";
    postOrder<char>(theTreeRoot);

    std::cout << std::endl;
    std::cout << "非递归中序遍历 : ";
    inOrderTraverse<char>(theTreeRoot);

    std::cout << std::endl;
    std::cout << "层次遍历 : ";
    levelOrder<char>(theTreeRoot);


    std::cout << std::endl;
    std::cout << "二叉树建立 : ";    // ABC##DE#G##F###
    binaryTreeNode<char>* creatTree = createBinaryTree2<char>();
    preOrder(creatTree);    //  A B C D E G F 

    std::cout << std::endl;
    std::cout << "二叉树复制 : ";
    binaryTreeNode<char>* newTree = new binaryTreeNode<char>();
    copyBinaryTree(creatTree, newTree);
    preOrder(newTree);  //  A B C D E G F

    std::cout << std::endl;
    std::cout << "二叉树深度 : ";
    std::cout << depthBinartTree<char>(theTreeRoot);

    std::cout << std::endl;
    std::cout << "二叉树节点统计 : ";
    std::cout << nodeCountBinaryTree<char>(theTreeRoot);

    std::cout << std::endl;
    std::cout << "二叉树叶子节点统计 : ";
    std::cout << leadCountBinaryTree<char>(theTreeRoot);
}



int main()
{
    testBinaryTree();
    system("pause");
    return 0;
}