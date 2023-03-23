class Solution {
public:
    void dfs(vector<vector<int>>& graph, unordered_set<int>& visited, int src) {
        visited.insert(src);
        for(int node: graph[src]) {
            if(visited.find(node) == visited.end()) dfs(graph, visited, node);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>graph(n);
        for(auto &c: connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        unordered_set<int>visited;
        int count = 0;
        for(int i=0; i<n; i++) {
            if(visited.find(i) == visited.end()) {
                dfs(graph, visited, i);
                count++;
            }
        }
        if(count == 1) return 0;
        if(count > 1) {
            if(n > connections.size()+1) return -1;
        }
        return count-1;
    }
};