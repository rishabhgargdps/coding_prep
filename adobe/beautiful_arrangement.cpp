class Solution
{
public:
    int res = 0;

    void backtrack(vector<int> &nums, int val, int n)
    {
        //Base case
        if (val > n)
        {
            res++;
            return;
        }

        //Recursive step
        for (int i = 1; i <= n; i++)
        {
            if (nums[i] == 0 && (val % i == 0 || i % val == 0))
            {
                nums[i] = val;
                backtrack(nums, val + 1, n);
                nums[i] = 0;
            }
        }
    }

    int countArrangement(int n)
    {
        vector<int> nums(n + 1);
        backtrack(nums, 1, n);
        return res;
    }
};