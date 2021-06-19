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
    int s = 0;
    int f(TreeNode *r, int m, int M)
    {
        if (r == NULL)
        {
            return 0;
        }
        if (r->val <= m || r->val >= M)
        {
            return INT_MIN;
        }

        int l = f(r->left, m, r->val);
        int R = f(r->right, r->val, M);
        s = max(s, max(l, R));
        if (R == INT_MIN || l == INT_MIN)
        {
            return INT_MIN;
        }
        return r->val + R + l;
    }

    int maxSumBST(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        s = 0;
        int a = f(root, INT_MIN, INT_MAX);

        if (a > s)
        {
            s = a;
            return a;
        }
        int l = maxSumBST(root->left);
        int r = maxSumBST(root->right);
        return max(s, max(l, r));
    }
};