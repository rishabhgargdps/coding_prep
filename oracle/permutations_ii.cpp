class Solution
{
public:
    vector<vector<int>> res;

    bool canPermutate(vector<int> &nums, int curr_index, int end)
    {
        for (int i = curr_index; i < end; i++)
        {
            if (nums[i] == nums[end])
                return false;
        }
        return true;
    }

    void backtrack(vector<int> &nums, int curr_index)
    {
        //Base case
        if (curr_index == nums.size())
        {
            res.push_back(nums);
            return;
        }
        //Recursive step
        for (int i = curr_index; i < nums.size(); i++)
        {
            if (i == curr_index || canPermutate(nums, curr_index, i))
            {
                swap(nums[curr_index], nums[i]);
                backtrack(nums, curr_index + 1);
                swap(nums[curr_index], nums[i]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        backtrack(nums, 0);
        return res;
    }
};