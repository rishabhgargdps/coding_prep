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
    void solve(TreeNode* root) {
        //Recursive step
        if(root->right) solve(root->right);
        res += root->val;
        root->val = res;
        if(root->left) solve(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return NULL;
        solve(root);
        return root;
    }
};