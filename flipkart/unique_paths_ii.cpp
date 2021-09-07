class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = !obstacleGrid[0][0];
        for (int i = 1; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i - 1][0];
        }
        for (int i = 1; i < n; i++)
        {
            if (obstacleGrid[0][i] == 0)
                dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

//TLE solution recursion based
class Solution
{
public:
    int res = 0;
    bool valid(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited)
    {
        if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && !visited[row][col] && grid[row][col] == 0)
            return true;
        return false;
    }
    void dfs(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited)
    {
        //Base case
        if (row == grid.size() - 1 && col == grid[0].size() - 1)
        {
            res++;
            return;
        }
        //Recursive step
        visited[row][col] = true;
        if (valid(grid, row + 1, col, visited))
        {
            // cout << row << " " << col << endl;
            dfs(grid, row + 1, col, visited);
        }
        if (valid(grid, row, col + 1, visited))
        {
            // cout << row << " " << col << endl;
            dfs(grid, row, col + 1, visited);
        }
        visited[row][col] = false;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        res = 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        if (obstacleGrid[0][0] == 0)
            dfs(obstacleGrid, 0, 0, visited);
        return res;
    }
};