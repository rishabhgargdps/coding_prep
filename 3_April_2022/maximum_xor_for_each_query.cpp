class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>res;
        int p = pow(2, maximumBit) - 1;
        for(int i=1; i<nums.size(); i++) {
            nums[i] ^= nums[i-1];
        }
        for(int i=nums.size()-1; i>=0; i--) {
            res.push_back(p - nums[i]);
        }
        return res;
    }
};