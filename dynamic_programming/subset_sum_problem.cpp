//Recursive solution
bool isSubsetSum(vector<int> &A, int n, int sum)
{
    // Base Case
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (sum < A[n - 1])
        return isSubsetSum(A, n - 1, sum);
    //Recursive step
    return isSubsetSum(A, n - 1, sum) || isSubsetSum(A, n - 1, sum - A[n - 1]);
}

int Solution::solve(vector<int> &A, int B)
{
    return isSubsetSum(A, A.size(), B);
}

//Dp solution
class Solution
{
public:
    int subsetSum(vector<int> &A, int B)
    {
        int m = A.size();
        int n = B;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j < A[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
            }
        }
        return dp[m][n];
    }
};