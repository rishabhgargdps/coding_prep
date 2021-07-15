class Solution
{
public:
    int fact(int n)
    {
        if (n == 1)
            return n;
        return fact(n - 1) * n;
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back(nums);
        int n = nums.size();
        for (int i = 1; i < fact(n); i++)
        {
            next_permutation(nums.begin(), nums.end());
            res.push_back(nums);
        }
        return res;
    }
};