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
    vector<TreeNode*>inOrder;
    TreeNode* solve(int start, int end) {
        //Base case
        if(start > end) return NULL;
        //Recursive step
        int mid = start + (end-start)/2;
        TreeNode* root = inOrder[mid];
        root->left = solve(start, mid - 1);
        root->right = solve(mid + 1, end);
        return root;
    }
    void inorder(TreeNode* root) {
        //Base case
        if(!root) return;
        //Recursive step
        inorder(root->left);
        inOrder.push_back(root);
        inorder(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return solve(0, inOrder.size()-1);
    }
};