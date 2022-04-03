class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int>rows(m, 0);
        vector<int>cols(n, 0);
        for(auto index: indices) {
            rows[index[0]] += 1;
            cols[index[1]] += 1;
        }
        int res = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if((rows[i] + cols[j])%2) res++;
            }
        }
        return res;
    }
};