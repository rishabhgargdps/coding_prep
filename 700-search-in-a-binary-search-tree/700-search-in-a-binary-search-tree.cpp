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
    TreeNode* res = NULL;
    void solve(TreeNode* root, int val) {
        //Base case
        if(root->val == val) {
            res = root;
            return;
        }
        //Recursive step
        if(root->val < val) {
            if(root->right) solve(root->right, val);
            return;
        }
        else if(root->val > val) {
            if(root->left) solve(root->left, val);
            return;
        }
    } 
    TreeNode* searchBST(TreeNode* root, int val) {
        res = NULL;
        solve(root, val);
        return res;
    }
};