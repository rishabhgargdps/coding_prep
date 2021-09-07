//wrong solution
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int maximum = INT_MIN;
            for (int j = 1; j <= k && i - j >= 0; j++)
            {
                maximum = max(maximum, dp[i - j]); //O(n*k) optimize using sliding window and monotonic queue
            }
            dp[i] = nums[i] + maximum;
        }
        return dp[n - 1];
    }
};

class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        k++; //size of sliding window
        //monotonic queue
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < n; i++)
        {
            if (i >= k && dq[0] == i - k)
                dq.pop_front();
            dp[i] = nums[i] + dp[dq[0]];
            while (!dq.empty() && dp[dq.back()] <= dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return dp[n - 1];
    }
};