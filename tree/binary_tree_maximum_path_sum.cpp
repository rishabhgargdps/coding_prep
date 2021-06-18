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
    int result = INT_MIN;
    int max_sum(TreeNode* root) {
        //Base case
        if(root == NULL) return 0;
        //Preprocessing
        int left = max_sum(root->left);
        int right = max_sum(root->right);
        int ms = max(max(left, right)+root->val, root->val);
        int m21 = max(ms, left+right+root->val);
        result = max(result, m21);
        return ms;
    }
    int maxPathSum(TreeNode* root) {
        result = INT_MIN;
        max_sum(root);
        return result;
    }
};