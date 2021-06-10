#include <iostream>
using namespace std;
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>temp;
        queue<TreeNode*>q;
        if(root==NULL) return {};
        q.push(root);
        temp.push_back(root->val);
        res.push_back(temp);
        temp.clear();
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                if(q.front()->left) {
                    q.push(q.front()->left);
                    temp.push_back(q.front()->left->val);
                }
                if(q.front()->right) {
                    q.push(q.front()->right);
                    temp.push_back(q.front()->right->val);
                }
                q.pop();
            }
            if (temp.size()) {
                res.push_back(temp);
                temp.clear();
            }
        }
        return res;
    }
};