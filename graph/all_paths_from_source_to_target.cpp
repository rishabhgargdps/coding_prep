class Solution
{
public:
    vector<vector<int>> res;
    void dfs(vector<int> temp, vector<vector<int>> &graph, int s, vector<bool> &visited)
    {
        //Processing
        visited[s] = true;
        temp.push_back(s);
        //Base case
        if (s == graph.size() - 1)
        {
            res.push_back(temp);
            temp = {};
        }
        //Recursive step
        for (int x : graph[s])
        {
            dfs(temp, graph, x, visited);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<bool> visited(v, false);
        dfs({}, graph, 0, visited);
        return res;
    }
};