class Solution
{
public:
    int largest1BorderedSquare(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2)));
        int maximum = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    dp[i + 1][j + 1][0] = 0;
                    dp[i + 1][j + 1][1] = 0;
                }
                else
                {
                    dp[i + 1][j + 1][0] = dp[i][j + 1][0] + 1;
                    dp[i + 1][j + 1][1] = dp[i + 1][j][1] + 1;
                    int len = min(dp[i + 1][j + 1][0], dp[i + 1][j + 1][1]);
                    for (int k = len; k > maximum; k--)
                    {
                        int len2 = min(dp[i + 1 - k + 1][j + 1][1], dp[i + 1][j + 1 - k + 1][0]);
                        if (len2 >= k)
                            maximum = max(maximum, k);
                    }
                }
            }
        }
        return maximum * maximum;
    }
};