class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>res(nums.size(),-1);
        int n = nums.size();
        for(int i=0; i<n; i++) {
            nums.push_back(nums[i]);
        }
        stack<int>stk;
        for(int i=0; i<nums.size();i++) {
            while(!stk.empty() && nums[stk.top()] < nums[i]) {
                if(res[stk.top()%n]==-1) res[stk.top()%n] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};