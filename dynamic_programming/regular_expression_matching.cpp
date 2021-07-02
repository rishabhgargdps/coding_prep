class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = p.length();
        int n = s.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            if (p[i - 1] != '*')
                dp[i][0] = 0;
            else
                dp[i][0] = dp[i - 2][0];
        }
        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                char pc = p[i - 1];
                char sc = s[j - 1];
                if (pc == '*')
                {
                    dp[i][j] = dp[i - 2][j];
                    if (p[i - 2] == sc || p[i - 2] == '.')
                    {
                        dp[i][j] = dp[i][j - 1] || dp[i][j];
                    }
                }
                else if (pc == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pc == sc)
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m][n];
    }
};