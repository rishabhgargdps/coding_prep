class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        int n = numRows;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
        for (int i = 2; i < n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j])
                    res[i].push_back(dp[i][j]);
            }
        }
        return res;
    }
};