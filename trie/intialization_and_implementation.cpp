#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    bool isEnd = false;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            isEnd = false;
            child[i] = NULL;
        }
    }
}

bool search(string &key)
{
    TrieNode *curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        if (curr->child[key[i] - 'a'] == NULL)
            return false;
        curr = curr->child[key[i] - 'a'];
    }
    return curr->isEnd;
}

void insert(string &key)
{
    TrieNode *curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        if (curr->child[key[i] - 'a'] == NULL)
        {
            curr->child[key[i] - 'a'] = new TrieNode();
        }
        curr = curr->child[key[i] - 'a'];
    }
    curr->isEnd = true;
}

bool isEmpty(TrieNode* root) {
    for(int i=0; i<26; i++) {
        if(root->child[i] != NULL) return false;
    }
    return true;
}

TrieNode* deleteNode(TreeNode* root, string &key, int i) {
    //Base cases
    if(root == NULL) return NULL;
    if(i == key.length()) {
        root->isEnd = false;
        if(isEmpty(root)) {
            delete root;
            root = NULL;
        }
        return root;
    }
    //Recursive step
    root->child[key[i] - 'a'] = deleteNode(root->child[key[i] - 'a'], key, i+1);
    //Processing
    if(isEmpty(root) && root->isEnd = false) {
        delete(root);
        root = NULL;
    }
    return root;
}

int main()
{
    return 0;
}