class Solution {
public:
    //use graph trimming
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>>graph(n);
        for(auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        queue<int>q;
        for(int i=0; i<n; i++) {
            if(graph[i].size() == 1) q.push(i);
        }
        queue<int>leafNodeWithCoin;
        int ans = n;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            if(coins[node] == 1) {
                leafNodeWithCoin.push(node);
                continue;
            }
            ans--;
            for(auto x: graph[node]) {
                auto itr1 = find(begin(graph[node]), end(graph[node]), x);
                auto itr2 = find(begin(graph[x]), end(graph[x]), node);
                
                graph[node].erase(itr1);
                graph[x].erase(itr2);
                
                if(graph[x].size() == 1) q.push(x);
            }
        }
        
        for(int i=0; i<2; i++) {
            int c = leafNodeWithCoin.size();
            for(int j=0; j<c; j++) {
                int node = leafNodeWithCoin.front();
                leafNodeWithCoin.pop();
                ans--;
                for(auto x: graph[node]) {
                    auto itr1 = find(begin(graph[node]), end(graph[node]), x);
                    auto itr2 = find(begin(graph[x]), end(graph[x]), node);

                    graph[node].erase(itr1);
                    graph[x].erase(itr2);

                    if(graph[x].size() == 1) leafNodeWithCoin.push(x);
                }
            }
        }
        
        if(ans == 0) return 0;
        return (ans-1)*2;
        
    }
};