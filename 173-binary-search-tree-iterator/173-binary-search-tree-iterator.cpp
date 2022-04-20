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
class BSTIterator {
public:
    stack<TreeNode*>stk;
    void push_to_stack(TreeNode* root) {
        while(root) {
            stk.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        push_to_stack(root);
    }
    
    int next() {
        TreeNode* res;
        res = stk.top();
        stk.pop();
        push_to_stack(res->right);
        return res->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */