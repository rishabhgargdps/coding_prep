class Solution {
public:
    int mod = 1e9+7;
    int checkRecord(int n) {
        int dp[2][3] = {0};
        dp[0][0] = 1;
        for(int total=1; total<=n; total++) {
            int temp_dp[2][3] = {0};
            //if present
            for(int absent=0; absent<2; absent++) {
                for(int cons_late=0; cons_late<3; cons_late++) {
                    temp_dp[absent][0] = (temp_dp[absent][0] + dp[absent][cons_late])%mod;
                }
            }
            //if absent
            for(int cons_late=0; cons_late<3; cons_late++) {
                temp_dp[1][0] = (temp_dp[1][0] + dp[0][cons_late])%mod;
            }
            //if late
            for(int absent=0; absent<2; absent++) {
                for(int cons_late=1; cons_late<3; cons_late++) {
                    temp_dp[absent][cons_late] = (temp_dp[absent][cons_late] + dp[absent][cons_late-1])%mod;
                }
            }
            for(int i=0; i<2; i++) {
                for(int j=0; j<3; j++) {
                    dp[i][j] = temp_dp[i][j];
                }
            }
        }
        int res = 0;
        for(int i=0; i<2; i++) {
            for(int j=0; j<3; j++) {
                res = (res + dp[i][j])%mod;
            }
        }
        return res;
    }
};