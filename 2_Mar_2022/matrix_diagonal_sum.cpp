class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n == 0) return 0;
        int res = 0;
        for(int i=0; i<n; i++) {
            res += mat[i][i];
            res += mat[n-1-i][i];
        }
        if(n%2) res -= mat[n/2][n/2];
        return res;
    }
};