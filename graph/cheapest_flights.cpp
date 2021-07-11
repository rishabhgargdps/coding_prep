//implementation of basic Dijkstra algorithm
class Solution
{
public:
    vector<vector<int>> buildGraph(vector<vector<int>> &flights, int n)
    {
        int v = n;
        vector<vector<int>> graph(v, vector<int>(v, 0));
        for (auto flight : flights)
        {
            graph[flight[0]][flight[1]] = flight[2];
        }
        return graph;
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        int v = n;
        vector<int> dist(v, INT_MAX);
        dist[src] = 0;
        vector<bool> finalised(v, false);
        vector<vector<int>> graph = buildGraph(flights, n);
        for (int count = 0; count < v - 1; count++)
        {
            int u = -1;
            for (int i = 0; i < v; i++)
            { //this loop can be replaced by priority queue (to pick the minimum key from the vector)
                if (!finalised[i] && (u == -1 || dist[i] < dist[u]))
                    u = i;
            }
            finalised[u] = true;
            for (int i = 0; i < v; i++)
            {
                if (graph[u][i] != 0 && finalised[i] == false)
                {
                    dist[i] = min(dist[i], dist[u] + graph[u][i]);
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};


class Solution {
public:
    pair<int, int> dfs(vector<vector<int>>& graph, int s, int dest, vector<pair<int, int>>& distance) {
        //Base cases
        if(s == dest) return {0,0};
        //Recursive step
        for(auto x : graph[s]) {
            pair<int, int> temp = dfs(graph, x.first, distance);
            if(temp.second != INT_MAX) return {temp.first + x.second, temp.second++};
            else return {0, INT_MAX};
        }
        return {0, INT_MAX};
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //we can use simple dfs method
        //build the graph here
        vector<vector<pair<int, int>>>& graph(n);
        for(auto itr : flights) {
            graph[itr[0]].push_back({itr[1], itr[2]});
        }
        vector<pair<int, int>distance(n);
        dfs(graph, 0, distance);
        int min_distance = INT_MAX;
        for(int i = 1; i<distance.size(); i++) {
            if(distance[i].second <= k) {
                min_distance = min(min_distance, distance[i].first);
            }
        }
        return min_distance;
    }
};

class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //we can use simple dfs method
        //build the graph here
        vector<vector<pair<int, int>>>graph(n);
        for(auto itr : flights) {
            graph[itr[0]].push_back({itr[1], itr[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, src, k+1});
        while(!pq.empty()) {
            int curr_node = pq.top()[1];
            int cost = pq.top()[0];
            int e = pq.top()[2];
            pq.pop();
            if(curr_node == dst) return cost;
            if(e > 0) {
                for(auto x : graph[curr_node]) {
                    pq.push({cost + x.second, x.first, e-1});
                }
            }
        }
        return -1;
    }
};