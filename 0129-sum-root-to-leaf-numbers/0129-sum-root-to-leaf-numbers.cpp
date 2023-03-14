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
    void solve(TreeNode* root, string curr, int &sum) {
        curr += to_string(root->val);
        if(root->left == NULL && root->right == NULL) {
            sum += stoi(curr);
            return;
        }
        if(root->left) solve(root->left, curr, sum);
        if(root->right) solve(root->right, curr, sum);
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        solve(root, "", sum);
        return sum;
    }
};