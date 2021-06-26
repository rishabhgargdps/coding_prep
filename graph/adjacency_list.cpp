//undirected graph
void add_edge(int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

int main()
{
    int v = 5;
    vector<vector<int>> adj(v);
    add_edge(0, 1);
    return 0;
}

//directed graph
void add_edge(int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int v = 5;
    vector<vector<int>> adj(v);
    add_edge(0, 1); //add an edge from u to v
    return 0;
}