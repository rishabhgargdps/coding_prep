class Solution
{
public:
    int max_area = 0;
    int curr_area = 1;

    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

    bool valid(vector<vector<int>> &grid, int row, int col)
    {
        if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1)
            return true;
        return false;
    }

    void bfs(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited)
    {
        //Processing
        visited[row][col] = true;
        max_area = max(max_area, curr_area);
        //Recursive step
        for (auto d : dir)
        {
            int new_row = row + d[0];
            int new_col = col + d[1];
            if (valid(grid, new_row, new_col) && !visited[new_row][new_col])
            {
                curr_area++;
                bfs(grid, new_row, new_col, visited);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (valid(grid, i, j))
                {
                    curr_area = 1;
                    bfs(grid, i, j, visited);
                }
            }
        }
        return max_area;
    }
};