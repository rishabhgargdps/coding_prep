class Solution
{
public:
    void BFS(vector<vector<char>> &grid, int i, int j)
    {
        int v = grid.size();
        int w = grid[0].size();
        if (i < 0 || i >= v || j < 0 || j >= w || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (auto d : dir)
        {
            BFS(grid, i + d.first, j + d.second);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int v = grid.size();
        int w = grid[0].size();
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    BFS(grid, i, j);
                }
            }
        }
        return count;
    }
};