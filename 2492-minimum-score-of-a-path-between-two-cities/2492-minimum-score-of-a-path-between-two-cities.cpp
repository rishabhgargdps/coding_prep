class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>&graph, unordered_set<int>& visited, int src) {
        visited.insert(src);
        for(auto &k : graph[src]) {
            int node = k.first;
            if(visited.find(node) == visited.end()) dfs(graph, visited, node);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>>graph(n+1);
        for(auto &r : roads) {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }
        unordered_set<int>visited;
        dfs(graph, visited, 1);
        int res = INT_MAX;
        for(int i=1; i<graph.size(); i++) {
            if(visited.find(i) != visited.end()) {
                for(auto &p: graph[i]) {
                    res = min(res, p.second);
                }
            }
        }
        return res;
    }
};