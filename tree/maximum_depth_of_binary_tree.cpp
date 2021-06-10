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

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if (root==NULL) return 0;
//         return 1+max(maxDepth(root->left), maxDepth(root->right));
//     }
// };

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue <TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()) {
            level++;
            int n = q.size();
            while (n--) {
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
        }
        return level;
    }
};