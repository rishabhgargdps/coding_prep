class Solution {
public:
    int solve(int a, int b) {
        if(b == 0) return a;
        return solve(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        int minimum = INT_MAX, maximum = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            minimum = min(minimum, nums[i]);
            maximum = max(maximum, nums[i]);
        }
        return solve(maximum, minimum);
    }
};