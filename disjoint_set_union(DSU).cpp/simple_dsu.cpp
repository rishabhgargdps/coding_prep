#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int find(vector<int> &parent, int x)
{ //Worst case time complexity is in the case of chaining (O(n))
    if (parent[x] == x)
        return x;
    else
        return find(parent[x]);
}

void union(vector<int> &parent, int x, int y)
{ //Merging two disjoint set elements to form a single set; Time complexity : O(n);
    int x_rep = find(x);
    int y_rep = find(y);
    if (x_rep == y_rep)
        return;
    parent[y_rep] = x_rep;
}

int main()
{
    int n = 5;
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    union(1,4);
    return 0;
}