


#include <iostream>
#include "binaryTreeNode.h"
#include "linkedBinaryTree.h"

// ����������
binaryTreeNode<char>* createBinaryTree()
{
    // ����ڵ�
    binaryTreeNode<char>* root = new binaryTreeNode<char>('A');
    binaryTreeNode<char>* node2 = new binaryTreeNode<char>('B');
    binaryTreeNode<char>* node3 = new binaryTreeNode<char>('C');
    binaryTreeNode<char>* node4 = new binaryTreeNode<char>('D');
    binaryTreeNode<char>* node5 = new binaryTreeNode<char>('E');
    binaryTreeNode<char>* node10 = new binaryTreeNode<char>('F');
    binaryTreeNode<char>* node11 = new binaryTreeNode<char>('G');

    // �����������ṹ
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
    
    // ��ǰ��� myTree ��Ϊ myTreeTest, ���Կ������캯��
    // linkedBinaryTree<char> myTree = myTreeTest;
    // linkedBinaryTree<char> myTree = myTreeTest;

    // ǰ�����
    std::cout << "ǰ����������";
     myTree.preOrderTraversal();
    std::cout << std::endl;

    // �������
    std::cout << "������������";
    myTree.inOrderTraversal();
    std::cout << std::endl;

    // �������
    std::cout << "������������";
    myTree.postOrderTraversal();
    std::cout << std::endl;

    // ��α���
    std::cout << "��α��������";
    myTree.levelOrderTraversal();
    std::cout << std::endl;

    // ���������
    std::cout << "��������ȣ�";
    std::cout << myTree.depth();
    std::cout << std::endl;

    // �������ڵ����
    std::cout << "�������ڵ������";
    std::cout << myTree.nodeCount();
    std::cout << std::endl;
    
    // ������Ҷ�ӽڵ����
    std::cout << "������Ҷ�ӽڵ������";
    std::cout << myTree.leadCount();
    std::cout << std::endl;
}



int main()
{
    testBinaryTree();
    system("pause");
    return 0;
}