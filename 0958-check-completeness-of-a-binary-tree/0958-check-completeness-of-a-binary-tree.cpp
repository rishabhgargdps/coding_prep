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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root);
        bool flag = true;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(!flag && curr->left) return false;
                if(curr->left) q.push(curr->left);
                else flag = false;
                if(!flag && curr->right) return false;
                if(curr->right) q.push(curr->right);
                else flag = false;
            }
        }
        return true;
    }
};