#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool binary[M][N]; //input matrix

struct TrieNode
{
    TrieNode *child[2];
    TrieNode()
    {
        child[0] = NULL;
        child[1] = NULL;
    }
}

bool insert(TrieNode *root, int row)
{
    TrieNode *curr = root;
    bool flag = false;
    //Processing
    for (int i = 0; i < N; i++)
    {
        int index = binary[row][i];
        if (curr->child[index] == NULL)
        {
            curr->child[index] = new TrieNode();
            flag = true;
        }
        curr = curr->child[index];
    }
    return flag;
}

int main()
{
    int res = 0;
    TrieNode *root = new TrieNode();
    for (int row = 0; row < M; row++)
    {
        if (insert(root, row))
            res++;
    }
    cout << res;
    return 0;
}