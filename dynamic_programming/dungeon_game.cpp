class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[m - 1][n - 1] = min(0, dungeon[m - 1][n - 1]);
        for (int i = m - 2; i >= 0; i--)
        {
            dp[i][n - 1] = min(0, dp[i + 1][n - 1] + dungeon[i][n - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            dp[m - 1][i] = min(0, dp[m - 1][i + 1] + dungeon[m - 1][i]);
        }
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                dp[i][j] = min(0, max(dp[i + 1][j], dp[i][j + 1]) + dungeon[i][j]);
            }
        }
        return 1 + abs(dp[0][0]);
    }
};