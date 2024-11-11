#include <iostream>
#include "adj_list_graph.h"

int main()
{
    Graph g;
    g.addVertex(3);
    g.print();

    g.DFS(0);

    g.addEdge(0, 2);
    g.print();

    g.DFS(0);

    g.addEdge(1, 0);
    g.addVertex(2);
    g.addEdge(0, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.print();
    g.DFS(0);

    g.clear();
    g.print();

    return 0;
}