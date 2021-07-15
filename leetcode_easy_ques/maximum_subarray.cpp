class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr_sum = 0;
        int max_sum = INT_MIN;
        for (int end = 0; end < nums.size(); end++)
        {
            curr_sum += nums[end];
            if (nums[end] > curr_sum)
                curr_sum = nums[end];
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};