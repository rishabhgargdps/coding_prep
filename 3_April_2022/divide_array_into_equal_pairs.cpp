class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        if(n%2) return false;
        unordered_map<int, int>m;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        for(auto itr = m.begin(); itr != m.end(); ++itr) {
            if(itr->second % 2) return false;;
        }
        return true;
    }
};