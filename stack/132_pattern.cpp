class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int>left(nums.size(),-1);
        left[0]=nums[0];
        for(int i=1; i<nums.size(); i++) {
            left[i] = min(left[i-1], nums[i]);
        }
        stack<int>stk;
        for(int i=nums.size()-1; i>=0; i--) {
            if(left[i]<nums[i]) {
                while(!stk.empty() && stk.top()<=left[i]) {
                    stk.pop();
                }
                if(!stk.empty() && stk.top() < nums[i]) return true;
                stk.push(nums[i]);
            }
        }
        return false;
    }
};