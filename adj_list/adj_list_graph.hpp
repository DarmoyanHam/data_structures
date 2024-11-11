#ifndef ADJLIST_HPP
#define ADJLIST_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "adj_list_graph.h"

using namespace adj_graph;

Graph::Graph()
{}

Graph::~Graph()
{
    clear();
}

void Graph::addVertex(int n = 1)
{
    for(int i = 0; i < n; ++i)
    {
        graph.push_back({});
    }
}

void Graph::addEdge(int u, int v)
{
    if(graph.size() <= u || graph.size() <= v || u < 0 || v < 0)
    {
        throw std::out_of_range("There are no so many vertices");
    }
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void Graph::DFS(int stVert) const
{
    if (stVert < 0 || stVert >= graph.size())
    {
        throw std::out_of_range("There are not that many vertices");
    }

    std::vector<bool> visited(graph.size(), false);

    DFSHelper(stVert, visited);

    for (int i = 0; i < graph.size(); ++i)
    {
        if (!visited[i])
        {
            DFSHelper(i, visited);
        }
    }
    std::cout << std::endl;
}

void Graph::DFSHelper(int stVert, std::vector<bool>& visited) const
{
    std::stack<int> st;
    st.push(stVert);

    while (!st.empty())
    {
        int vertex = st.top();
        st.pop();

        if (!visited[vertex])
        {
            std::cout << vertex << " ";
            visited[vertex] = true;

            for (int i = graph[vertex].size() - 1; i >= 0; --i)
            {
                int adj = graph[vertex][i];
                if (!visited[adj])
                {
                    st.push(adj);
                }
            }
        }
    }
}


void Graph::BFS(int stVert) const
{
    if (stVert < 0 || stVert >= graph.size())
    {
        throw std::out_of_range("There are not that many vertices");
    }

    std::vector<bool> visited(graph.size(), false);
    
    
    BFSHelper(stVert, visited);
    for (int i = 0; i < graph.size(); ++i)
    {
        if (!visited[i])
        {
            BFSHelper(i, visited);
        }
    }
    std::cout << std::endl;
}

void Graph::BFSHelper(int stVert, std::vector<bool>& visited) const
{
    std::queue<int> q;
    q.push(stVert);
    visited[stVert] = true;

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        std::cout << vertex << " ";

        for (int i = 0; i < graph[vertex].size(); ++i)
        {
            int adj = graph[vertex][i];
            if (!visited[adj])
            {
                q.push(adj);
                visited[adj] = true;
            }
        }
    }
}

void Graph::clear()
{
    for(int i = 0; i < graph.size(); ++i)
    {
        graph[i].clear();
    }
    graph.clear();
}

void Graph::print() const
{
    for(int i = 0; i < graph.size(); ++i)
    {
        std::cout << i << ":" << " ";
        for(int j = 0; j < graph[i].size(); ++j)
        {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif