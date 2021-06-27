class Solution
{
public:
    struct orange
    {
        int timeframe = 0;
        int x, y;
        orange(int t, int x, int y)
        {
            timeframe = t;
            this->x = x;
            this->y = y;
        }
    };
    //we use the BFS approach since here we are traversing in BFS manner only to find the rotten oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        int res = 0;
        int v = grid.size();
        int w = grid[0].size();
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<orange> q;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push(orange(0, i, j));
                }
            }
        }
        while (!q.empty())
        {
            orange temp = q.front();
            q.pop();
            int i = temp.x;
            int j = temp.y;
            for (auto d : dir)
            {
                if (i + d.first >= 0 && i + d.first < v && j + d.second >= 0 && j + d.second < w && grid[i + d.first][j + d.second] == 1)
                {
                    grid[i + d.first][j + d.second] = 2;
                    q.push(orange(temp.timeframe + 1, i + d.first, j + d.second));
                    res = temp.timeframe + 1;
                }
            }
        }
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return res;
    }
};