void BFS(const vector<vector<int>> &adj, int s)
{
    const int v = adj.size();
    bool visited[v] = {false};
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        cout << q.front() << " ";
        for (int x : adj[q.front()])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
        q.pop();
    }
}
int main()
{
    int v = 5;
    int s = 0; //source node
    vector<vector<int>> adj(v);
    //some add edge loop here
    BFS(adj, s);
    cout << endl;
    return 0;
}

//more general version (all nodes are not connected, different connected components in graph)
void BFS(const vector<vector<int>> &adj, int s, bool visited[])
{
    int v = adj.size();
    queue<int> q;
    q.push(adj[s]);
    visited[s] = true;
    while (!q.empty())
    {
        cout << q.front() << " ";
        for (int x : adj[q.front()])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
int main()
{
    int v = 5;
    int s = 0; //source node
    vector<vector<int>> adj(v);
    bool visited[v] = false;
    int count = 0;
    //some add edge loop here
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            count++; //optional: to count the number of connected components in the graph
            BFS(adj, i, visited);
        }
    }
    cout << endl;
    return 0;
}