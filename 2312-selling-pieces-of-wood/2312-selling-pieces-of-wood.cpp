class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>>dp(m+1, vector<long long>(n+1));
        for(auto price: prices) {
            int x = price[0];
            int y = price[1];
            int sellingprice = price[2];
            dp[x][y] = sellingprice;
        }
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                //Vertical partition
                for(int k=1; k<=i; k++) {
                    dp[i][j] = max(dp[i][j], dp[i-k][j] + dp[k][j]);
                }
                //Horizontal partition
                for(int k=1; k<=j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][j-k] + dp[i][k]);
                }
            }
        }
        return dp[m][n];
    }
};