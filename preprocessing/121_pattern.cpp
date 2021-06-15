class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int>left(nums.size(),-1);
        vector<int>right(nums.size(),-1);
        int min_value = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            min_value = min(min_value, nums[i]);
            left[i] = min_value;
        }
        min_value = INT_MAX;
        for(int i=nums.size()-1; i>=0; i--) {
            min_value = min(min_value, nums[i]);
            right[i] = min_value;
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=left[i] && nums[i]!=right[i]) {
                return true;
            }
        }
        return false;
    }
};