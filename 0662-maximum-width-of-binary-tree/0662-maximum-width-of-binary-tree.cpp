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
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, uint>>dq;
        dq.push_back({root, 0});
        uint res = 0;
        while(!dq.empty()) {
            int size = dq.size();
            res = max(res, dq.back().second-dq.front().second+1);
            for(int i=0; i<size; i++) {
                TreeNode* parent = dq.front().first;
                uint col = dq.front().second;
                dq.pop_front();
                if(parent->left) dq.push_back({parent->left, 2*col});
                if(parent->right) dq.push_back({parent->right, 2*col+1});
            }
        }
        return res;
    }
};