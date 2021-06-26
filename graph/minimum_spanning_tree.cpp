//defined only for undirected graphs (weighted and connected)
//spanning tree has no cycles; exactly (v-1) edges
//for a graph we have to find all possible spanning trees and then find the minimum out of them
//Prim's algorithm is a greedy algorithm to find the MST
//has two sets, in MST and not in MST
//we use a 2D adjacency matrix this time for implementing the UNDIRECTED graph
#include <iostream>
#include <bits/stdc++.h>
int primMST(const vector<vector<int>> &graph)
{
    const int v = graph.size();
    vector<int> key(v, INT_MAX);
    int res = 0;
    key[0] = 0;
    bool mSet[v] = {false};
    for (int count = 0; count < v; count++)
    {
        int u = -1;
        for (int i = 0; i < v; i++)
        {
            if (!mSet[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }
        mSet[u] = true;
        res = res + key[u];
        for (int i = 0; i < v; i++)
        {
            if (graph[u][i] ! = 0 && !mSet[i])
            {
                key[i] = min(key[i], graph[u][i]);
            }
        }
    }
    return res;
}

int main()
{
    const int v = 5;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    //add_edge function calls here
    int res = primMST(graph);
    cout << res;
    return 0;
}