class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res = {0,0};
        unordered_map<int, int>m;
        for(int i=0; i<nums.size(); i++) {
            if(m.find(target-nums[i])!=m.end()) {
                res[0] = i;
                res[1] = m.find(target-nums[i])->second;
            }
            else m[nums[i]]=i;
        }
        return res;
    }
};