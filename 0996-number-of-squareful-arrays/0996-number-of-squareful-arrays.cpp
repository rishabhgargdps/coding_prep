class Solution {
public:
    int res = 0;
    bool shouldSwap(vector<int>& nums, int start, int curr) {
        for(int i=start; i<curr; i++) {
            if(nums[i] == nums[curr]) return false;
        }
        return true;
    }
    void solve(vector<int>& nums, int left) {
        if(left == nums.size()) {
            for(int i=1; i<nums.size(); i++) {
                int temp = sqrt(nums[i-1] + nums[i]);
                if(temp*temp != nums[i-1] + nums[i]) return;
            }
            res++;
            return;
        }
        for(int i=left; i<nums.size(); i++) {
            if(!shouldSwap(nums, left, i)) continue;
            for(int j=1; j<left; j++) {
                int temp = sqrt(nums[j-1] + nums[j]);
                if(temp*temp != nums[j-1] + nums[j]) return;
            }
            swap(nums[left], nums[i]);
            solve(nums, left+1);
            swap(nums[left], nums[i]);
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        solve(nums, 0);
        return res;
    }
};