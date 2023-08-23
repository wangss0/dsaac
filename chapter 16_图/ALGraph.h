

#ifndef __ALGRAPH_H_
#define __ALGRAPH_H_


#include <iostream>
#include <vector>

using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::vector;



// 弧（边）的节点结构
// 边节点
struct ArcNode {
    int adjvex;         // 该边所指向的顶点的位置
    ArcNode* nextrarc;  // 指向下一条边的指针
    int info;           // 和边相关的信息

    ArcNode() : adjvex(-1), nextrarc(nullptr), info(0) {}
};



// 采用邻接表表示法创建无向网
// 顶点的结构
template <class T>
struct VNode
{
    T data;     // 顶点信息
    ArcNode* firstArc;      // 指向第一条依附该顶点的边的指针

    VNode() : data(T()), firstArc(nullptr) {}
    VNode(T theData) : data(theData), firstArc(nullptr) {}
    VNode(T theData, ArcNode* theFirstArc) : data(theData), firstArc(theFirstArc) {}
};



template <class T>
class ALGraph {
public:
    vector<VNode<T>> vertices;    // vertics -- vertex的复数； 存储图的顶点
    int vexNum;                 // 顶点数
    int arcNum;                 // 弧数

public:
    ALGraph() : vexNum(0), arcNum(0) {}
    ALGraph(int theVexNum, int theArcNum) : vexNum(theVexNum), arcNum(theArcNum) {}

    // 创建无向图
    void creatUDG();
    // 打印无向图
    void printUDG();


private:
    int locateVex(VNode<T> node) const;   // 返回图中，下表为 index 的顶点
};

template <class T>
int ALGraph<T> ::locateVex(VNode<T> node) const   // 这个下标从 0 开始
{
    for (int index = 0; index < vexNum; index++)
    {
        if (vertices[index].data == node.data)
            return index;
    }

    cerr << "输入的顶点， 未创建";
    return -1;
}

// 创建无向图
// 1. 确定总顶点数 和 总边数
// 2. 建立 顶点表
// 3. 创建邻接表
// 注： 每个顶点，有其各自的 邻近节点（邻接表）
template <class T>
void ALGraph<T> ::creatUDG()
{
    // 建立顶点表, 头节点的数组
    for (int i = 0; i < vexNum; i++) {
        T value = T();
        cout << "请输入第" << i << "个顶点的值：";
        cin >> value;
        VNode<T> vertex(value);
        vertices.push_back(vertex);
    }


    // 创建邻接表， 单链表
    for (int i = 0; i < arcNum; i++)
    {
        T srcValue = T();
        T destValue = T();
        cout << "请输入第" << i + 1 << "条边的起始顶点和结束顶点（以空格分隔）：";
        cin >> srcValue >> destValue;

        int srcIndex = locateVex(srcValue);
        int destIndex = locateVex(destValue);

        ArcNode* p1 = new ArcNode();            // 生成一个新的边节点 *p1
        p1->adjvex = destIndex;                 // 邻节点序号为 destIndex
        p1->nextrarc = vertices[srcIndex].firstArc;
        vertices[srcIndex].firstArc = p1;       // 将新节点 *p1， 插入顶点vertices[srcIndex]边表头部         // 头插入法

        ArcNode* p2 = new ArcNode();            // 生成另一个对称的新的边节点 *p2
        p2->adjvex = srcIndex;                  // 邻节点序号为 srcIndex
        p2->nextrarc = vertices[destIndex].firstArc;
        vertices[destIndex].firstArc = p2;      // 将新节点 *p2 插入顶点 vertices[destIndex] 的边表头部
    }

    // 例如， 输入 a b 
    // ab是一条边的两个顶点， ab相邻
    // a 的顶点，有 b的边节点； b 的顶点， 有 a 的边节点
    // 1. 先找到 a, b 的数字编号， 在顶点表中的位置， （顶点指向边节点， 边节点继续指向边节点的时候，可以直接指向位置）
    // 2. 把 b 的边节点， 添加到 a 中
    //      边节点采用链式存储结构， 以 顶点开始， 后面全是这个 顶点 相邻的 顶点（边节点） 的位置; (后面边节点的先后顺序，不重要)
    //      故而， 链式存储中， 需要，确定 顶点指向的第一个边节点的位置， 还有 边节点 指向 下一个边节点
    //      这里使用 头插入法
    //      
    //      创建一个边节点，需要这个边节点 指向的 具体顶点 的位置(adjvex)， 这里直接赋上 b 的位置
    //      确定 该边节点指向的下一个边节点的位置； 这里下一个边节点的位置，就是原来顶点 指向的 第一个节点的位置； （头插法）
    //      确定 顶点 a 的第一个边界点的位置， 顶点 a.firstArc 指向这个新的创建的 边界点

    // 3. 把 a 的边节点， 添加到 b 中
}

// 打印无向图
template <class T>
void ALGraph<T> ::printUDG()
{
    for (int i = 0; i < vexNum; i++)
    {
        cout << "顶点: " << vertices[i].data << "， 邻接点为 : ";

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
