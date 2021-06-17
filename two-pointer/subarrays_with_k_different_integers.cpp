class Solution
{
public:
    int ans_till_k(vector<int>& nums, int k)
    {
        int begin = 0;
        int end = 0;
        int diff = 0;
        int total = 0;
        vector<int> count(20002, 0);
        for (end = 0; end < nums.size(); end++)
        {
            if (count[nums[end]] == 0)
            {
                diff++;
                count[nums[end]]++;
            }
            else
            {
                count[nums[end]]++;
            }
            if (diff <= k)
            {
                total += (end - begin + 1);
            }
            else
            {
                while (begin < nums.size() && begin <= end && diff > k)
                {
                    count[nums[begin]]--;
                    if (count[nums[begin]] == 0)
                    {
                        diff--;
                    }
                    begin++;
                }
                total += (end - begin + 1);
            }
        }
        return total;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return ans_till_k(nums, k) - ans_till_k(nums, k-1);
    }
};