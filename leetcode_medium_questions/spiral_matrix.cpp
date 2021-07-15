class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int beginrow = 0;
        int begincol = 0;
        int endrow = matrix.size() - 1;
        int endcol = matrix[0].size() - 1;
        vector<int> res;
        while (beginrow <= endrow && begincol <= endcol)
        {
            for (int i = begincol; i <= endcol; i++)
            {
                res.push_back(matrix[beginrow][i]);
            }
            beginrow++;
            for (int i = beginrow; i <= endrow; i++)
            {
                res.push_back(matrix[i][endcol]);
            }
            endcol--;
            if (beginrow <= endrow)
            {
                for (int i = endcol; i >= begincol; i--)
                {
                    res.push_back(matrix[endrow][i]);
                }
                endrow--;
            }
            if (begincol <= endcol)
            {
                for (int i = endrow; i >= beginrow; i--)
                {
                    res.push_back(matrix[i][begincol]);
                }
                begincol++;
            }
        }
        return res;
    }
};