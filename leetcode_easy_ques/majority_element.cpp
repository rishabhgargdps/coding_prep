class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 1;
        int curr_ele = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == curr_ele)
                count++;
            else
            {
                count--;
                if (count == 0)
                {
                    curr_ele = nums[i];
                    count++;
                }
            }
        }
        return curr_ele;
    }
};