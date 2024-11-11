#ifndef ADJLIST_H
#define ADJLIST_H

#include <iostream>
#include <vector>

namespace adj_graph{

class Graph {
public:
    Graph(); // +
    ~Graph(); // 
public:
    void addVertex(int verts); // +
    void addEdge(int, int); // +
    void clear(); // +
    void print() const;// +
    void BFS(int stVert) const; // +
    void DFS(int stVert) const; // +
private:
    void DFSHelper(int stVert, std::vector<bool>& visited) const; // +
    void BFSHelper(int stVert, std::vector<bool>& visited) const; // +
private:
    std::vector<std::vector<int>> graph;
};

}

#include "adj_list_graph.hpp"

#endif