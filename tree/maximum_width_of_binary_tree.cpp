//wrong solution

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
    vector<pair<int, int>> res;

    void dfs(TreeNode *root, int row, int col)
    {
        //Base case
        res.push_back({row, col});
        if (root->left == NULL && root->right == NULL)
            return;
        //Recursive step
        dfs(root->left, col - 1, level + 1);
        dfs(root->right, col + 1, level + 1);
    }

    int widthOfBinaryTree(TreeNode *root)
    {
        dfs(root, 0, 0);
        sort(res.begin(), res.end());
        //row-wise left_max and right_max to be found
        return right_max - left_max;
    }
};

//correct solution

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
    int widthOfBinaryTree(TreeNode *root)
    {
        uint ans = 0;
        deque<pair<TreeNode *, uint>> dq;
        dq.push_back({root, 0});
        while (!dq.empty())
        {
            int n = dq.size();
            ans = max(ans, dq.back().second - dq.front().second + 1);
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = dq.front().first;
                uint col = dq.front().second;
                dq.pop_front();
                if (curr->left)
                    dq.push_back({curr->left, 2 * col});
                if (curr->right)
                    dq.push_back({curr->right, 2 * col + 1});
            }
        }
        return ans;
    }
};