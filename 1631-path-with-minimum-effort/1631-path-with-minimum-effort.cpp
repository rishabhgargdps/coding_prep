class Solution {
public:
    struct compareVector {
        bool operator() (vector<int>& v1, vector<int>& v2) {
            return v1[0] > v2[0];
        }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>>effort(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, compareVector>pq;
        pq.push({0, 0, 0});
        vector<vector<int>>dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while(!pq.empty()) {
            vector<int> min = pq.top();
            pq.pop();
            int dist = min[0], row = min[1], col = min[2];
            if(dist > effort[row][col]) continue;
            if(row == m-1 && col == n-1) return dist;
            for(auto d : dir) {
                int newRow = row + d[0];
                int newCol = col + d[1];
                if(newRow >= 0 && newRow < m && newCol >=0 && newCol < n) {
                    int newDist = max(dist, abs(heights[newRow][newCol] - heights[row][col]));
                    if(newDist < effort[newRow][newCol]) {
                        effort[newRow][newCol] = newDist;
                        pq.push({newDist, newRow, newCol});
                    }
                }
            }
        }
        return 0;
    }
};