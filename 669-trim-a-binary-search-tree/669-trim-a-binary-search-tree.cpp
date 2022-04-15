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
    TreeNode* solve(TreeNode* root, int low, int high) {
        //Base case
        if(root == NULL) return NULL;
        //Recursive step
        if(root->val < low) return solve(root->right, low, high);
        else if(root->val > high) return solve(root->left, low, high);
        else {
            root->left = solve(root->left, low, high);
            root->right = solve(root->right, low, high);
            return root;
        }
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }
};