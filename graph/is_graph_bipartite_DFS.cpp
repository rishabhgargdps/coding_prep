class Solution
{
public:
    //we use graph coloring (BFS and DFS)
    //we can use union find as well
    bool validColor(vector<vector<int>> &graph, vector<int> color, int c, int node)
    {
        if (color[node] != 0)
            return color[node] == c;
        color[node] = c;
        for (int x : graph[node])
        {
            if (!validColor(graph, color, -c, x))
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++)
        {
            if (color[i] == 0 && !validColor(graph, color, 1, i))
                return false;
        }
        return true;
    }
};