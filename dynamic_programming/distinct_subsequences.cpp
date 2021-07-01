class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = t.length();
        int n = s.length();
        vector<vector<long long int>> dp(m + 1, vector<long long int>(n + 1));
        // dp[0][0] = s[0] == t[0] ? 1:0;
        // for(int i=1; i<=m; i++) {
        //     dp[0][i] = 0;
        // }
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == t[0])
                dp[1][i] = 1 + dp[1][i - 1];
            else
                dp[1][i] = dp[1][i - 1];
        }
        long long int mod = 1e10;
        for (int i = 2; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (t[i - 1] == s[j - 1])
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % mod;
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};