//kosaraju's algorithm is used for identifying strongly connected components in the graph
//for printing the connected components in separate lines
//for undirected graphs we simply do a DFS since if u is reachable from v then v is also reachable from u
//kosaraju's algorithm makes sense for directed graphs only
//it ensures that DFS starts from sink components instead of source components by doing preprocessing with start and finish times
//(decreasing order of finish times)
//transpose of the graph involved in step 2 is simply the transpose of the adj matrix.

void DFS_stack(vector<vector<int>> &graph, int s, bool visited[], stack<int> &stk)
{
    int v = graph.size();
    cout << s;
    visited[s] = true;
    for (int i = 0; i < v; i++)
    {
        if (graph[s][i] != 0 && !visited[i])
        {
            DFS_stack(graph, i, visited, stk);
        }
    }
    stk.push(i);
}

void transpose(vector<vector<int>> &graph)
{
    int v = graph.size();
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            swap(graph[i][j], graph[j][i]);
        }
    }
}

void DFS(vector<vector<int>> &graph, int s, bool visited[])
{
    int v = graph.size();
    visited[s] = true;
    for (int i = 0; i < v; i++)
    {
        if (graph[s][i] != 0 && !visited[i])
        {
            DFS(graph, i, visited);
        }
    }
}

int main()
{
    const int v = 5;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    //add_edge function calls here
    bool visited[v] = {false};
    stack<int> stk;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            DFS_stack(graph, i, visited, stk);
        }
    }
    transpose(graph);
    //reinitialize the visited array
    visited[i] = {false};
    while (!stk.empty())
    {
        if (!visited[stk.top()])
        {
            DFS(graph, stk.top(), visited);
        }
    }
    return 0;
}