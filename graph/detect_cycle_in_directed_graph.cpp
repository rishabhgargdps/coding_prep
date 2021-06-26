bool DFS(vector<vector<int>> adj, int s, bool visited[], bool recSt[])
{
    int v = adj.size();
    visited[s] = true;
    recSt[s] = true;
    for (int x : adj[s])
    {
        if (!visited[x] && DFS(adj, x, visited, recSt))
        {
            return true;
        }
        else if (recSt[x])
        {
            return true;
        }
    }
    recSt[s] = false;
    return false;
}

bool res(vector<vector<int>> adj, bool visited[], bool recSt[])
{
    int v = visited.size();
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && DFS(adj, i, visited, recSt))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    const int v = 5;
    int s = 0;
    vector<vector<int>> adj(v, {});
    bool visited[v] = {false};
    bool recSt[v] = {false};
    //add_edge function here
    res(adj, visited, recSt);
    return 0;
}