

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
    vector<vector<int>> adjacencyMatrix; // 邻接矩阵

public:
    ALGraph() : vexNum(0), arcNum(0) {}
    ALGraph(int theVexNum, int theArcNum) : vexNum(theVexNum), arcNum(theArcNum) {}

    
    void creatUDG();                // 创建无向图
    void printUDG();                // 打印无向图
    void generateAdjacencyMatrix(); // 生成邻接矩阵 
    
    void DFSTraversal();            // 深度优先搜索(Depth First Search, DFS)
    void DFSTraversal(int startIndex);
    void BFSTraversal();            // 广度优先遍历(Breadth First Search, BFS)
    

private:
    int locateVex(VNode<T> node) const;   // 返回图中，顶点 node 的位置
    void DFS(int v, vector<bool>& visited);
    void BFS(int v, vector<bool>& visited);
};


/********************************************************************************/
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
    // 2. 把 b 的边节点， 添加到 顶点a 中
    //      边节点采用链式存储结构， 以 顶点开始， 后面全是这个 顶点 相邻的 顶点（边节点） 的位置; (后面边节点的先后顺序，无所谓)
    //      故而， 链式存储中， 需要，确定 顶点指向的第一个边节点的位置， 还有 边节点 指向 下一个边节点
    //      这里使用 头插入法
    //      
    //      创建一个新的边节点，需要这个边节点 指向的 具体顶点 的位置(adjvex)， 这里直接赋上 b 的位置
    //      确定 该边节点指向的下一个边节点的位置； 这里下一个边节点的位置，就是原来顶点 指向的 第一个节点的位置； （头插法）
    //      确定 顶点 a 的第一个边界点的位置， 顶点 a.firstArc 指向这个新的创建的 边界点

    // 3. 把 a 的边节点， 添加到 顶点b 中

    
    // 顺便生成一个邻接矩阵
}



// 打印无向图
template <class T>
void ALGraph<T> ::printUDG()
{
    for (int i = 0; i < vexNum; i++)
    {
        cout << "顶点: " << vertices[i].data << "， 邻接点为 : ";

        ArcNode* p = vertices[i].firstArc;  // 使用临时指针变量， 不改变原来的值

        while (p != nullptr)
        {
            cout << p->adjvex;
            // cout << vertices[p->adjvex].data;
            p = p->nextrarc;
        }


        cout << endl;
    }
}

// 生成邻接矩阵
template <class T>
void ALGraph<T>::generateAdjacencyMatrix()
{
    adjacencyMatrix.resize(vexNum, vector<int>(vexNum, 0));

    for (int i = 0; i < vexNum; i++) {
        ArcNode* p = vertices[i].firstArc;
        while (p != nullptr) {
            int adjIndex = p->adjvex;
            adjacencyMatrix[i][adjIndex] = 1;
            p = p->nextrarc;
        }
    }
}


/********************************************************************************/
// DFS, 邻接矩阵 O(n^2)
template <class T>
void ALGraph<T>::DFS(int v, vector<bool>& visited)
{
    cout << vertices[v].data << " ";

    visited[v] = true;

    for (int i = 0; i < vexNum; i++)
    {
        if (adjacencyMatrix[v][i] == 1 && !visited[i])
            DFS(i, visited);
    }
}
// DFS 邻接表
// O(n + e),n 头节点， e 边节点 
//template <class T>
//void ALGraph<T>::DFS(int v, vector<bool>& visited)
//{
//    cout << vertices[v].data << " ";
//
//    visited[v] = true;
//
//    ArcNode* p = vertices[v].firstArc;
//    while (p != nullptr)
//    {
//        int adjIndex = p->adjvex;
//        if (!visited[adjIndex])
//            DFS(adjIndex, visited);
//        p = p->nextrarc;
//    }
//}
template <class T>
void ALGraph<T>::DFSTraversal()
{
    vector<bool> visited(vexNum, false);
    DFS(0, visited);

    // 非连通图
    //for (int i = 0; i < vexNum; i++)
    //{
    //    if (!visited[i])
    //        DFS(i, visited);
    //}

    cout << endl;
}


template <class T>
void ALGraph<T>::DFSTraversal(int startIndex)
{
    vector<bool> visited(vexNum, false);
    DFS(startIndex, visited);
    cout << endl;
}


#include <queue>
using std::queue;

template <class T>
void ALGraph<T>::BFS(int v, vector<bool>& visited)
{
    queue<int> q;
    cout << vertices[v].data << " ";
    visited[v] = true;
    q.push(v);      // v 入队

    while (!q.empty())
    {
        int front = q.front();  // 确定对头， “顶点”
        q.pop();    // 队头出队

        ArcNode* p = vertices[front].firstArc;  // 队头顶点的， 节点
        while (p != nullptr)
        {
            int adjIndex = p->adjvex;
            if (!visited[adjIndex])
            {
                cout << vertices[adjIndex].data << " "; // 没访问过，就访问
                visited[adjIndex] = true;               // 访问状态， true
                q.push(adjIndex);       // 当前 节点入队， 后面到表头时， 这就是顶点
            }
            p = p->nextrarc;    // 节点依次
        }   // 这个顶点， 后面的节点， 全部搞定
        // 外层 while 将这个对头， 顶点出队
    }
}

template <class T>
void ALGraph<T>::BFSTraversal()
{
    vector<bool> visited(vexNum, false);

    for (int i = 0; i < vexNum; i++)
    {
        if (!visited[i])
            BFS(i, visited);
    }

    cout << endl;
}
#endif // __ALGRAPH_H_;
