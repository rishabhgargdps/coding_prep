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
class FindElements {
public:
    TreeNode* root;
    unordered_set<int>s;
    void solve(TreeNode* root) {
        //Recursive step
        if(root->left) {
            root->left->val = 2 * root->val + 1;
            s.insert(2 * root->val + 1);
            solve(root->left);
        }
        if(root->right) {
            root->right->val = 2 * root->val + 2;
            s.insert(2 * root->val + 2);
            solve(root->right);
        }
    }
    void print(TreeNode* root) {
        cout << root->val << endl;
        if(root->left) print(root->left);
        else cout << "null" << endl;
        if(root->right) print(root->right);
        else cout << "null" << endl;
    }
    FindElements(TreeNode* root) {
        s.clear();
        this->root = root;
        this->root->val = 0;
        s.insert(0);
        solve(this->root);
        // print(this->root);
    }
    
    bool findBST(TreeNode* root, int target) {
        //Base case
        if(root == NULL) return false;
        if(root->val  == target) return true;
        //Recursive step
        if(root->val < target) return findBST(root->right, target);
        return findBST(root->left, target);
    }
    
    bool find(int target) {
        return s.find(target) != s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */