class Solution
{
public:
    void backtrack(int &count, int down, int right, int m, int n)
    {
        //Base case
        if (down == m && right == n)
        {
            count++;
            return;
        }
        //Recursive step
        if (down < m)
            backtrack(count, down + 1, right, m, n);
        if (right < n)
            backtrack(count, down, right + 1, m, n);
    }

    int uniquePaths(int m, int n)
    {
        int count = 0;
        backtrack(count, 0, 0, m - 1, n - 1);
        return count;
    }
};

//dp
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int count = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};