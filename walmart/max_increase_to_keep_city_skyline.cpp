class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int breadth = grid.size();
        int width = grid[0].size();
        //max as seen from south
        vector<int> south_max(width);
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < breadth; j++)
            {
                south_max[i] = max(south_max[i], grid[j][i]);
            }
        }
        vector<int> west_max(breadth);
        for (int i = 0; i < breadth; i++)
        {
            for (int j = 0; j < width; j++)
            {
                west_max[i] = max(west_max[i], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < breadth; i++)
        {
            for (int j = 0; j < width; j++)
            {
                // cout << south_max[j] << " " << west_max[i] << endl;
                res += min(south_max[j], west_max[i]) - grid[i][j];
            }
        }
        return res;
    }
};