class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int res = INT_MAX;
        int m = triangle.size();
        for (int i = 1; i < m; i++)
        {
            int n = triangle[i].size();
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                {
                    triangle[i][j] += triangle[i - 1][j];
                    continue;
                }
                if (j == n - 1)
                {
                    triangle[i][j] += triangle[i - 1][n - 2];
                    continue;
                }
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
        for (int i = 0; i < triangle[m - 1].size(); i++)
        {
            res = min(res, triangle[m - 1][i]);
        }
        return res;
    }
};