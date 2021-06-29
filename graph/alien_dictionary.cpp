class Solution
{
public:
    bool hasCycle(vector<vector<int>> &adj, int s, vector<bool> &visited, vector<bool> &recSt)
    {
        visited[s] = true;
        recSt[s] = true;
        for (int x : adj[s])
        {
            if (!visited[x])
            {
                if (hasCycle(adj, x, visited, recSt))
                    return true;
            }
            else if (recSt[x])
            {
                return true;
            }
        }
        recSt[s] = false;
        return false;
    }

    void buildGraph(vector<string> &dict, vector<vector<int>> &adj)
    {
        for (int i = 1; i < dict.size(); i++)
        {
            int j = 0;
            while (j < min(dict[i - 1].length(), dict[i].length()) && dict[i - 1][j] == dict[i][j])
            {
                j++;
            }
            if (j == min(dict[i - 1][j], dict[i][j]))
                continue;
            adj[dict[i - 1][j] - 'a'] = dict[i][j] - 'a';
        }
    }

    void topological_sort(vector<vector<int>> &adj, int s, vector<bool> visited, stack<int> &stk)
    {
        visited[s] = true;
        for (int x : adj[s])
        {
            if (!visited[x])
            {
                topological_sort(adj, x, visited);
            }
        }
        stk.push(s);
    }

    string findOrder(string dict[], int N, int K)
    {
        vector<vector<int>> adj(K, vector<int>());
        buildGraph(dict, adj);
        vector<bool> visited(K, false);
        vector<bool> recSt(K, false);
        for (int i = 0; i < K; i++)
        {
            if (!visited[i] && hasCycle(adj, i, visited, recSt))
                return "";
        }
        for (int i = 0; i < K; i++)
        {
            visited[i] = false;
        }
        stack<int> stk;
        for (int i = 0; i < K; i++)
        {
            topological_sort(adj, i, visited, stk);
        }
        string res;
        while (!stk.empty())
        {
            res += (stk.top() + 'a');
            stk.pop();
        }
        return res;
    }
};