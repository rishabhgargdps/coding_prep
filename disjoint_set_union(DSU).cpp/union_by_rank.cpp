#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int find(vector<int> &parent, int x) // Time complexity is O(n);
{
    if (parent[x] == x)
        return x;
    else
        return find(parent[x]);
}

void union(vector<int> &parent, vector<int> &rank, int x, int y) //Time complexity is O(log n) now
{
    int x_rep = find(x);
    int y_rep = find(y);
    if (x_rep == y_rep)
        return;
    if (rank[x_rep] < rank[y_rep])
        parent[x_rep] = y_rep;
    else if (rank[y_rep] < rank[x_rep])
        parent[y_rep] = x_rep;
    else
    {
        parent[y_rep] = x_rep;
        rank[x_rep]++;
    }
}

int main()
{
    int n = 5;
    vector<int> parent(n);
    vector<int> rank(n, 0); //rank represents the height of the parent node in the tree representation within a forest.
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    return 0;
}