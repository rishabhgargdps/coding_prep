class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //sliding window approach
        int begin = 0;
        int end = 0;
        while(end<nums.size()) {
            if(nums[end]==0) k--;
            if(k<0) {
                if(nums[begin]==0) k++;
                begin++;
            }
            end++;
        }
        return end-begin;
    }
};