class Solution
{
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {-1, -1}, {1, 1}};

    bool valid(vector<vector<char>> &grid, int row, int col)
    {
        if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size())
            return true;
        return false;
    }

    void dfs(vector<vector<char>> &grid, int row, int col)
    {
        if (grid[row][col] == 'B')
            return;
        int flag = 0;
        for (auto d : dir)
        {
            int new_row = row + d[0];
            int new_col = col + d[1];
            if (valid(grid, new_row, new_col) && grid[new_row][new_col] == 'M')
                flag++;
        }
        if (flag == 0)
        {
            grid[row][col] = 'B';
            for (auto d : dir)
            {
                int new_row = row + d[0];
                int new_col = col + d[1];
                if (valid(grid, new_row, new_col))
                {
                    dfs(grid, new_row, new_col);
                }
            }
        }
        else
            grid[row][col] = flag + '0';
    }

    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int row = click[0], col = click[1];
        if (board[row][col] == 'M')
        {
            board[row][col] = 'X';
            return board;
        }
        dfs(board, row, col);
        return board;
    }
};