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
int sum = 0;
class Solution {
public:
    void greaterTree(TreeNode* root) {
        if(root==NULL) return;
        greaterTree(root->right);
        sum+= root->val;
        root->val = sum;
        greaterTree(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        greaterTree(root);
        return root;
    }
};