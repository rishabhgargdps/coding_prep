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
    TreeNode* invertTree(TreeNode* root) {
        //Base case
        if(root == NULL) return root;
        else if(root->left == NULL && root->right == NULL) return root;
        else if(root->right == NULL) {
            root->right = root->left;
            root->right = NULL;
        }
        else if(root->left == NULL) {
            root->left = root->right;
            root->left = NULL;
        }
        //Recursive step
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};