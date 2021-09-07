//wrong solution
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        //if we choose the first house and ignore the last house
        if (nums.size() < 2)
            return nums[0];
        else if (nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(nums.size() - 1);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < nums.size() - 1; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int res = dp.back();
        //if we ignore the first house and choose the last house
        dp[0] = nums[1];
        dp[1] = nums[2];
        for (int i = 3; i < nums.size(); i++)
        {
            dp[i - 1] = max(dp[i - 2], dp[i - 3] + nums[i - 1]);
        }
        res = max(res, dp.back());
        return res;
    }
};

//correct solution
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> temp(nums.begin(), nums.end() - 1);
        vector<int> dp(temp.size());
        dp[0] = temp[0];
        dp[1] = max(temp[0], temp[1]);
        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + temp[i]);
        }
        int res = dp.back();
        temp = vector<int>(nums.begin() + 1, nums.end());
        dp[0] = temp[0];
        dp[1] = max(temp[0], temp[1]);
        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + temp[i]);
        }
        res = max(res, dp.back());
        return res;
    }
};