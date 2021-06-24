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
    TreeNode *binary_traversal(vector<int> &nums, int left, int right)
    {
        //Base case
        if (left > right)
            return NULL;
        int midpoint = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[midpoint]);
        root->left = binary_traversal(nums, left, midpoint - 1);
        root->right = binary_traversal(nums, midpoint + 1, right);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return NULL;
        return binary_traversal(nums, 0, nums.size() - 1);
    }
};