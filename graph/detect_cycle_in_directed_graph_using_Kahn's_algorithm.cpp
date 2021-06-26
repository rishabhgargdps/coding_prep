//add all indegree 0 elements to the queue and then iterate thorugh their neighbours, reducing their indegree by 1 in every iteration
bool BFS(const vector<vector<int>> &adj, vector<int> &indegree)
{
    int v = adj.size();
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        for (int x : adj[q.front()])
        {
            if (indegree[x] > 0)
            {
                indegree[x]--;
            }
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
        count++;
        cout << q.front();
        q.pop();
    }
    return count != v;
}
int main()
{
    const int v = 5;
    vector<vector<int>> adj(v, {});
    vector<int> indegree(v, 0);
    //add_edge function called here
    //indegree vector is processed here
    for (int i = 0; i < v; i++)
    {
        for (int x : adj[i])
        {
            indegree[x]++;
        }
    }
    BFS(adj, indegree);
    return 0;
}