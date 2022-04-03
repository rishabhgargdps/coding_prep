class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = 1;
        priority_queue<int, vector<int>, greater<int>>q;
        for(int i=0; i<nums.size(); i++) {
            q.push(nums[i]);
            if(q.size() > 2) q.pop();
        }
        while(q.size()) {
            res *= q.top()-1;
            q.pop();
        }
        return res;
    }
};