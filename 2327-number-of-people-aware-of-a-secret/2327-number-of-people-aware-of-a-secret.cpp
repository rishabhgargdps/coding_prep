class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>dp(n+1);
        long long noOfPeopleSharingSecret = 0;
        int mod = 1e9+7;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            if(i >= forget) noOfPeopleSharingSecret = (noOfPeopleSharingSecret - dp[i-forget] + mod)%mod;
            if(i >= delay) noOfPeopleSharingSecret = (noOfPeopleSharingSecret + dp[i-delay])%mod;
            dp[i] = noOfPeopleSharingSecret;
        }
        int res = 0;
        for(int i=n-forget+1; i<=n; i++) {
            res = (res + dp[i])%mod;
        }
        return res;
    }
};