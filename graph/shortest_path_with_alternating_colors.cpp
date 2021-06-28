class Solution
{
public:
    void buildGraph(vector<vector<int>> g, int n, vector<vector<int>> red_edges, vector<vector<int>> blue_edges)
    {
        for (auto i : red_edges)
        {
            int from = i[0];
            int to = i[1];
            g[from][to] = 1;
        }
        for (auto i : blue_edges)
        {
            int from = i[0];
            int to = i[1];
            if (g[from][to] == 1)
                g[from][to] = 0;
            else
                g[from][to] = -1;
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges)
    {
        vector<vector<int>> g(n, vector(n, -n));
        buildGraph(g, n, red_edges, blue_edges);
        queue<vector<int>> q;
        q.push({0, 1});
        q.push({0, -1});
        set<string> visited;
        int len = 0;
        vector<int> res(n, INT_MAX);
        res[0] = 0;
        while (!q.empty())
        {
            int size = q.size();
            len++;
            for (int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();
                int node = curr[0];
                int color = curr[1];
                int oppoColor = -color;
                for (int j = 1; j < n; j++)
                {
                    if (g[node][j] == oppoColor || g[node][j] == 0)
                    {
                        if (visited.find(to_string(j) + to_string(oppoColor)) != visited.end())
                            continue;
                        visited.insert(to_string(j) + to_string(oppoColor));
                        q.push({j, oppoColor});
                        res[j] = min(res[j], len);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (res[i] == INT_MAX)
                res[i] = -1;
        }
        return res;
    }
};