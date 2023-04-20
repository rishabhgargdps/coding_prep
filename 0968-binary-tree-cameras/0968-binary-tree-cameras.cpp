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
    //-1: camera needed
    //0: have camera
    //1: are covered by child
    int res = 0;
    int solve(TreeNode* root) {
        if(!root) return 1;
        int left = solve(root->left), right = solve(root->right);
        if(left == -1 || right == -1) {
            res++;
            return 0;
        }
        if(left == 0 || right == 0) {
            return 1;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(solve(root) == -1) res++;
        return res;
    }
};