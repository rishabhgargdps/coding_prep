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
    int solve(TreeNode* root) {
        //Base case
        if(root == NULL) return 0;
        //Recursive step
        int left = solve(root->left);
        int right = solve(root->right);
        res += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
    int distributeCoins(TreeNode* root) {
        res = 0;
        solve(root);
        return res;
    }
};