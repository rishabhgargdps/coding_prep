class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        vector<int> a(n + 2);
        a[0] = 1;
        a[n + 1] = 1;
        for (int i = 0; i < n; i++)
        {
            a[i + 1] = nums[i];
        }
        for (int gap = 2; gap < n + 2; gap++)
        {
            for (int left = 0; left < n + 2 - gap; left++)
            {
                int curr = 0;
                int right = left + gap;
                for (int i = left + 1; i < right; i++)
                {
                    curr = max(curr, a[left] * a[i] * a[right] + dp[left][i] + dp[i][right]);
                    dp[left][right] = curr;
                }
            }
        }
        return dp[0][n + 1];
    }
};