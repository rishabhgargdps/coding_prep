class Solution
{
public:
    void DFS(vector<vector<int>> &graph, int s, vector<bool> &visited)
    {
        int v = graph.size();
        visited[s] = true;
        for (int x = 0; x < v; x++)
        {
            if (graph[s][x] == 1 && !visited[x])
            {
                DFS(graph, x, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        const int v = isConnected.size();
        // int w = isConnected[0].size(); v = w;
        for (int i = 0; i < v; i++)
        {
            isConnected[i][i] = 0; //remove non existent self edges
        }
        vector<bool> visited(v, false);
        int count = 0;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                count++;
                DFS(isConnected, i, visited);
            }
        }
        return count;
    }
};