class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> res(nums.size());
        int j = (int)nums.size() - 1;
        for (int i = 1; i < res.size(); i += 2)
        {
            res[i] = nums[j];
            j--;
        }
        for (int i = 0; i < res.size(); i += 2)
        {
            res[i] = nums[j];
            j--;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = res[i];
        }
        return;
    }
};