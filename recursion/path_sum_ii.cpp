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
    vector<vector<int>>res;
    void path_sum(TreeNode* root, int targetSum, vector<int> currtop) {
        //Base cases
        if(root == NULL) return;
        currtop.push_back(root->val);
        if(targetSum == root->val && root->left == NULL && root->right == NULL) res.push_back(currtop);
        //Recursive step
        path_sum(root->left, targetSum - root->val, currtop);
        path_sum(root->right, targetSum - root->val, currtop);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        path_sum(root, targetSum, {});
        return res;
    }
};