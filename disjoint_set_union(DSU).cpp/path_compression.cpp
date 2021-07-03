//here we update the parent of the node after finding it
//when we use both union by rank and path compression, time complexity is O(alpha(n)) where alpha(n) <=4 is the Inverse Ackermann function
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int find(vector<int> &parent, int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

int main()
{
    int n = 5;
    vector<int> parent(n);
    return 0;
}