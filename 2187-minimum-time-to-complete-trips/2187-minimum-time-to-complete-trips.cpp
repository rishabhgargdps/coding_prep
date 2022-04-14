class Solution {
public:
    long long binary_search(vector<int>nums, long long left, long long right, int target) {
        //Base case
        if(left >= right) return left;
        //Recursive step
        long long mid = left + (right-left)/2;
        long long ans = 0ll;
        for(int i=0; i < nums.size(); i++) {
            ans += mid / nums[i];
        }
        if(ans < target) return binary_search(nums, mid+1, right, target);
        return binary_search(nums, left, mid, target);
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        return binary_search(time, 1ll, 1e14, totalTrips);
    }
};