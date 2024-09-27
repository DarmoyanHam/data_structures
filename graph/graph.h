#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

namespace gr{

class Graph{
public:
    Graph();
    ~Graph();
public:
    void addVertex(int);
    void addEdge(int, int);
    void clear();
    void print();
    void BFS(int stVert);
    void DFS(int stVert);
private:
    std::vector<std::vector<bool>> graph;
};

}

#include "graph.hpp"

#endif