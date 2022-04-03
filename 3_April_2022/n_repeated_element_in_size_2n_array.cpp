class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // unordered_set<int>s;
        // for(int i=0; i<nums.size(); i++) {
        //     if(s.find(nums[i]) != s.end()) return nums[i];
        //     s.insert(nums[i]);
        // }
        // return -1;
        int fast = 0;
        for(int slow = 0; slow < nums.size(); slow++) {
            fast = (fast+2)%nums.size();
            if(nums[slow] == nums[fast] && slow != fast) return nums[slow];
            if(slow == nums.size()-1) {
                slow = 0;
                fast++;
            }
        }
        return -1;
    }
};