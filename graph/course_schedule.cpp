class Solution
{
public:
    bool detectCycle(vector<vector<int>> &adj, int s, vector<bool> &visited, vector<bool> &recStk)
    {
        int v = adj.size();
        visited[s] = true;
        recStk[s] = true;
        for (int x : adj[s])
        {
            if (!visited[x] && detectCycle(adj, x, visited, recStk))
            {
                return true;
            }
            else if (recStk[x])
                return true;
        }
        recStk[s] = false;
        return false;
    }

    void buildGraph(vector<vector<int>> &prerequisites, vector<vector<int>> &adj)
    {
        for (auto p : prerequisites)
        {
            adj[p[0]].push_back(p[1]);
        }
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        //simple cycle detection using DFS (directed graph)
        int v = numCourses;
        vector<vector<int>> adj(v, vector<int>());
        buildGraph(prerequisites, adj);
        vector<bool> visited(v, false);
        vector<bool> recStk(v, false);
        bool ans = true;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && detectCycle(adj, i, visited, recStk))
                return false;
        }
        return true;
    }
};