class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for(auto &v : accounts) {
            res = max(res, accumulate(v.begin(), v.end(), 0));
        }
        return res;
    }
};