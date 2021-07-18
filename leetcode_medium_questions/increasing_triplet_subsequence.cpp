class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        int i = INT_MAX, j = INT_MAX;
        for (int end = 0; end < nums.size(); end++)
        {
            if (nums[end] <= i)
            {
                i = nums[end];
            }
            else if (nums[end] <= j)
            {
                j = nums[end];
            }
            else
                return true;
        }
        return false;
    }
};