class Solution {
public:
    int res = 0;
    int max = 0;
    
    void backtrack(vector<int>nums, int start, int val) {
        //Base case
        if(val == max) res++;
        //Recursive step
        for(int i=start; i<nums.size(); i++) {
            backtrack(nums, i+1, val | nums[i]);
        }
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        res = 0, max = 0;
        for(int i=0; i<nums.size(); i++) {
            max |= nums[i];
        }
        backtrack(nums, 0, 0);
        return res;
    }
};