class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        //we need prefix sum array and queue because the elements are not constrained to be positive. Else sliding windows can be used.
        vector<long> prefix_sum(nums.size() + 1, 0);
        deque<int> q;
        int min_length = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        //the deque will always keep the prefix sums in increasing order
        for (int i = 0; i < nums.size() + 1; i++)
        {
            while (!q.empty() && prefix_sum[i] - prefix_sum[q.front()] >= k)
            {
                min_length = min(min_length, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && prefix_sum[i] - prefix_sum[q.back()] <= 0)
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        return min_length == INT_MAX ? -1 : min_length;
    }
};