


#include "ALGraph.h"


void test01()
{
    ALGraph<char> G;
    G.arcNum = 5;
    G.vexNum = 6;
 
    VNode<char> node1('a');
    VNode<char> node2('b');
    G.vertices.push_back(node1);
    G.vertices.push_back(node2);

    cout << G.vertices[1].data << endl;

  
    /*ArcNode* p = G.vertices[1].firstArc;
    p->adjvex = 4;*/
}

void testUDG()
{
    ALGraph<int> graph(6, 6);
    graph.creatUDG();
    graph.printUDG();
    graph.generateAdjacencyMatrix();
    cout << "ÁÚ½Ó¾ØÕó£º" << endl;
    for (const auto& row : graph.adjacencyMatrix) {
        for (const auto& value : row) {
            cout << value << " ";
        }
        cout << endl;
    }


    graph.DFSTraversal();
    graph.BFSTraversal();
}

int main()
{
    // test01();
    testUDG();

    
    system("pause");
    return 0;
}




