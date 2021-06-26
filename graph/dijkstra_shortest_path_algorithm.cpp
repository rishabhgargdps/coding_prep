//given a source, find the shortest path from the source to all the other vertices in the graph
//does not work for negative weights

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstraShortestPath(vector<vector<int>> &graph, int s)
{
    int v = graph.size();
    vector<int> dist(v, INT_MAX);
    dist[s] = 0;
    vector<bool> finalised[v] = {false};
    for (int count = 0; count < v - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < v; i++)
        { //this loop can be replaced by priority queue
            if (!finalised[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }
        finalised[u] = true;
        for (int i = 0; i < v; i++)
        {
            if (graph[u][i] != 0 && finalised[i] == false)
            {
                dist[i] = min(dist[i], dist[u] + graph[u][i]);
            }
        }
    }

    return dist;
}

int main()
{
    int v = 5;
    int s = 0;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    //add_edge function calls here
    vector<int> res = dijkstraShortestPath(graph, s);
    //res has the result
    return 0;
}