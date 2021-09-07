class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int candidate1 = INT_MIN;
        int candidate2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        for (int x : nums)
        {
            if (candidate1 != INT_MIN && x == candidate1)
            {
                count1++;
            }
            else if (candidate2 != INT_MIN && x == candidate2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                candidate1 = x;
                count1++;
            }
            else if (count2 == 0)
            {
                candidate2 = x;
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int x : nums)
        {
            if (candidate1 != INT_MIN && x == candidate1)
            {
                count1++;
            }
            else if (candidate2 != INT_MIN && x == candidate2)
            {
                count2++;
            }
        }
        vector<int> res;
        if (count1 > nums.size() / 3)
            res.push_back(candidate1);
        if (count2 > nums.size() / 3)
            res.push_back(candidate2);
        return res;
    }
};