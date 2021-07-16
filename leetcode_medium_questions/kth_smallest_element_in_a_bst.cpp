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
    void inorder(TreeNode *root, vector<int> &res)
    {
        //Base case
        if (root == NULL)
            return;
        //Recursive step
        inorder(root->left, res);
        //do some work
        res.push_back(root->val);
        inorder(root->right, res);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> res;
        inorder(root, res);
        return res[k - 1];
    }
};

//optimization when we cannot modify the nodes
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
    int solve(TreeNode *root, int &k)
    {
        if (root == NULL)
            return 0;
        int left = solve(root->left, k);
        if (left)
            return left;
        k -= 1;
        if (k == 0)
            return root->val;
        int right = solve(root->right, k);
        return right;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        return solve(root, k);
    }
};
