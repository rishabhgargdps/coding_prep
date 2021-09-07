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
class Solution
{
public:
    vector<int> res;
    void inorder(TreeNode *root)
    {
        //Base case
        if (root == NULL)
            return;
        //Positive case
        if (root->left == NULL && root->right == NULL)
            res.push_back(root->val);
        //Recursive step
        inorder(root->left);
        inorder(root->right);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        inorder(root1);
        vector<int> temp = res;
        res.clear();
        inorder(root2);
        if (temp == res)
            return true;
        return false;
    }
};