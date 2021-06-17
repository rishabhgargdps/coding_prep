class Solution {
public:
    int lower_bound_(vector<int>& nums, int l, int r, int target) {
        int index = -1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(nums[mid]>=target) r = mid-1;
            else l = mid+1;
            if(nums[mid] == target) index = mid;
        }
        return index;
    }
    int upper_bound_(vector<int>& nums, int l, int r, int target) {
        int index = -1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(nums[mid] <= target) l = mid+1;
            else r = mid-1;
            if(nums[mid] == target) index = mid;
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lower_bound_(nums, 0, nums.size()-1, target), upper_bound_(nums, 0, nums.size()-1, target)};
    }
};