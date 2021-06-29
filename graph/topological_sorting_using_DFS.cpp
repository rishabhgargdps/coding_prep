void DFS(vector<vector<int>> adj, int s, bool visited[], stack<int>& stk)
{
    visited[s] = true;
    cout << s;
    for (int x : adj[s])
    {
        if (!visited[x])
        {
            DFS(adj, x, visited);
        }
    }
    stk.push(s);
}

int main()
{
    const int v = 5;
    // int s = 0;
    vector<vector<int>> adj(v, 0);
    bool visited[v] = {false};
    stack<int>stk;
    for (int i = 0; i < visited.size(); i++)
    {
        DFS(adj, i, visited, stk);
    }
    while(!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    return 0;
}