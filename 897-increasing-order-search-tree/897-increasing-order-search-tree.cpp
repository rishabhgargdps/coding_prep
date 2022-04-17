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
class Solution {
public:
    void dfs(TreeNode* root, TreeNode*& sentinel) {
        if(root == NULL) return;
        dfs(root->left, sentinel);
        sentinel->right = new TreeNode(root->val);
        sentinel = sentinel->right;
        dfs(root->right, sentinel);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* sentinel = new TreeNode(0);
        TreeNode* ans = sentinel;
        dfs(root, sentinel);
        return ans->right;
    }
};