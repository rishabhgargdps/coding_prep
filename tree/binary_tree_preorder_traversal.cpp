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

//recursive solution:
vector<int>res;
class Solution {
public:
    void traversal(TreeNode* root) {
        if(root==NULL) return;
        res.push_back(root->val);
        if(root->left) traversal(root->left);
        if(root->right)traversal(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        res.clear();
        traversal(root);
        return res;
    }
};

//iterative solution:
