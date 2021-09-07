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
    vector<TreeNode *> generateTrees(int low, int high)
    {
        vector<TreeNode *> res;
        //Base case
        if (low > high)
        {
            res.push_back(NULL);
            return res;
        }
        //Recursive step
        for (int i = low; i <= high; i++)
        {
            vector<TreeNode *> left_subtrees = generateTrees(low, i - 1);
            vector<TreeNode *> right_subtrees = generateTrees(i + 1, high);
            for (TreeNode *left_subtree : left_subtrees)
            {
                for (TreeNode *right_subtree : right_subtrees)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left_subtree;
                    root->right = right_subtree;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {NULL};
        return generateTrees(1, n);
    }
};