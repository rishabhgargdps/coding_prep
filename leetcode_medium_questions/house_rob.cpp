class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int excl = 0, excl_new;
        int incl = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            excl_new = max(incl, excl);
            incl = excl + nums[i];
            excl = excl_new;
        }
        return max(incl, excl);
    }
};