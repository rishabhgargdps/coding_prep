//we use topological sorting to do this. We can also use Bellman-Ford and even better with Djikstra than Bellman-Ford
vector<int> BFS(const vector<vector<int>> &adj, vector<int> &indegree)
{
    queue<int> q;
    vector<int> res;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        for (int x : adj[q.front()])
        {
            if (indegree[x] > 0)
            {
                indegree[x]--;
            }
            if (indegree[x] == 0)
                q.push(x);
        }
        res.push(q.front());
        q.pop();
    }
    return res;
}
int main()
{
    const int v = 5;
    int s = 0;
    vector<vector<int>> adj(v, {});
    vector<int> indegree(v, 0);
    //add_edge function called here
    vector<vector<int>> weight(v, vector<int>(v, 0));
    //process weight matrix here
    //indegree vector is processed here
    for (int i = 0; i < v; i++)
        for (int x : adj[i])
            indegree[x]++;
    vector<int> res;
    res = BFS(adj, indegree);
    vector<int> dist(v, INT_MAX);
    dist[s] = 0;
    for (int u : res)
    {
        for (int x : adj[u])
        {
            if (dist[x] > dist[u] + weight[u][x])
                dist[x] = dist[u] + weight[u][x];
        }
    }
    //dist array has the answer
    return 0;
}