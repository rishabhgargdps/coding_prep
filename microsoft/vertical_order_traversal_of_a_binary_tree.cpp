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
    vector<vector<int>> temp;
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    void preorder(TreeNode *root, int col, int level)
    {
        //Base case
        if (root == NULL)
            return;
        //Recursive step
        temp.push_back({root->val, col, level});
        minimum = min(minimum, col);
        maximum = max(maximum, col);
        preorder(root->left, col - 1, level + 1);
        preorder(root->right, col + 1, level + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        preorder(root, 0, 0);
        vector<vector<pair<int, int>>> temp2(maximum - minimum + 1);
        for (auto v : temp)
        {
            temp2[v[1] + abs(minimum)].push_back({v[2], v[0]});
        }
        for (auto &v : temp2)
        {
            sort(v.begin(), v.end());
        }
        vector<vector<int>> res(maximum - minimum + 1);
        for (int i = 0; i < res.size(); i++)
        {
            for (auto x : temp2[i])
            {
                res[i].push_back(x.second);
            }
        }
        return res;
    }
};