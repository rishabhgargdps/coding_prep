class Solution {
public:
    int depth(vector<vector<int>>& graph, int src, int curr_depth, unordered_set<int>& visited) {
        visited.insert(src);
        int res = 0;
        for(auto node: graph[src]) {
            if(visited.find(node) == visited.end()) res += depth(graph, node, curr_depth+1, visited);
        }
        res += curr_depth;
        return res;
    }
    int solve(vector<vector<int>>& graph, int src, unordered_set<int>& visited, vector<int>& dp) {
        visited.insert(src);
        int res = 1;
        for(auto node: graph[src]) {
            if(visited.find(node) == visited.end()) {
                res += solve(graph, node, visited, dp);
            }
        }
        return dp[src] = res;
    }
    void dfs(vector<vector<int>>& graph, int src, unordered_set<int>& visited, vector<int>& res, vector<int>& dp) {
        visited.insert(src);
        for(auto node: graph[src]) {
            if(visited.find(node) == visited.end()) {
                res[node] = res[src] - dp[node] + (graph.size() - dp[node]);
                dfs(graph, node, visited, res, dp);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>dp(n); //to find number of nodes in subtree
        vector<vector<int>>graph(n);
        for(auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        unordered_set<int>visited;
        solve(graph, 0, visited, dp);
        unordered_set<int>temp;
        swap(visited, temp);
        vector<int>res(n);
        res[0] = depth(graph, 0, 0, visited);
        unordered_set<int>temp2;
        swap(visited, temp2);
        dfs(graph, 0, visited, res, dp);
        return res;
    }
};