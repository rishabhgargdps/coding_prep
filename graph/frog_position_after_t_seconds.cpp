class Solution
{
public:
    double compute_prob(vector<int> *adj, int src, int dest, int t)
    {
        //bfs traversal
        queue<pair<int, pair<int, double>>> q; //{vertex, {time, probability}}
        q.push({src, {0, 1.0}});
        while (!q.empty())
        {
            int node = q.front().first;
            int time = q.front().second.first;
            double prob = q.front().second.second;
            q.pop();
            if (node == dest)
            {
                if (time == t || (time < t && adj[node].size() == 0))
                {
                    return prob;
                }
                return 0;
            }
            for (int x : adj[node])
            {
                q.push({x, {time + 1, 1.0 * prob / adj[node].size()}});
            }
        }
        return 0;
    }

    void buildGraph(vector<vector<int>> &edges, vector<int> *adj)
    {
        for (auto edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            if (from > to)
                swap(from, to);
            adj[from].push_back(to);
        }
    }

    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
        //create an adjacency matrix
        vector<int> adj[n + 1];
        buildGraph(edges, adj);

        return compute_prob(adj, 1, target, t);
    }
};