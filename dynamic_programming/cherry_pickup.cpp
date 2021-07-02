class Solution
{
public:
    bool inRange(int val, int limit)
    {
        if (0 <= val && val < limit)
            return true;
        return false;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
        vector<int> dir = {-1, 0, 1};
        int col1 = 0, col2 = col - 1;
        dp[0][col1][col2] = grid[0][col1] + grid[0][col2];
        int maximum = dp[0][col1][col2];
        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    int prev = dp[i - 1][j][k];
                    if (prev >= 0)
                    {
                        for (int d1 : dir)
                        {
                            col1 = j + d1;
                            for (int d2 : dir)
                            {
                                col2 = k + d2;
                                if (inRange(col1, col) && inRange(col2, col))
                                {
                                    dp[i][col1][col2] = max(dp[i][col1][col2], prev + (col1 == col2 ? grid[i][col1] : grid[i][col1] + grid[i][col2]));
                                    maximum = max(maximum, dp[i][col1][col2]);
                                }
                            }
                        }
                    }
                }
            }
        }
        return maximum;
    }
};