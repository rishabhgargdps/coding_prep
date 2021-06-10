#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
vector<int>res;
class Solution {
public:
    void inorder(TreeNode* root) {
        //Base case
        //Recursive step
        if (root==NULL) return;
        if (root->left) inorder(root->left);
        res.push_back(root->val);
        if (root->right)inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        res.clear();
        inorder(root);
        return res;
    }
};