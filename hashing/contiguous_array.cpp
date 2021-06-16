class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        replace(nums.begin(), nums.end(), 0, -1);
        unordered_map<int, int>m;
        int curr_sum = 0;
        int target = 0;
        int max_len = 0;
        for(int end=0; end<nums.size(); end++) {
            curr_sum+=nums[end];
            if(curr_sum == target) {
                max_len = end+1;
            }
            else if (m.find(curr_sum-target)!=m.end()) {
                max_len = max(max_len, end-m[curr_sum-target]);
            }
            else m[curr_sum] = end;
        }
        return max_len;
    }
};