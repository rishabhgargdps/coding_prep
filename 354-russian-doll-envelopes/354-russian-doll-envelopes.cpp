class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int>lis;
        for(auto &e : envelopes) {
            int height = e[1];
            int index = lower_bound(lis.begin(), lis.end(), height) - lis.begin();
            if(index >= lis.size()) lis.push_back(height);
            else lis[index] = height;
        }
        return lis.size();
    }
};