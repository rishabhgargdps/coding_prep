class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        vector<vector<int>> dp(s.length(), vector<int>(s.length()));
        for (int l = 0; l < s.length(); l++)
        {
            for (int x = 0, y = x + l; x < s.length() && y < s.length(); x++, y++)
            {
                if (l == 0)
                    dp[x][y] = 1;
                else if (l == 1)
                    dp[x][y] = s[x] == s[y] ? 2 : 1;
                else
                {
                    dp[x][y] = s[x] == s[y] ? 2 + dp[x + 1][y - 1] : max(dp[x + 1][y], dp[x][y - 1]);
                }
            }
        }
        return dp[0][s.length() - 1];
    }
};