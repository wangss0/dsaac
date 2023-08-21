


#include <iostream>
#include "binaryTreeNode.h"
#include "linkedBinaryTree.h"

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



void testBinaryTree()
{
    binaryTreeNode<char>* theTreeRoot = createBinaryTree();
    linkedBinaryTree<char> myTree;
    myTree.creatRoot(theTreeRoot);
    
    // ABD##EF##G##C##
    // myTree.createTree();
    
    // 将前面的 myTree 改为 myTreeTest, 测试拷贝构造函数
    // linkedBinaryTree<char> myTree = myTreeTest;
    // linkedBinaryTree<char> myTree = myTreeTest;

    // 前序遍历
    std::cout << "前序遍历结果：";
     myTree.preOrderTraversal();
    std::cout << std::endl;

    // 中序遍历
    std::cout << "中序遍历结果：";
    myTree.inOrderTraversal();
    std::cout << std::endl;

    // 后序遍历
    std::cout << "后序遍历结果：";
    myTree.postOrderTraversal();
    std::cout << std::endl;

    // 层次遍历
    std::cout << "层次遍历结果：";
    myTree.levelOrderTraversal();
    std::cout << std::endl;

    // 二叉树深度
    std::cout << "二叉树深度：";
    std::cout << myTree.depth();
    std::cout << std::endl;

    // 二叉树节点个数
    std::cout << "二叉树节点个数：";
    std::cout << myTree.nodeCount();
    std::cout << std::endl;
    
    // 二叉树叶子节点个数
    std::cout << "二叉树叶子节点个数：";
    std::cout << myTree.leadCount();
    std::cout << std::endl;
}



int main()
{
    testBinaryTree();
    system("pause");
    return 0;
}