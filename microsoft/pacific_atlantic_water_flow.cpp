//wrong approach
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        //pacific ocean
        for (int i = 0; i < m; i++)
        {
            pacific[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            pacific[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if ((heights[i][j] >= heights[i - 1][j] && pacific[i - 1][j] == 1) || (heights[i][j] >= heights[i][j - 1] && pacific[i][j - 1] == 1))
                {
                    pacific[i][j] = 1;
                }
            }
        }
        //altantic ocean
        for (int i = 0; i < m; i++)
        {
            atlantic[i][n - 1] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            atlantic[m - 1][i] = 1;
        }
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                if ((heights[i][j] >= heights[i + 1][j] && atlantic[i + 1][j] == 1) || (heights[i][j] >= heights[i][j + 1] && atlantic[i][j + 1] == 1))
                {
                    atlantic[i][j] = 1;
                }
            }
        }
        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1)
                    res.push_back({i, j});
            }
        }
        return res;
    }
};

//correct approach
class Solution
{
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool valid(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col)
    {
        if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && visited[row][col] == false)
            return true;
        return false;
    }

    void bfs(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited, int prev)
    {
        if (!valid(grid, visited, row, col))
            return;
        if (grid[row][col] < prev)
            return;
        visited[row][col] = true;
        for (auto d : dir)
        {
            bfs(grid, row + d[0], col + d[1], visited, grid[row][col]);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, 0));
        vector<vector<bool>> atlantic(m, vector<bool>(n, 0));
        //DFS
        for (int i = 0; i < n; i++)
        {
            bfs(heights, 0, i, pacific, INT_MIN);
            bfs(heights, m - 1, i, atlantic, INT_MIN);
        }
        for (int i = 0; i < m; i++)
        {
            bfs(heights, i, 0, pacific, INT_MIN);
            bfs(heights, i, n - 1, atlantic, INT_MIN);
        }
        //result
        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};