class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() - 1 && nums[i] != nums[i + 1])
        {
            i++;
        }
        return nums[i];
    }
};

//for linear runtime complexity in a mutable array and positive elements
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int i = 0;
        while (true)
        {
            i = abs(nums[i]);
            if (nums[i] < 0)
                break;
            nums[i] *= -1;
        }
        return i;
    }
};

