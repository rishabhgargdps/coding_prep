#include<iostream>
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
vector<int>res;
class Solution {
public:
    void inOrderTraversal(TreeNode* root) {
        //Base cases
        if(root==NULL) return;
        //Recursive step
        inOrderTraversal(root->left);
        //Do some work
        res.push_back(root->val);
        inOrderTraversal(root->right);
    }
    bool isValidBST(TreeNode* root) {
        res.clear();
        inOrderTraversal(root);
        for(int i=0; i<res.size()-1; i++) {
            if(res[i]>=res[i+1]) {
                return false;
            }
        }
        return true;
    }
};