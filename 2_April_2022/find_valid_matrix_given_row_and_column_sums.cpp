class Solution {
public:
    
    int minValueIndex(unordered_set<int>& s, vector<int>& v) {
        int minimum = INT_MAX;
        int index = 0;
        for(int i=0; i<v.size(); i++) {
            if(minimum > v[i] && s.find(i) == s.end()) {
                minimum = v[i];
                index = i;
            }
        }
        return index;
    }
    
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>>res(m, vector<int>(n, 0));
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>row;
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>col;
        // for(int i=0; i<rowSum.size(); i++) {
        //     row.push({rowSum[i], i});
        //     col.push({colSum[i], i});
        // }
        // while(row.size()) {
        //     while(row.size()) {
        //         if(row.top()[0] == 0) row.pop();
        //         else break;
        //     }
        //     while(col.size()) {
        //         if(col.top()[0] == 0) col.pop();
        //         else break;
        //     }
        //     int i = row.top()[1];
        //     int j = col.top()[1];
        //     if(row.top()[0] >= col.top()[0]) {
        //         res[i][j] = col.top()[0];
        //         col.pop();
        //         int diff = row.top()[0] - col.top()[0];
        //         row.pop();
        //         if(row.top()[0] != col.top()[0]) row.push({i, diff});
        //     }
        //     else {
        //         res[i][j] = row.top()[0];
        //         row.pop();
        //         int diff = col.top()[0] - row.top()[0];
        //         col.pop();
        //         if(row.top()[0] != col.top()[0]) col.push({j, diff});
        //     }
        // }
        unordered_set<int>row, col;
        while(row.size() != m && col.size() != n) {
            int ri = minValueIndex(row, rowSum);
            int ci = minValueIndex(col, colSum);
            if(rowSum[ri] < colSum[ci]) {
                res[ri][ci] = rowSum[ri];
                colSum[ci] -= rowSum[ri];
                row.insert(ri);
            }
            else {
                res[ri][ci] = colSum[ci];
                rowSum[ri] -= colSum[ci];
                col.insert(ci);
            }
        }
        return res;
    }
};