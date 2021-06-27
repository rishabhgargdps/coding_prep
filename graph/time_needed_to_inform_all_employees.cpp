class Solution
{
public:
    int dfs(vector<vector<int>> &adj, int headID, vector<int> &informTime)
    {
        int total_time = 0;
        for (int x : adj[headID])
        {
            total_time = max(total_time, dfs(adj, x, informTime));
        }

        return total_time + informTime[headID];
    }

    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        int v = manager.size();
        vector<vector<int>> adj(v);
        for (int i = 0; i < v; i++)
        {
            if (manager[i] != -1)
            {
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(adj, headID, informTime);
    }
};