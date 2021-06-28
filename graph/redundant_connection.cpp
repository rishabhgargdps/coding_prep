class Solution
{
public:
    int find(int s, vector<int> &parent)
    {
        if (parent[s] == 0)
            parent[s] = s;
        if (parent[s] != s)
            parent[s] = find(parent[s], parent);
        return parent[s];
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        //we can use Kruskal's algorithm : union-find approach
        int v = edges.size();
        vector<int> parent(v + 1, 0);
        for (auto edge : edges)
        {
            int src = edge[0];
            int dest = edge[1];
            int p_src = find(src, parent);
            int p_dest = find(dest, parent);
            if (p_src == p_dest)
                return edge;
            parent[p_dest] = p_src;
        }
        return {0, 0};
    }
};