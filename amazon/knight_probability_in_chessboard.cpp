class Solution
{
public:
    double sum = 0.0;

    vector<vector<int>> dir = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, 1}, {2, -1}, {-2, -1}, {-2, 1}};

    bool valid(int n, int row, int col)
    {
        if (row >= 0 && row < n && col >= 0 && col < n)
            return true;
        return false;
    }

    void dfs(int n, int row, int col, double prob, int k)
    {
        //Base case
        if (k == 0)
        {
            sum += prob;
            return;
        }
        //Recursive step
        for (auto d : dir)
        {
            int new_row = row + d[0];
            int new_col = col + d[1];
            if (valid(n, new_row, new_col))
                dfs(n, new_row, new_col, 1.0 * prob / 8, k - 1);
        }
    }

    double knightProbability(int n, int k, int row, int column)
    {
        dfs(n, row, column, 1.0, k);
        return sum;
    }
};