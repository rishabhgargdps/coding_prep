class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n));
        int left = 0, right = n - 1, top = 0, bottom = n - 1, count = 1;
        while (count <= n * n)
        {
            for (int i = left; i <= right; i++)
            {
                res[top][i] = count;
                count++;
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                res[i][right] = count;
                count++;
            }
            right--;
            for (int i = right; i >= left; i--)
            {
                res[bottom][i] = count;
                count++;
            }
            bottom--;
            for (int i = bottom; i >= top; i--)
            {
                res[i][left] = count;
                count++;
            }
            left++;
        }
        return res;
    }
};