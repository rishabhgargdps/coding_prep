class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,0);
        dp[0] = 0;
        for(int i=1; i<=n; i++) {
            int min_value = i;
            for(int y=1; y*y<=i; y++) {
                min_value = min(min_value, 1+dp[i-y*y]);
            }
            dp[i] = min_value;
        }
        return dp[n];
    }
};