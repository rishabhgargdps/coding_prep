//wrong approach
class Solution
{
public:
    vector<string> &res;

    void dfs(vector<vector<int>> &adj, int s, unordered_map<string, int> &m, unordered_map<int, string> &m2)
    {
        res.push_back(m2[s]);
        for (int x : adj[s])
        {
            dfs(adj, x, m, m2);
        }
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        int nodes = 1;
        unordered_map<string, int> m;
        unordered_map<int, string> m2;
        m["JFK"] = 0;
        for (const auto &v : tickets)
        {
            if (m.find(v[0]) != m.end())
            {
                m[v[0]] = nodes;
                m2[nodes] = v[0];
                nodes++;
            }
            if (m.find(v[1]) != m.end())
            {
                m[v[1]] = nodes;
                m2[nodes] = v[1];
                nodes++;
            }
        }
        vector<vector<int>> adj(nodes);
        for (const auto &v : tickets)
        {
            adj[m[v[0]]].push_back(m[v[1]]);
        }
        dfs(adj, 0, m, m2);
        return res;
    }
};

//correct approach
class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, multiset<string>> adj;
        stack<string> stk;
        for (const auto &v : tickets)
        {
            adj[v[0]].insert(v[1]);
        }
        vector<string> res;
        stk.push("JFK");
        while (!stk.empty())
        {
            string curr = stk.top();
            if (adj[curr].size() == 0)
            {
                res.push_back(curr);
                stk.pop();
            }
            else
            {
                auto dst = adj[curr].begin();
                stk.push(*dst);
                adj[curr].erase(dst);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};