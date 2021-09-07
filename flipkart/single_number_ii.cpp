class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int first_xor = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            first_xor ^= nums[i];
        }
        int count = 0;
        while (first_xor)
        {
            if (first_xor & 1)
                break;
            count++;
            first_xor >>= 1;
        }
        int xor1 = 0, xor2 = 0;
        int bitmask = 1 << count;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & bitmask)
                xor1 ^= nums[i];
            else
                xor2 ^= nums[i];
        }
        return {xor1, xor2};
    }
};