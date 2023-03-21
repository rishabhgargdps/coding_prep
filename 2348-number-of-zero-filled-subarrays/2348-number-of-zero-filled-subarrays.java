class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long res = 0, curr_count = 0;
        for(int i=0; i<nums.length; i++) {
            if(nums[i] != 0) {
                res += curr_count*(curr_count+1)/2;
                curr_count = 0;
            }
            else curr_count++;
        }
        if(nums[nums.length-1] == 0) res += curr_count*(curr_count+1)/2;
        return res;
    }
}