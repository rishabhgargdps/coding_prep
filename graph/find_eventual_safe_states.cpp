class Solution
{
public:
    unordered_set<int> cycle_nodes;
    unordered_set<int> safe_nodes;

    bool dfs(vector<vector<int>> &adj, int s, vector<bool> &visited)
    {
        //Base cases
        if (safe_nodes.find(s) != safe_nodes.end())
            return true;
        else if (cycle_nodes.find(s) != cycle_nodes.end())
            return false;
        else if (visited[s])
        {
            cycle_nodes.insert(s);
            return false;
        }

        visited[s] = true;

        //Recursive step
        for (int x : adj[s])
        {
            if (!dfs(adj, x, visited))
            {
                cycle_nodes.insert(s);
                return false;
            }
        }
        safe_nodes.insert(s);
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<bool> visited(v, false);
        vector<int> res;
        for (int i = 0; i < v; i++)
        {
            if (dfs(graph, i, visited))
                res.push_back(i);
        }
        return res;
    }
};