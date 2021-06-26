void DFS(const vector<vector<int>> &adj, int s, bool visited[])
{
    // int v = adj.size();
    cout << s;
    visited[s] = true;
    for (int x : adj[s])
    {
        if (!visited[x])
        {
            // visited[x] = true;
            DFS(adj, x, visited);
        }
    }
}

int main()
{
    int v = 5;
    int s = 0;
    vector<vector<int>> adj(v);
    bool visited[v] = false;
    //some edge addition calls here
    DFS(adj, s, visited);
    return 0;
}

//for multiple connected components in graph isolated from each other

void DFS(const vector<vector<int>> &adj, int s, bool visited[])
{
    int v = adj.size();
    cout << adj[s];
    visited[s] = true;
    for (int x : adj[s])
    {
        if (!visited[x])
        {
            visited[x] = true;
            DFS(adj, x, visited);
        }
    }
}

int main()
{
    int v = 5;
    int s = 0;
    vector<vector<int>> adj(v);
    bool visited[v] = false;
    //some edge addition calls here
    int count = 0;
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            count++; //optional: to count the number of isolated connected components
            DFS(adj, i, visited);
        }
    }
    return 0;
}