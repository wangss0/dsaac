

#ifndef __ALGRAPH_H_
#define __ALGRAPH_H_


#include <iostream>
#include <vector>

using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::vector;



// �����ߣ��Ľڵ�ṹ
// �߽ڵ�
struct ArcNode {
    int adjvex;         // �ñ���ָ��Ķ����λ��
    ArcNode* nextrarc;  // ָ����һ���ߵ�ָ��
    int info;           // �ͱ���ص���Ϣ

    ArcNode() : adjvex(-1), nextrarc(nullptr), info(0) {}
};



// �����ڽӱ��ʾ������������
// ����Ľṹ
template <class T>
struct VNode
{
    T data;     // ������Ϣ
    ArcNode* firstArc;      // ָ���һ�������ö���ıߵ�ָ��

    VNode() : data(T()), firstArc(nullptr) {}
    VNode(T theData) : data(theData), firstArc(nullptr) {}
    VNode(T theData, ArcNode* theFirstArc) : data(theData), firstArc(theFirstArc) {}
};



template <class T>
class ALGraph {
public:
    vector<VNode<T>> vertices;    // vertics -- vertex�ĸ����� �洢ͼ�Ķ���
    int vexNum;                 // ������
    int arcNum;                 // ����

public:
    ALGraph() : vexNum(0), arcNum(0) {}
    ALGraph(int theVexNum, int theArcNum) : vexNum(theVexNum), arcNum(theArcNum) {}

    // ��������ͼ
    void creatUDG();
    // ��ӡ����ͼ
    void printUDG();


private:
    int locateVex(VNode<T> node) const;   // ����ͼ�У��±�Ϊ index �Ķ���
};

template <class T>
int ALGraph<T> ::locateVex(VNode<T> node) const   // ����±�� 0 ��ʼ
{
    for (int index = 0; index < vexNum; index++)
    {
        if (vertices[index].data == node.data)
            return index;
    }

    cerr << "����Ķ��㣬 δ����";
    return -1;
}

// ��������ͼ
// 1. ȷ���ܶ����� �� �ܱ���
// 2. ���� �����
// 3. �����ڽӱ�
// ע�� ÿ�����㣬������Ե� �ڽ��ڵ㣨�ڽӱ�
template <class T>
void ALGraph<T> ::creatUDG()
{
    // ���������, ͷ�ڵ������
    for (int i = 0; i < vexNum; i++) {
        T value = T();
        cout << "�������" << i << "�������ֵ��";
        cin >> value;
        VNode<T> vertex(value);
        vertices.push_back(vertex);
    }


    // �����ڽӱ� ������
    for (int i = 0; i < arcNum; i++)
    {
        T srcValue = T();
        T destValue = T();
        cout << "�������" << i + 1 << "���ߵ���ʼ����ͽ������㣨�Կո�ָ�����";
        cin >> srcValue >> destValue;

        int srcIndex = locateVex(srcValue);
        int destIndex = locateVex(destValue);

        ArcNode* p1 = new ArcNode();            // ����һ���µı߽ڵ� *p1
        p1->adjvex = destIndex;                 // �ڽڵ����Ϊ destIndex
        p1->nextrarc = vertices[srcIndex].firstArc;
        vertices[srcIndex].firstArc = p1;       // ���½ڵ� *p1�� ���붥��vertices[srcIndex]�߱�ͷ��         // ͷ���뷨

        ArcNode* p2 = new ArcNode();            // ������һ���ԳƵ��µı߽ڵ� *p2
        p2->adjvex = srcIndex;                  // �ڽڵ����Ϊ srcIndex
        p2->nextrarc = vertices[destIndex].firstArc;
        vertices[destIndex].firstArc = p2;      // ���½ڵ� *p2 ���붥�� vertices[destIndex] �ı߱�ͷ��
    }

    // ���磬 ���� a b 
    // ab��һ���ߵ��������㣬 ab����
    // a �Ķ��㣬�� b�ı߽ڵ㣻 b �Ķ��㣬 �� a �ı߽ڵ�
    // 1. ���ҵ� a, b �����ֱ�ţ� �ڶ�����е�λ�ã� ������ָ��߽ڵ㣬 �߽ڵ����ָ��߽ڵ��ʱ�򣬿���ֱ��ָ��λ�ã�
    // 2. �� b �ı߽ڵ㣬 ��ӵ� a ��
    //      �߽ڵ������ʽ�洢�ṹ�� �� ���㿪ʼ�� ����ȫ����� ���� ���ڵ� ���㣨�߽ڵ㣩 ��λ��; (����߽ڵ���Ⱥ�˳�򣬲���Ҫ)
    //      �ʶ��� ��ʽ�洢�У� ��Ҫ��ȷ�� ����ָ��ĵ�һ���߽ڵ��λ�ã� ���� �߽ڵ� ָ�� ��һ���߽ڵ�
    //      ����ʹ�� ͷ���뷨
    //      
    //      ����һ���߽ڵ㣬��Ҫ����߽ڵ� ָ��� ���嶥�� ��λ��(adjvex)�� ����ֱ�Ӹ��� b ��λ��
    //      ȷ�� �ñ߽ڵ�ָ�����һ���߽ڵ��λ�ã� ������һ���߽ڵ��λ�ã�����ԭ������ ָ��� ��һ���ڵ��λ�ã� ��ͷ�巨��
    //      ȷ�� ���� a �ĵ�һ���߽���λ�ã� ���� a.firstArc ָ������µĴ����� �߽��

    // 3. �� a �ı߽ڵ㣬 ��ӵ� b ��
}

// ��ӡ����ͼ
template <class T>
void ALGraph<T> ::printUDG()
{
    for (int i = 0; i < vexNum; i++)
    {
        cout << "����: " << vertices[i].data << "�� �ڽӵ�Ϊ : ";

        while (vertices[i].firstArc != nullptr)
        {
            cout << vertices[i].firstArc->adjvex;
            // cout << vertices[vertices[i].firstArc->adjvex].data;
            vertices[i].firstArc = vertices[i].firstArc->nextrarc;
        }


        cout << endl;
    }
}


#endif // __ALGRAPH_H_
