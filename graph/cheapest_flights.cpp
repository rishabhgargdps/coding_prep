//implementation of basic Dijkstra algorithm
class Solution
{
public:
    vector<vector<int>> buildGraph(vector<vector<int>> &flights, int n)
    {
        int v = n;
        vector<vector<int>> graph(v, vector<int>(v, 0));
        for (auto flight : flights)
        {
            graph[flight[0]][flight[1]] = flight[2];
        }
        return graph;
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        int v = n;
        vector<int> dist(v, INT_MAX);
        dist[src] = 0;
        vector<bool> finalised(v, false);
        vector<vector<int>> graph = buildGraph(flights, n);
        for (int count = 0; count < v - 1; count++)
        {
            int u = -1;
            for (int i = 0; i < v; i++)
            { //this loop can be replaced by priority queue (to pick the minimum key from the vector)
                if (!finalised[i] && (u == -1 || dist[i] < dist[u]))
                    u = i;
            }
            finalised[u] = true;
            for (int i = 0; i < v; i++)
            {
                if (graph[u][i] != 0 && finalised[i] == false)
                {
                    dist[i] = min(dist[i], dist[u] + graph[u][i]);
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};