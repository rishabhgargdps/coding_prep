//TLE
class Solution
{
public:
    float probability = 0.0;
    void dfs(vector<vector<pair<int, float>>> &adj, int src, int dst, float curr_prob, vector<bool> &visited)
    {
        if (src == dst)
        {
            probability = max(probability, curr_prob);
            return;
        }
        visited[src] = true;
        for (auto x : adj[src])
        {
            if (!visited[x.first])
                dfs(adj, x.first, dst, curr_prob * x.second, visited);
        }
        visited[src] = false;
    }

    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, float>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<bool> visited(n, false);
        dfs(adj, start, end, 1, visited);
        return probability;
    }
};