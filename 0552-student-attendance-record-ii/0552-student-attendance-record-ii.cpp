class Solution {
public:
    int mod = 1e9+7;
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(3, vector<int>(4)));
        dp[0][0][0] = 1;
        for(int total=1; total<=n; total++) {
            //if present
            for(int absent=0; absent<2; absent++) {
                for(int cons_late=0; cons_late<3; cons_late++) {
                    dp[total][absent][0] = (dp[total][absent][0] + dp[total-1][absent][cons_late])%mod;
                }
            }
            //if absent
            for(int cons_late=0; cons_late<3; cons_late++) {
                dp[total][1][0] = (dp[total][1][0] + dp[total-1][0][cons_late])%mod;
            }
            //if late
            for(int absent=0; absent<2; absent++) {
                for(int cons_late=1; cons_late<3; cons_late++) {
                    dp[total][absent][cons_late] = (dp[total][absent][cons_late] + dp[total-1][absent][cons_late-1])%mod;
                }
            }
        }
        int res = 0;
        for(int i=0; i<2; i++) {
            for(int j=0; j<3; j++) {
                res = (res + dp[n][i][j])%mod;
            }
        }
        return res;
    }
};