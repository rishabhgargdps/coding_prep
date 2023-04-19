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
    int res = 0;
    pair<int, int> solve(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return {0, 0};
        if(root->left == NULL) {
            int right = 1+solve(root->right).first;
            res = max(res, right);
            return {0, right};
        }
        if(root->right == NULL) {
            int left = 1+solve(root->left).second;
            res = max(res, left);
            return {left, 0};
        }
        int left = 1+solve(root->left).second, right = 1+solve(root->right).first;
        res = max(res, left);
        res = max(res, right);
        return {left, right};
    }
    int longestZigZag(TreeNode* root) {
        solve(root);
        return res;
    }
};