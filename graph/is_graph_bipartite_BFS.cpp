class Solution
{
public:
    //we use graph coloring (BFS and DFS)
    //we can use union find as well
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++)
        {
            if (color[i] == 0)
            {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for (int x : graph[node])
                    {
                        if (color[x] == color[node])
                            return false;
                        else if (color[x] == 0)
                        {
                            q.push(x);
                            color[x] = -color[node];
                        }
                    }
                }
            }
        }
        return true;
    }
};