/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>>res;
        queue<Node*>q;
        q.push(root);
        res.push_back({root->val});
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            vector<int>temp;
            for(int i=0; i<size; i++) {
                Node* curr = q.front();
                q.pop();
                for(Node* child : curr->children) {
                    q.push(child);
                    temp.push_back(child->val);
                }
            }
            if(temp.size() != 0) res.push_back(temp);
        }
        return res;
    }
};