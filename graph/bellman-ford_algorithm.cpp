//shortest distance from the source to every other vertex
//for unweighted graphs simply do a BFS
//improved over Dijkstra, here we can also have negative weights attached
vector<int> bellmanFordShortestPath(vector<vector<int>> &graph, int s)
{
    int v = graph.size();
    vector<int> dist(v, INT_MAX);
    dist[0] = 0;
    for (int count = 0; count < v - 1; count++)
    { //relax all the edges exactly v-1 times
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (graph[i][j] != 0)
                {
                    if (dist[j] > dist[i] + graph[i][j])
                        dist[j] = dist[i] + graph[i][j];
                }
            }
        }
    }
    //we relax one more time to check if there is any negative weight cycle
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (graph[i][j] != 0)
            {
                if (dist[j] > dist[i] + graph[i][j])
                {
                    print("Negative weight cycle found");
                    return dist;
                }
            }
        }
    }
    return dist;
}

int main()
{
    int v = 5;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    vector<int> res = bellmanFordShortestPath(graph, s);
    //res contains the result
    return 0;
}