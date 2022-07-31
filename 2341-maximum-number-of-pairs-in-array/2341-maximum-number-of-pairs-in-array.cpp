class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int>m;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        vector<int>res = {0,0};
        for(auto itr=m.begin(); itr!=m.end(); ++itr) {
            res[0] += itr->second/2;
            res[1] += itr->second%2;
        }
        return res;
    }
};