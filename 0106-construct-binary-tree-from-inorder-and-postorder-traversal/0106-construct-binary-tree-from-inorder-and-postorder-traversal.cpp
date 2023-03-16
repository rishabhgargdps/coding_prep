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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inorder_left, int inorder_right, int &postorder_index) {
        if(inorder_left > inorder_right) return NULL;
        int val = postorder[postorder_index--];
        int i=inorder_left;
        for(; i<=inorder_right; i++) {
            if(inorder[i] == val) break;
        }
        TreeNode* root = new TreeNode(val);
        root->right = solve(inorder, postorder, i+1, inorder_right, postorder_index);
        root->left = solve(inorder, postorder, inorder_left, i-1, postorder_index);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size()-1;
        return solve(inorder, postorder, 0, inorder.size()-1, size);
    }
};