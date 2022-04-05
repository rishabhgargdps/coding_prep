class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>s;
        for(int num : nums) s.insert(num);
        while(s.find(original) != s.end()) {
            original *= 2;
        }
        return original;
    }
};