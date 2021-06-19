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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        TreeNode* temp = root;
        vector<vector<int>>res;
        if(root == NULL) return res;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            vector<int>v;
            int n = q.size();
            while(n--) {
                v.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
                level++;
                res.push_back(v);
            //changing the order of elements within res
            }
        for(int i=0; i<res.size(); i++) {
            if(i%2) {
                for(int j=0; j<res[i].size()/2; j++) {
                    swap(res[i][j], res[i][res[i].size()-1-j]);
                }
            }
        }
        return res;
    }
};