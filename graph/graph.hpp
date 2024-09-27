#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "graph.h"

gr::Graph::Graph()
{}

gr::Graph::~Graph()
{
    clear();
}

void gr::Graph::addVertex(int n = 1)
{
    graph.resize(graph.size() + n);
    for(int i = 0; i < graph.size(); ++i)
    {
        graph[i].resize(graph.size());
    }
}

void gr::Graph::addEdge(int u, int v)
{
    if(graph.size() <= u || graph.size() <= v || u < 0 || v < 0)
    {
        throw std::out_of_range("There are no so many vertices");
    }
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void gr::Graph::DFS(int stVert)
{
    if(stVert < 0 || stVert >= graph.size())
    {
        throw std::out_of_range("There are no so many vertices");
    }
    std::stack<int> st;
    std::vector<bool> visited(graph.size(), false);
    st.push(stVert);
    while(!st.empty())
    {
        int vertex = st.top();
        st.pop();
        if(!visited[vertex])
        {
            std::cout << vertex << " ";
            visited[vertex] = true;
        }
        for(int i = 0; i < graph.size(); ++i)
        {
            if(!visited[i] && graph[vertex][i] == 1)
            {
                st.push(i);
            }
        }
    }
    std::endl(std::cout);
}

void gr::Graph::BFS(int stVert)
{
    if(stVert < 0 || stVert >= graph.size())
    {
        throw std::out_of_range("There are no so many vertices");
    }
    std::queue<int> q;
    std::vector<bool> visited(graph.size(), false);
    q.push(stVert);
    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();
        std::cout << vertex << " ";
        visited[vertex] = true;
        for(int i = 0; i < graph.size(); ++i)
        {
            if(!visited[i] && graph[vertex][i] == 1)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    std::endl(std::cout);
}

void gr::Graph::clear()
{
    for(int i = 0; i < graph.size(); ++i)
    {
        graph[i].clear();
    }
    graph.clear();
}

void gr::Graph::print()
{
    for(int i = 0; i < graph.size(); ++i)
    {
        for(int j = 0; j < graph[i].size(); ++j)
        {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif