class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>s;
        int curr_sum = 0, max_sum = 0;
        int begin = 0, end = 0;
        for(end = 0; end < nums.size(); end++) {
            curr_sum += nums[end];
            while(s.find(nums[end]) != s.end()) {
                curr_sum -= nums[begin];
                s.erase(nums[begin]);
                begin++;
            }
            max_sum = max(max_sum, curr_sum);
            s.insert(nums[end]);
        }
        return max_sum;
    }
};