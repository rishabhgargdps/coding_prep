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
    bool isBalanced(TreeNode* root) {
        //Base case
        if(root == NULL) return true;
        //Processing
        TreeNode *lNode = root, *rNode = root;
        int l = 0, r = 0;
        while(lNode) {
            l++;
            // cout << l << endl;
            lNode = lNode->left;
        }
        while(rNode) {
            r++;
            rNode = rNode->right;
        }
        if(abs(l-r)>1) return false;
        //Recursive step
        return isBalanced(root->left) && isBalanced(root->right);
    }
};