class Solution {
public:
    int jump(vector<int>& nums) {
        int count=1;
        if(nums[0] == 0 || nums.size()==1) return 0;
        int maximum = nums[0];
        int current_end = nums[0];
        for(int i=0; i<nums.size(); i++) {
            if(i==nums.size()-1) return count;
            maximum = max(maximum, i+nums[i]);
            if(i==current_end) {
                count++;
                current_end = maximum;
            }
        }
        return count;
    }
};