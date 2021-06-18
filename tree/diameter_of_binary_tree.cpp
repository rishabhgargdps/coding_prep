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
    pair<int, int> distance(TreeNode* root) {
        //Base cases
        if(root == NULL) return {0,0};
        //Recursive case
        pair<int, int>left = distance(root->left);
        pair<int, int>right = distance(root->right);
        int internal_path = max(left.second, right.second); //Case 1 and 2 exclude current node
        if(left.first + right.first+1 > internal_path) {
            internal_path = left.first + right.first+1;
        }
        return {1+max(left.first, right.first), internal_path};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int>res = distance(root);
        return max(res.first, res.second)-1;
    }
};