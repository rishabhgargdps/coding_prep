/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        //we do a breadth first search of the BST
        string res = "";
        if (root == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                res += "NULL ";
                continue;
            }
            res += to_string(temp->val) + " ";
            q.push(temp->left);
            q.push(temp->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        //convert the result string into a vector of strings
        if (data.length() == 0)
            return NULL;
        istringstream s(data);
        vector<string> nodes;
        string temp;
        while (s >> temp)
        {
            nodes.push_back(temp);
        }
        int len = nodes.size();
        TreeNode *root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode *> q;
        q.push(root);
        for (int i = 1; i < len; i++)
        {
            TreeNode *parent = q.front();
            q.pop();
            if (!(nodes[i] == "NULL"))
            {
                parent->left = new TreeNode(stoi(nodes[i]));
                q.push(parent->left);
            }
            i++;
            if (i < len && !(nodes[i] == "NULL"))
            {
                parent->right = new TreeNode(stoi(nodes[i]));
                q.push(parent->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;