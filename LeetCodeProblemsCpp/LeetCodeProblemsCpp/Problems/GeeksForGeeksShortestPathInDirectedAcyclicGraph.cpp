#include "GeeksForGeeksShortestPathInDirectedAcyclicGraph.h"

#include <map>
#include <queue>
#include <stack>

#include "Auxilaries.h"

#pragma region  TopologicalSorting
std::vector<int> GeeksForGeeksShortestPathInDirectedAcyclicGraph::shortestPath(
    int V, int E, std::vector<std::vector<int>>& edges)
{
    std::map<int, std::map<int, int>> adjPlus;
    for (auto edge : edges)
    {
        if (adjPlus.find(edge[0]) == adjPlus.end())
            adjPlus[edge[0]] = std::map<int, int>();
        adjPlus[edge[0]][edge[1]] = edge[2];
    }
    bool visited[V] = {false};
    std::stack<int> topoStack;
    for (int i = 0; i < V; i++)
    {
        TopologicalSort(adjPlus, visited, topoStack, i);
    }
    int maxValue = std::numeric_limits<int>::max();
    std::vector<int> distances;
    distances.reserve(V);
    distances.push_back(0);
    for (int i=1; i<V; i++)
    {
        distances.push_back(maxValue);
    }
    while (!topoStack.empty())
    {
        int vertex = topoStack.top();
        topoStack.pop();
        if (distances[vertex] == maxValue)
            continue;
        for (auto vert : adjPlus[vertex])
        {
            if (distances[vert.first] <= distances[vertex] + vert.second)
                continue;
            distances[vert.first] = distances[vertex] + vert.second;
        }
    }
    for (int i=0; i < V; i++)
    {
        if (distances[i] < maxValue)
            continue;
        distances[i] = -1;
    }
    return distances;
}

void GeeksForGeeksShortestPathInDirectedAcyclicGraph::TopologicalSort
(std::map<int, std::map<int, int>>& adjPlus, bool* visited, std::stack<int>& topoStack, int vertex)
{
    if (visited[vertex])
        return;
    visited[vertex] = true;
    for (auto vert : adjPlus[vertex])
    {
        TopologicalSort(adjPlus, visited, topoStack, vert.first);
    }
    topoStack.push(vertex);
}
#pragma endregion


#pragma region  BFS
// std::vector<int> GeeksForGeeksShortestPathInDirectedAcyclicGraph::shortestPath(int V, int E, std::vector<std::vector<int>>& edges)
// {
//     std::map<int, std::map<int, int>> adjPlus;
//
//
//     int maxValue = std::numeric_limits<int>::max();
//
//
//     for (int i = 0; i < E; i++)
//     {
//         int u = edges[i][0], v = edges[i][1], weight = edges[i][2];
//
//         if (adjPlus[u].find(v) != adjPlus[u].end())
//         {
//             adjPlus[u][v] = std::min(adjPlus[u][v], weight);
//         }
//         else
//         {
//             adjPlus[u][v] = weight;
//         }
//     }
//     std::vector<int> result(V, maxValue);
//     result[0] = 0;
//     std::queue<int> currentLayer;
//     currentLayer.push(0);
//
//     while (!currentLayer.empty())
//     {
//         int currentVertex = currentLayer.front();
//         currentLayer.pop();
//
//
//         if (adjPlus.find(currentVertex) == adjPlus.end()) continue;
//
//
//         for (auto it = adjPlus[currentVertex].begin(); it != adjPlus[currentVertex].end(); ++it)
//         {
//             int neighbor = it->first;
//             int weight = it->second;
//
//             if (result[currentVertex] + weight < result[neighbor])
//             {
//                 result[neighbor] = result[currentVertex] + weight;
//                 currentLayer.push(neighbor);
//             }
//         }
//     }
//     for (int i = 0; i < V; i++)
//     {
//         if (result[i] == maxValue) result[i] = -1;
//     }
//     return result;
// }

#pragma endregion


void GeeksForGeeksShortestPathInDirectedAcyclicGraph::Run()
{
    int v = 6;
    int e = 7;
    std::vector<std::vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}
    };
    auto result = shortestPath(v, e, edges);
    Auxilaries::PrintVector(result);
}
