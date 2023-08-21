


#include <iostream>
#include "binaryTreeNode.h"

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

// �������
// ��������Ϊ�գ� ��ղ���
// ���������ǿգ� ��������
// P88, 89; page 278
template <class T>
void preOrder(binaryTreeNode<T>* node)
{
    if (node != nullptr)
    {
        // visit(node);
        std::cout << node->element << " ";  // ���ʸ��ڵ�
        preOrder(node->leftChild);          // �ݹ����������
        preOrder(node->rightChild);         // �ݹ����������
    }
}

// �������
// ��������Ϊ�գ� ��ղ���
// ���������ǿգ� �󡢸�����
template <class T>
void inOrder(binaryTreeNode<T>* node)
{
    if (node != nullptr)
    {
        inOrder(node->leftChild);           // �ݹ����������
        // visit(node);
        std::cout << node->element << " ";  // ���ʸ��ڵ�
        inOrder(node->rightChild);          // �ݹ����������
    }
} 

// �������
// ��������Ϊ�գ� ��ղ���
// ���������ǿգ� ���ҡ���
template <class T>
void postOrder(binaryTreeNode<T>* node)
{
    if (node != nullptr)
    {
        postOrder(node->leftChild);         // �ݹ����������
        postOrder(node->rightChild);        // �ݹ����������
        // visit(node);
        std::cout << node->element << " ";  // ���ʸ��ڵ�
    }
}

// �ǵݹ�ʵ��������� ��������ջ
#include <stack>
template <class T>
void inOrderTraverse(binaryTreeNode<T>* node)
{
    std::stack<binaryTreeNode<T>*> s;
    binaryTreeNode<T>* p = node;

    while (p != nullptr || !s.empty())
    {
        // ���������ڵ�������ջ
        while (p != nullptr)
        {
            s.push(p);
            p = p->leftChild;
        }

        // ����ջ���ڵ㲢����
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            std::cout << p->element << " ";

            // �л���������
            p = p->rightChild;
        }
    }
}

// �ǵݹ��α��� �������� ����
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



// �������Ľ���
// ABC##DE#G##F###, ��������� #�����
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


// ���ƶ�����
// �µ�����Ϊ����ָ�봫�ݣ�binaryTreeNode<T>*& newTree��������Ϊ��Ҫ�޸Ĵ����ָ�룬ʹ��ָ���ƺ��������
// ʹ����ָͨ�루binaryTreeNode<T>* newTree������ô�ں����ڲ���ָ����޸Ľ�����Ӱ�캯���ⲿ��ָ�롣
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

// ������������
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

// �������ڵ����
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

// Ҷ�ӽڵ����
template <class T>
int leadCountBinaryTree(binaryTreeNode<T>* node)
{
    if (node == nullptr) return 0;  // ��������� �Ż�0
    else
    {
        if (node->leftChild == nullptr && node->rightChild == nullptr)
            return 1;   // �ҵ�һ��Ҷ�ӽ׶Σ� ���� 1
        else
            return leadCountBinaryTree(node->leftChild) +
            leadCountBinaryTree(node->rightChild);
    }
}

void testBinaryTree()
{
    binaryTreeNode<char>* theTreeRoot = createBinaryTree();
    std::cout << "������� : ";
    preOrder<char>(theTreeRoot);    // ABDEFGC

    std::cout << std::endl;
    std::cout << "������� : ";
    inOrder<char>(theTreeRoot);

    std::cout << std::endl;
    std::cout << "������� : ";
    postOrder<char>(theTreeRoot);

    std::cout << std::endl;
    std::cout << "�ǵݹ�������� : ";
    inOrderTraverse<char>(theTreeRoot);

    std::cout << std::endl;
    std::cout << "��α��� : ";
    levelOrder<char>(theTreeRoot);


    std::cout << std::endl;
    std::cout << "���������� : ";    // ABC##DE#G##F###
    binaryTreeNode<char>* creatTree = createBinaryTree2<char>();
    preOrder(creatTree);    //  A B C D E G F 

    std::cout << std::endl;
    std::cout << "���������� : ";
    binaryTreeNode<char>* newTree = new binaryTreeNode<char>();
    copyBinaryTree(creatTree, newTree);
    preOrder(newTree);  //  A B C D E G F

    std::cout << std::endl;
    std::cout << "��������� : ";
    std::cout << depthBinartTree<char>(theTreeRoot);

    std::cout << std::endl;
    std::cout << "�������ڵ�ͳ�� : ";
    std::cout << nodeCountBinaryTree<char>(theTreeRoot);

    std::cout << std::endl;
    std::cout << "������Ҷ�ӽڵ�ͳ�� : ";
    std::cout << leadCountBinaryTree<char>(theTreeRoot);
}



int main()
{
    testBinaryTree();
    system("pause");
    return 0;
}