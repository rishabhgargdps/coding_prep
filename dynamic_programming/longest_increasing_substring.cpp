class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            int res = INT_MIN;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    res = max(res, dp[j]);
                    dp[i] = 1 + res;
                }
            }
        }
        int res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            res = max(res, dp[i]);
        }
        return res;
    }
};