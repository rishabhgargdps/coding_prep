class Solution {
public:
    int mod = 1e9+7;
    int solve(int n, int total, int absent, int cons_late, vector<vector<vector<int>>>& dp) {
        if(absent >= 2 || cons_late >= 3) return 0;
        if(total == n) return 1;
        if(dp[total][absent][cons_late] != -1) return dp[total][absent][cons_late];
        dp[total][absent][cons_late] = ((long long)solve(n, total+1, absent, 0, dp)%mod + (long long)solve(n, total+1, absent+1, 0, dp)%mod + (long long)solve(n, total+1, absent, cons_late+1, dp)%mod)%mod;
        return dp[total][absent][cons_late]%mod;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(n, 0, 0, 0, dp);
    }
};