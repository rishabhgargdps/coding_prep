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
    bool isCousins(TreeNode *root, int x, int y)
    {
        //bfs
        queue<pair<TreeNode *, TreeNode *>> q;
        q.push({root, NULL});
        while (!q.empty())
        {
            int n = q.size();
            int flag = 0;
            int curr_flag = 0;
            while (n--)
            {
                TreeNode *curr_node = q.front().first;
                q.pop();
                if (curr_node->left)
                {
                    q.push({curr_node->left, curr_node});
                    if (curr_node->left->val == x || curr_node->left->val == y)
                    {
                        flag++;
                        curr_flag++;
                    }
                }
                if (curr_node->right)
                {
                    q.push({curr_node->right, curr_node});
                    if (curr_node->right->val == x || curr_node->right->val == y)
                    {
                        flag++;
                        curr_flag++;
                    }
                }
                if (curr_flag == 2)
                    return false;
                curr_flag = 0;
            }
            if (flag == 1)
                return false;
            else if (flag == 2)
                return true;
        }
        return false;
    }
};