class Solution
{

public:
    int minDifference(int arr[], int m)
    {
        //we want to find the subsets having sum from 0 to sum/2 first as:
        //s1+s2 = sum
        //let s1 <= s2
        //hence 0<=s1<=sum/2
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += arr[i];
        }
        int n = sum;
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
                if (j < arr[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
        int diff = INT_MAX;
        for (int i = 0; i <= sum / 2; i++)
        {
            if (dp[m][i] == 1)
            {
                diff = min(diff, abs(sum - 2 * i));
            }
        }
        return diff;
    }
};