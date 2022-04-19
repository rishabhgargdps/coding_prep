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
    int res =0;
    vector<int>solve(TreeNode* root) {
        if(root == NULL) return {INT_MAX, INT_MIN};
        if(root->left == NULL && root->right == NULL) return {root->val, root->val};
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);
        int minimum = min(left[0], right[0]);
        int maximum = max(left[1], right[1]);
        res = max(res, max(abs(root->val - minimum), abs(maximum - root->val)));
        minimum = min(minimum, root->val);
        maximum = max(maximum, root->val);
        return {minimum, maximum};
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return res;
    }
};