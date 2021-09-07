class Solution
{
public:
    int max_sum = 0;

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool valid(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited)
    {
        if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] != 0 && !visited[row][col])
            return true;
        return false;
    }

    void dfs(vector<vector<int>> &grid, int row, int col, int sum, vector<vector<bool>> &visited)
    {
        visited[row][col] = true;
        max_sum = max(max_sum, sum);
        for (auto d : dir)
        {
            int new_row = row + d[0];
            int new_col = col + d[1];
            if (valid(grid, new_row, new_col, visited))
            {
                dfs(grid, new_row, new_col, sum + grid[new_row][new_col], visited);
            }
        }
        visited[row][col] = false;
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (valid(grid, i, j, visited))
                    dfs(grid, i, j, grid[i][j], visited);
            }
        }
        return max_sum;
    }
};