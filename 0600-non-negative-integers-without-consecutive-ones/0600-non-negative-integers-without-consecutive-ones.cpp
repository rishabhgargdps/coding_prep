class Solution {
public:
    int helper(int n, vector<int>& dp) {
        double req_power = log2(n);
        if(req_power == (int) req_power) return dp[(int)req_power];
        int res = dp[(int)req_power];
        int low = pow(2, (int)req_power); 
        int left = n-low;
        if(left >= low/2) {
            return res + dp[(int)req_power-1]+(left-low/2+1);
        }
        else {
            return res + helper(left, dp);
        }
    }
    int findIntegers(int n) {
        if(n == 1) return 2;
        int req_power = log2(n);
        vector<int>dp(req_power+1);
        dp[0] = 0; dp[1] = 0;
        for(int i=2; i<=req_power; i++) {
            dp[i] = dp[i-1] + dp[i-2] + pow(2, i-2);
        }
        return n-helper(n, dp)+1;
    }
};