class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<int> &quiet, int src, vector<int> &res, int ans, int &curr_node)
    {
        for (int node : adj[src])
        {
            if (ans > quiet[node])
            {
                ans = quiet[node];
                curr_node = node;
            }
            dfs(adj, quiet, node, res, ans, curr_node);
        }
    }

    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int n = quiet.size();
        vector<int> res(n);
        vector<vector<int>> adj(n);
        for (auto rich : richer)
        {
            adj[rich[1]].push_back(rich[0]);
        }
        for (int i = 0; i < n; i++)
        {
            int curr_node = i;
            dfs(adj, quiet, i, res, quiet[i], curr_node);
            res[i] = curr_node;
        }
        return res;
    }
};