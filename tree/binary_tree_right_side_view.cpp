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
    vector<int> rightSideView(TreeNode* root) {
        TreeNode* temp = root;
        vector<int>res;
        //Breadth first search
        queue<TreeNode*>q;
        if(root==NULL) return res;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i=0; i<n; i++) {
                if(i==0) res.push_back(q.front()->val);
                if(q.front()->right) q.push(q.front()->right);
                if(q.front()->left) q.push(q.front()->left);
                q.pop();
            }
        }
        return res;
    }
};