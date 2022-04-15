class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int>res;
        int n = security.size();
        vector<int>inc(n);
        vector<int>dec(n);
        for(int i=1; i<n; i++) {
            if(security[i] <= security[i-1]) dec[i] = dec[i-1] + 1;
        }
        for(int i = n-2; i>=0; i--) {
            if(security[i] <= security[i+1]) inc[i] = inc[i+1] + 1;
        }
        for(int i=0; i<security.size(); i++) {
            if(inc[i] >= time && dec[i] >= time) res.push_back(i);
        }
        return res;
    }
};