//here the elements are constrained to be positive. Hence we used sliding windows
class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int begin = 0;
        int end = 0;
        int curr_sum = 0;
        int min_length = INT_MAX;
        for (end = 0; end < nums.size(); end++)
        {
            curr_sum += nums[end];
            while (curr_sum >= k)
            {
                min_length = min(min_length, end - begin + 1);
                curr_sum -= nums[begin];
                begin++;
            }
        }
        return min_length == INT_MAX ? -1 : min_length;
    }
};