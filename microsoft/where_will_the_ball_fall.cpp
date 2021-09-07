class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        vector<int> res(grid[0].size());
        for (int col = 0; col < grid[0].size(); col++)
        {
            int temp_col = col;
            bool flag = true;
            for (int row = 0; row < grid.size(); row++)
            {
                if ((temp_col + 1 < grid[0].size() && grid[row][temp_col] == 1 && grid[row][temp_col + 1] == -1) || (temp_col + 1 == grid[0].size() && grid[row][temp_col] == 1))
                {
                    flag = false;
                    break;
                }
                else if ((temp_col - 1 >= 0 && grid[row][temp_col] == -1 && grid[row][temp_col - 1] == 1) || (temp_col - 1 < 0 && grid[row][temp_col] == -1))
                {
                    flag = false;
                    break;
                }
                temp_col += grid[row][temp_col];
            }
            res[col] = flag ? temp_col : -1;
            flag = true;
        }
        return res;
    }
};