class Solution {
public:
    long long nc2(int n) {
        return (long long)n*(n-1)/2;
    }
    vector<vector<int>>buildGraph(vector<vector<int>>& edges, int n) {
        vector<vector<int>>res(n);
        for(auto edge: edges) {
            res[edge[0]].push_back(edge[1]);
            res[edge[1]].push_back(edge[0]);
        }
        return res;
    }
    void connected_components(vector<vector<int>>& graph, int src, unordered_set<int>& s, int &res) {
        s.insert(src);
        for(auto node: graph[src]) {
            if(s.find(node) == s.end()) {
                res++;
                connected_components(graph, node, s, res);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long res = nc2(n);
        vector<vector<int>> graph = buildGraph(edges, n);
        unordered_set<int>s;
        for(int i=0; i<n; i++) {
            if(s.find(i) == s.end()) {
                int temp = 1;
                connected_components(graph, i, s, temp);
                // cout << temp << endl;
                res -= nc2(temp);
            }
        }
        return res;
    }
};