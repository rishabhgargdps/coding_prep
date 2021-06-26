bool DFSDetect(vector<vector<int>> adj, int s, bool visited[], int parent)
{
    int v = adj.size();
    visited[s] = true;
    for (int x : adj[s])
    {
        if (!visited[x])
        {
            DFSDetect(adj, x, visited, s);
        }
        else if (x != parent)
        {
            return true;
        }
    }
    return false;
}

bool res(vector<vector<int>> adj, bool visited[])
{
    for (int i = 0; i < visited.size(); i++)
    {
        if (DFSDetect(adj, i, visited, -1) == true)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    const int v = 5;
    vector<vector<int>> adj(v, {});
    bool visited[v] = false;
    //add edges here
    res(adj, visited);
    return 0;
}