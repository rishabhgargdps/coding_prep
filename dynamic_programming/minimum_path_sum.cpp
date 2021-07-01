class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - 1 >= 0 && j - 1 >= 0)
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
                else if (i - 1 >= 0)
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                else if (j - 1 >= 0)
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};