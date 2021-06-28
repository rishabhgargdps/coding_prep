class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<vector<int>> &cost, int src, int dest, int k, int &fare, int total_cost, vector<bool> &visited)
    {
        if (k < -1)
            return;
        if (src == dest)
        {
            fare = min(fare, total_cost);
            return;
        }
        visited[src] = true;
        for (int x : adj[src])
        {
            if (!visited[x] && total_cost + cost[src][x] <= fare)
            {
                dfs(adj, cost, x, dest, k - 1, fare, total_cost + cost[src][x], visited);
            }
        }
        visited[src] = false;
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        //initialize the data structures here
        int v = n;
        vector<vector<int>> adj(v, vector<int>());
        vector<vector<int>> cost(v, vector<int>(v, 0));
        for (auto flight : flights)
        {
            adj[flight[0]].push_back(flight[1]);
            cost[flight[0]][flight[1]] = flight[2];
        }
        vector<bool> visited(v, false);
        int fare = INT_MAX;
        dfs(adj, cost, src, dst, k, fare, 0, visited);
        return fare == INT_MAX ? -1 : fare;
    }
};