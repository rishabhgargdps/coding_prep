class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return true;
        int maximum = -1;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            maximum = max(maximum, nums[i]);
            if (maximum > nums[i + 2])
                return false;
        }
        return true;
    }
};