class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int res = 0;
        vector<vector<int>>graph(n);
        for(auto &c: connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        set<pair<int, int>>s;
        for(auto &c: connections) {
            s.insert({c[0], c[1]});
        }
        unordered_set<int>visited;
        queue<int>q;
        q.push(0);
        visited.insert(0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int neighbor: graph[node]) {
                if(visited.find(neighbor) != visited.end()) continue;
                q.push(neighbor);
                visited.insert(neighbor);
                if(s.find({neighbor, node}) == s.end()) res++;
            }
        }
        return res;
    }
};