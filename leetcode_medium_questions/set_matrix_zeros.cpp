//if matrix[i][j] >= 0, apply this method.
class Solution
{
public:
    void solve(vector<vector<int>> &matrix, int row, int col)
    {
        for (int i = col + 1; i < matrix[0].size(); i++)
        {
            if (matrix[row][i] != 0)
                matrix[row][i] = -1;
        }
        for (int i = row + 1; i < matrix.size(); i++)
        {
            if (matrix[i][col] != 0)
                matrix[i][col] = -1;
        }
        for (int i = col - 1; i >= 0; i--)
        {
            if (matrix[row][i] != 0)
                matrix[row][i] = -1;
        }
        for (int i = row - 1; i >= 0; i--)
        {
            if (matrix[i][col] != 0)
                matrix[i][col] = -1;
        }
    }

    void setZeroes(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    solve(matrix, i, j);
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }
};

//general optimized solution
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int col0 = 1; //set to true
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = matrix.size() - 1; i >= 0; i--)
        {
            for (int j = matrix[0].size() - 1; j >= 1; j--)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};