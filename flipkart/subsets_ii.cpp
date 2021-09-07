class Solution
{
public:
    vector<vector<int>> res;

    void subset(vector<int> &nums, int index, vector<int> curr)
    {
        res.push_back(curr);
        //Recursive step
        for (int i = index; i < nums.size(); i++)
        {
            if (i != index && nums[i] == nums[i - 1])
                continue;
            curr.push_back(nums[i]);
            subset(nums, i + 1, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        subset(nums, 0, {});
        return res;
    }
};

//wrong solution
class Solution
{
public:
    vector<vector<int>> res;

    void subset(vector<int> &nums, int index, vector<int> curr)
    {
        //Base case
        if (index == nums.size())
        {
            res.push_back(curr);
            return;
        }
        //Recursive step
        //exclude
        subset(nums, index + 1, curr);
        //include
        curr.push_back(nums[index]);
        subset(nums, index + 1, curr);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        subset(nums, 0, {});
        sort(res.begin(), res.end());
        for (int i = 1; i < res.size(); i++)
        {
            if (res[i] == res[i - 1])
            {
                res.erase(res.begin() + i - 1);
            }
        }
        return res;
    }
};