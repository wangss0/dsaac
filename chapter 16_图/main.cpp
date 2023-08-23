


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

    ArcNode* p = G.vertices[1].firstArc;
    p->adjvex = 4;
}

void testUDG()
{
    ALGraph<char> graph(5, 6);
    graph.creatUDG();
    graph.printUDG();
}

int main()
{
    // test01();
    testUDG();

    
    system("pause");
    return 0;
}




